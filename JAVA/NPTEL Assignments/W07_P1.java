import java.util.Scanner;

class W07_1 {
    private int num1;
    private int num2;
    // Constructor to initialize num1 and num2
    public W07_1(int num1, int num2) {
        this.num1 = num1;
        this.num2 = num2;
    }

    // Method to add numbers
    public int add() {
        return num1 + num2;
    }

    // Method to subtract numbers
    public int subtract() {
        return num1 - num2;
    }

    // Method to multiply numbers
    public int multiply() {
        return num1 * num2;
    }

    // Method to divide numbers with zero handling
    public int divide() {
        if (num2 == 0) {
            System.out.println("Error: Division by zero is not allowed.");
            return 0; // Returning default value to avoid crash
        }
        return num1 / num2;
    }
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int a = scanner.nextInt();
        int b = scanner.nextInt();

        W07_1 calc = new W07_1(a, b);
        System.out.println("Sum: " + calc.add());
        System.out.println("Difference: " + calc.subtract());
        System.out.println("Product: " + calc.multiply());
        System.out.println("Quotient: " + calc.divide());

        scanner.close();
    }
}