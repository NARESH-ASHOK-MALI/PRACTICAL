import java.io.IOException;
import java.net.DatagramPacket;
import java.net.DatagramSocket;
import java.net.InetAddress;
import java.util.HashMap;
import java.util.Map;

public class Receiver {
    private DatagramSocket socket;
    private int port;
    private String protocol;
    private int seqNumBits;
    private int maxSeqNum;
    private volatile boolean running = true;

    // State
    private int expectedSeqNum = 0;
    private Map<Integer, Packet> buffer; // For Selective Repeat
    private StringBuilder receivedMessage = new StringBuilder();

    public Receiver(int port, String protocol, int seqNumBits) throws Exception {
        this.port = port;
        this.socket = new DatagramSocket(port);
        this.protocol = protocol.toUpperCase();
        this.seqNumBits = seqNumBits;
        this.maxSeqNum = (int) Math.pow(2, seqNumBits);
        this.buffer = new HashMap<>();

        if (!this.protocol.equals("GBN") && !this.protocol.equals("SR")) {
            throw new IllegalArgumentException("Protocol must be GBN (Go-Back-N) or SR (Selective Repeat)");
        }
        System.out.println("Receiver configured for " + this.protocol + " on port " + port);
    }

    public void start() {
        System.out.println("Receiver is listening...");
        byte[] receiveData = new byte[1024];

        while (running) {
            try {
                DatagramPacket receivePacket = new DatagramPacket(receiveData, receiveData.length);
                socket.receive(receivePacket);

                Packet packet = Packet.fromBytes(receivePacket.getData());
                System.out.println("Received: " + packet);

                if (packet.getType() == Packet.TYPE_DATA) {
                    if (protocol.equals("GBN")) {
                        handleGoBackN(packet, receivePacket.getAddress(), receivePacket.getPort());
                    } else if (protocol.equals("SR")) {
                        handleSelectiveRepeat(packet, receivePacket.getAddress(), receivePacket.getPort());
                    }
                }

            } catch (Exception e) {
                System.err.println("Error in receiver loop: " + e.getMessage());
                e.printStackTrace();
            }
        }
        socket.close();
    }

    private void handleGoBackN(Packet packet, InetAddress senderAddress, int senderPort) throws IOException {
        if (packet.getSeqNum() == expectedSeqNum) {
            // Correct packet received
            receivedMessage.append(packet.getData());
            System.out.println("Appended data: " + packet.getData() + ". Full message: \"" + receivedMessage + "\"");

            // Send ACK for this packet
            sendAck(expectedSeqNum, senderAddress, senderPort);

            // Increment expected sequence number
            expectedSeqNum = (expectedSeqNum + 1) % maxSeqNum;
        } else {
            // Wrong packet, discard and resend ACK for the last correctly received packet
            System.out.println("Discarding packet. Expected " + expectedSeqNum + ", but got " + packet.getSeqNum());
            // The ACK for the last in-order packet is (expectedSeqNum - 1)
            int lastAcked = (expectedSeqNum == 0) ? (maxSeqNum - 1) : (expectedSeqNum - 1);
            sendAck(lastAcked, senderAddress, senderPort);
        }
    }

    private void handleSelectiveRepeat(Packet packet, InetAddress senderAddress, int senderPort) throws IOException {
        // Always send an ACK for the received packet, regardless of order
        sendAck(packet.getSeqNum(), senderAddress, senderPort);

        // Check if the packet is within the receive window
        // Simplified check: assume window size is large enough. A full implementation would track the window base.
        if (packet.getSeqNum() == expectedSeqNum) {
            // Packet is the one we were waiting for. Append its data.
            receivedMessage.append(packet.getData());
            System.out.println("Appended data: " + packet.getData() + ". Full message: \"" + receivedMessage + "\"");
            expectedSeqNum = (expectedSeqNum + 1) % maxSeqNum;

            // Check buffer for any subsequent contiguous packets
            while (buffer.containsKey(expectedSeqNum)) {
                Packet bufferedPacket = buffer.remove(expectedSeqNum);
                receivedMessage.append(bufferedPacket.getData());
                System.out.println("Delivered buffered data: " + bufferedPacket.getData() + ". Full message: \"" + receivedMessage + "\"");
                expectedSeqNum = (expectedSeqNum + 1) % maxSeqNum;
            }
        } else {
            // Out-of-order packet. Buffer it if it's within the window.
            // Simplified: we buffer any packet with seqNum > expectedSeqNum
            if (packet.getSeqNum() > expectedSeqNum) {
                 System.out.println("Buffering out-of-order packet with seqNum " + packet.getSeqNum());
                 buffer.put(packet.getSeqNum(), packet);
            }
        }
    }

    private void sendAck(int ackNum, InetAddress senderAddress, int senderPort) throws IOException {
        Packet ackPacket = new Packet(Packet.TYPE_ACK, ackNum, "");
        byte[] ackData = ackPacket.toBytes();
        DatagramPacket ackDatagram = new DatagramPacket(ackData, ackData.length, senderAddress, senderPort);
        socket.send(ackDatagram);
        System.out.println("Sent: ACK for seqNum=" + ackNum);
    }

    public static void main(String[] args) {
        if (args.length != 3) {
            System.out.println("Usage: java Receiver <port> <GBN|SR> <seq_num_bits>");
            return;
        }
        try {
            int port = Integer.parseInt(args[0]);
            String protocol = args[1];
            int seqNumBits = Integer.parseInt(args[2]);
            Receiver receiver = new Receiver(port, protocol, seqNumBits);
            receiver.start();
        } catch (Exception e) {
            e.printStackTrace();
        }
    }
}
