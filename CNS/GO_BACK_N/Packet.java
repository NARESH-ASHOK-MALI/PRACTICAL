import java.io.ByteArrayInputStream;
import java.io.ByteArrayOutputStream;
import java.io.IOException;
import java.io.ObjectInputStream;
import java.io.ObjectOutputStream;
import java.io.Serializable;

/**
 * A simple Packet class to encapsulate data for the sliding window protocols.
 * Must be Serializable to be sent over ObjectOutput/InputStreams.
 */
public class Packet implements Serializable {
    private final int type; // 0 for data, 1 for ACK
    private final int seqNum;
    private final String data;

    public static final int TYPE_DATA = 0;
    public static final int TYPE_ACK = 1;

    public Packet(int type, int seqNum, String data) {
        this.type = type;
        this.seqNum = seqNum;
        this.data = data;
    }

    public int getType() {
        return type;
    }

    public int getSeqNum() {
        return seqNum;
    }

    public String getData() {
        return data;
    }

    /**
     * Converts the Packet object into a byte array for sending over UDP.
     */
    public byte[] toBytes() throws IOException {
        ByteArrayOutputStream byteStream = new ByteArrayOutputStream();
        ObjectOutputStream objStream = new ObjectOutputStream(byteStream);
        objStream.writeObject(this);
        objStream.flush();
        return byteStream.toByteArray();
    }

    /**
     * Creates a Packet object from a byte array received over UDP.
     */
    public static Packet fromBytes(byte[] data) throws IOException, ClassNotFoundException {
        ByteArrayInputStream byteStream = new ByteArrayInputStream(data);
        ObjectInputStream objStream = new ObjectInputStream(byteStream);
        return (Packet) objStream.readObject();
    }

    @Override
    public String toString() {
        return "Packet{" +
                "type=" + (type == TYPE_DATA ? "DATA" : "ACK") +
                ", seqNum=" + seqNum +
                ", data='" + data + '\'' +
                '}';
    }
}
