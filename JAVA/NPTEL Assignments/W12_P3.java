import java.util.Scanner;

public class W12_P3 {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);

        // Read two numeric values
        double a = sc.nextDouble();
        double b = sc.nextDouble();

        // Read the operator (e.g., '+', '-', '*', '/')
        char op = sc.next().charAt(0);
        // ================================================
        // NOTE TO STUDENTS:
        // You have reached the final steps of this course.
        // This task is short, and you are expected to complete only one line.
        // Try to understand the code by yourself before checking the solution.
        // ================================================

        // TODO: Call operate with the two numbers and the operator, and print the result

        /*
         Hint:
         - Use the method operate(a, b, op) which returns a double.
         - You need to print its result directly.

         Pseudocode:
         System.out.println( ___ ); // What method do you need to call here?
        */
        System.out.println(operate(a, b, op));

        sc.close();
    }

    // Helper method to perform basic arithmetic operations
    public static double operate(double a, double b, char op) {
        switch (op) {
            case '+': return a + b;
            case '-': return a - b;
            case '*': return a * b;
            case '/': return a / b;
            default: return 0.0;
        }
    }
}