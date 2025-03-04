// Class to implement a counter


class Counter {
    private int count;
    // Constructor to initialize count to zero
    public Counter() {
        this.count = 0;
    }

    // Method to increment count by 1
    public void increment() {
        count++;
    }

    // Method to decrement count by 1 but ensuring it does not go below zero
    public void decrement() {
        if (count > 0) {
            count--;
        }
    }

    // Method to return the current value of count
    public int getValue() {
        return count;
    }

}
public class W07_P2 {
    public static void main(String[] args) {
        Counter counter = new Counter();
        counter.increment();
        counter.increment();
        counter.decrement();
        System.out.println(counter.getValue()); // Output: 1
    }
}