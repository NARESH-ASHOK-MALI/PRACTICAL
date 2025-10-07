import java.io.IOException;
import java.net.DatagramPacket;
import java.net.DatagramSocket;
import java.net.InetAddress;
import java.util.Scanner;
import java.util.Timer;
import java.util.TimerTask;
import java.util.concurrent.locks.ReentrantLock;

public class Sender {
    // Configuration
    private static final int PACKET_SIZE = 1; // Size of data in each packet (1 char)
    private static final int TIMEOUT = 2000; // Timeout in milliseconds (2 seconds)

    // State
    private DatagramSocket socket;
    private InetAddress receiverAddress;
    private int receiverPort;
    private String protocol;
    private int windowSize;
    private int seqNumBits;
    private int maxSeqNum;

    // Sliding Window variables
    private ReentrantLock lock = new ReentrantLock();
    private String[] messageChunks;
    private int base = 0;
    private int nextSeqNum = 0;
    private Timer timer;
    private volatile boolean ackThreadRunning = true;
    private boolean[] ackReceived; // For Selective Repeat

    public Sender(String receiverHost, int receiverPort, String protocol, int windowSize, int seqNumBits) throws Exception {
        this.receiverAddress = InetAddress.getByName(receiverHost);
        this.receiverPort = receiverPort;
        this.socket = new DatagramSocket();
        this.protocol = protocol.toUpperCase();
        this.windowSize = windowSize;
        this.seqNumBits = seqNumBits;
        this.maxSeqNum = (int) Math.pow(2, seqNumBits);

        if (!this.protocol.equals("GBN") && !this.protocol.equals("SR")) {
            throw new IllegalArgumentException("Protocol must be GBN (Go-Back-N) or SR (Selective Repeat)");
        }
        System.out.println("Sender configured for " + this.protocol);
    }

    public void start() throws IOException {
        Scanner scanner = new Scanner(System.in);
        System.out.print("Enter the message to send: ");
        String message = scanner.nextLine();

        // Split message into chunks
        messageChunks = message.split("(?<=\\G.{" + PACKET_SIZE + "})");
        ackReceived = new boolean[messageChunks.length];

        // Start a thread to listen for ACKs
        Thread ackListener = new Thread(this::listenForAcks);
        ackListener.start();

        // Main sending loop
        while (base < messageChunks.length) {
            lock.lock();
            try {
                // Send all packets within the window
                while (nextSeqNum < base + windowSize && nextSeqNum < messageChunks.length) {
                    sendDataPacket(nextSeqNum);
                    nextSeqNum++;
                }
            } finally {
                lock.unlock();
            }

            // Wait for ACKs or timeout
            try {
                Thread.sleep(100); // Small sleep to prevent busy-waiting
            } catch (InterruptedException e) {
                Thread.currentThread().interrupt();
            }
        }

        // Cleanup
        System.out.println("Message sent successfully.");
        ackThreadRunning = false;
        timer.cancel();
        socket.close();
        scanner.close();
    }

    private void sendDataPacket(int seqNum) throws IOException {
        String data = messageChunks[seqNum];
        Packet packet = new Packet(Packet.TYPE_DATA, seqNum % maxSeqNum, data);
        byte[] sendData = packet.toBytes();

        // *** SIMULATE PACKET LOSS HERE ***
        if (seqNum == 2) { // Example: Drop packet with sequence number 2
            System.out.println("SIMULATING PACKET LOSS: Not sending packet with seqNum " + seqNum);
            // Don't start timer for this packet in GBN
             if (protocol.equals("GBN") && seqNum == base) {
                 // do nothing, the next send will trigger the timer
             } else {
                 startTimer();
             }
            return;
        }

        DatagramPacket sendPacket = new DatagramPacket(sendData, sendData.length, receiverAddress, receiverPort);
        socket.send(sendPacket);
        System.out.println("Sent: Packet seqNum=" + seqNum + " (mod " + maxSeqNum + " -> " + (seqNum % maxSeqNum) + ")");

        // Start the timer only for the oldest un-ACK'd packet in GBN
        if (protocol.equals("GBN") && base == seqNum) {
            startTimer();
        } else if (protocol.equals("SR")) {
             // SR would need a timer per packet. This is a simplified demo.
             // For simplicity, we'll use a single timer like GBN, which is less efficient for SR.
             startTimer();
        }
    }

    private void listenForAcks() {
        byte[] receiveData = new byte[1024];
        while (ackThreadRunning) {
            try {
                DatagramPacket receivePacket = new DatagramPacket(receiveData, receiveData.length);
                socket.receive(receivePacket);
                Packet ack = Packet.fromBytes(receivePacket.getData());

                if (ack.getType() == Packet.TYPE_ACK) {
                    System.out.println("Received: ACK for seqNum=" + ack.getSeqNum());
                    handleAck(ack.getSeqNum());
                }
            } catch (Exception e) {
                if (ackThreadRunning) {
                    System.err.println("Error receiving ACK: " + e.getMessage());
                }
            }
        }
    }

    private void handleAck(int ackNum) {
        lock.lock();
        try {
            if (protocol.equals("GBN")) {
                // In GBN, an ACK for N acknowledges all packets up to N.
                // We use base <= ackNum logic to handle modulo arithmetic correctly
                // A better approach for modulo would be more complex, this is simplified.
                base = Math.max(base, ackNum + 1);
                if (base == nextSeqNum) {
                    System.out.println("All sent packets ACK'd. Stopping timer.");
                    stopTimer();
                } else {
                    System.out.println("ACK received, restarting timer for new base.");
                    startTimer(); // Restart timer for the new base
                }
            } else if (protocol.equals("SR")) {
                // In SR, an ACK marks a specific packet.
                // This logic is simplified and does not perfectly handle modulo for ackNum
                if(ackNum >= base && ackNum < base + windowSize){
                    ackReceived[ackNum] = true;
                    // Slide window forward if the base packet has been ACK'd
                    while (base < messageChunks.length && ackReceived[base]) {
                        base++;
                    }
                    System.out.println("Window base is now " + base);
                    stopTimer(); // Simplified: stop timer on any ACK
                    startTimer();
                }
            }
        } finally {
            lock.unlock();
        }
    }

    private void handleTimeout() {
        lock.lock();
        try {
            System.out.println("TIMEOUT event!");
            if (protocol.equals("GBN")) {
                System.out.println("Go-Back-N: Resending all packets from base " + base);
                for (int i = base; i < nextSeqNum; i++) {
                    // Resend without simulating loss this time
                    String data = messageChunks[i];
                    Packet packet = new Packet(Packet.TYPE_DATA, i % maxSeqNum, data);
                    byte[] sendData = packet.toBytes();
                    DatagramPacket sendPacket = new DatagramPacket(sendData, sendData.length, receiverAddress, receiverPort);
                    socket.send(sendPacket);
                    System.out.println("Re-Sent: Packet seqNum=" + i);
                }
            } else if (protocol.equals("SR")) {
                // In SR, resend only the un-ACK'd packets
                 System.out.println("Selective Repeat: Checking for un-ACK'd packets to resend.");
                 for (int i = base; i < nextSeqNum; i++) {
                     if(!ackReceived[i]) {
                        System.out.println("Resending un-ACK'd packet: " + i);
                        String data = messageChunks[i];
                        Packet packet = new Packet(Packet.TYPE_DATA, i % maxSeqNum, data);
                        byte[] sendData = packet.toBytes();
                        DatagramPacket sendPacket = new DatagramPacket(sendData, sendData.length, receiverAddress, receiverPort);
                        socket.send(sendPacket);
                     }
                 }
            }
            startTimer(); // Restart the timer after resending
        } catch (IOException e) {
            System.err.println("Error during retransmission: " + e.getMessage());
        } finally {
            lock.unlock();
        }
    }

    private void startTimer() {
        stopTimer();
        timer = new Timer(true); // Use a daemon thread
        timer.schedule(new TimerTask() {
            @Override
            public void run() {
                handleTimeout();
            }
        }, TIMEOUT);
    }

    private void stopTimer() {
        if (timer != null) {
            timer.cancel();
        }
    }

    public static void main(String[] args) {
        if (args.length != 5) {
            System.out.println("Usage: java Sender <receiver_host> <receiver_port> <GBN|SR> <window_size> <seq_num_bits>");
            return;
        }
        try {
            String receiverHost = args[0];
            int receiverPort = Integer.parseInt(args[1]);
            String protocol = args[2];
            int windowSize = Integer.parseInt(args[3]);
            int seqNumBits = Integer.parseInt(args[4]);

            Sender sender = new Sender(receiverHost, receiverPort, protocol, windowSize, seqNumBits);
            sender.start();
        } catch (Exception e) {
            e.printStackTrace();
        }
    }
}
