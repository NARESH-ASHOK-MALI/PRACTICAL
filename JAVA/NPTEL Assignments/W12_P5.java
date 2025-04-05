import java.util.Scanner;

public class W12_P5 {

    // Helper method to format an expression by replacing symbols with words
    public static String formatExpression(String input) {
        String output = input;
        output = output.replace("+", " Plus ");
        output = output.replace("-", " Minus ");
        output = output.replace("*", " Times ");
        output = output.replace("/", " Divided By ");
        return output;
    }

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);

        // Read an expression that contains digits and operators
        String expression = sc.nextLine();
        // ================================================
        // NOTE TO STUDENTS:
        // This is the final problem of the final week.
        // Reaching this far in the course is an achievement worth appreciating.
        // This problem is short and simple, and is meant to give you a clear and confident finish.
        // You need to write just one line to complete this task.
        // ================================================

        // TODO: Use the formatExpression method and print the formatted expression

        // Hint:
        // Call the method formatExpression and pass the string 'expression'
        // Then print the result using System.out.println
        // Example structure: System.out.println( _____ );
        System.out.println(formatExpression(expression));

        sc.close();
    }
}