import java.util.concurrent.Semaphore;

class RW {
    // Semaphores
    static Semaphore mutex = new Semaphore(1);  
    static Semaphore wrt = new Semaphore(1);   
    static int readCount = 0;                 

    // Reader Class
    static class Reader implements Runnable {
        int readerId;

        Reader(int id) {
            this.readerId = id;
        }

        @Override
        public void run() {
            try {
                
                mutex.acquire();
                readCount++;
                if (readCount == 1) {
                    wrt.acquire(); 
                }
                mutex.release();

                System.out.println("Reader " + readerId + " is reading");
                Thread.sleep(1000); // simulate read time
                System.out.println("Reader " + readerId + " has finished ");

                mutex.acquire();
                readCount--;
                if (readCount == 0) {
                    wrt.release(); 
                }
                mutex.release();

            } catch (InterruptedException e) {
                e.printStackTrace();
            }
        }
    }

    static class Writer implements Runnable {
        int writerId;

        Writer(int id) {
            this.writerId = id;
        }

        @Override
        public void run() {
            try {
                // Entry section
                wrt.acquire();

                // Critical Section (Writing)
                System.out.println("Writer " + writerId + " is Writing");
                Thread.sleep(1500); // simulate write time
                System.out.println("Writer " + writerId + " has finished writting");

                // Exit section
                wrt.release();

            } catch (InterruptedException e) {
                e.printStackTrace();
            }
        }
    }
}

// Main Class
public class ReaderWriterProblem {
    public static void main(String[] args) {
        // Create Reader and Writer threads
        Thread r1 = new Thread(new RW.Reader(1));
        Thread r2 = new Thread(new RW.Reader(2));
        Thread w1 = new Thread(new RW.Writer(1));
        Thread r3 = new Thread(new RW.Reader(3));
        Thread w2 = new Thread(new RW.Writer(2));

        r1.start();
        w1.start();
        r2.start();
        r3.start();
        w2.start();
    }
}
