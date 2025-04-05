import java.util.Scanner;

public class W12_P2 {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);

        // Read a single character input representing a calculator function key
        char key = sc.next().charAt(0);
        // ================================================
        // NOTE TO STUDENTS:
        // This is the final week of the course, and you are doing great.
        // This problem is intentionally simple and designed to encourage exploration.
        // Your task is to write just one line of code to call the helper method.
        // ================================================

        // TODO: Call mapFunction with the key and print the returned function name

        /*
         Hint:
         - The method mapFunction(char key) returns a string (e.g., "Addition").
         - Your task is to call it using the variable 'key' and print its result.

         Pseudocode:
         System.out.println( ___ ); // What goes inside the parentheses?
        */
        System.out.println(mapFunction(key));

        sc.close();
    }

    // Helper method that maps each calculator key to its function name
    public static String mapFunction(char key) {
        switch (key) {
            case '+': return "Addition";
            case '-': return "Subtraction";
            case '*': return "Multiplication";
            case '/': return "Division";
            case 'R': return "Square Root";
            case 'S': return "Square";
            case 'F': return "Reciprocal";
            case '=': return "Equals";
            case 'C': return "Clear";
            default: return "Unknown Function";
        }
    }
}