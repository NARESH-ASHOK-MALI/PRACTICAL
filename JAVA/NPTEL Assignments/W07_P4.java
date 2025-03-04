import java.util.Scanner;
// Class to store and process an array of numbers
class NumberArray {
    private int[] numbers; // This array will store the numbers given by the user

    // Constructor to initialize the array
    public NumberArray(int[] numbers) {
        this.numbers = numbers;
    }
    public int getMax() {
        int max = numbers[0]; // Initialize max with the first element
        for (int num : numbers) {
            if (num > max) {
                max = num; // Update max if a larger number is found
            }
        }
        return max;
    }

public int getMin() {
    int min = numbers[0]; // Initialize min with the first element
    for (int num : numbers) {
        if (num < min) {
            min = num; // Update min if a smaller number is found
        }
    }
    return min;
}
}
// ==========================================================
// Main class to test the NumberArray class
public class W07_P4 {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);

        // Read 5 integers from the user and store them in an array
        int[] arr = new int[5]; // Create an array of size 5
        for (int i = 0; i < arr.length; i++) {
            arr[i] = scanner.nextInt(); // Read numbers from user
        }

        // Create an instance of NumberArray and print max & min values
        NumberArray numArray = new NumberArray(arr);
        System.out.println("Max: " + numArray.getMax() + ", Min: " + numArray.getMin());

        scanner.close(); // Close scanner to free resources
    }
}