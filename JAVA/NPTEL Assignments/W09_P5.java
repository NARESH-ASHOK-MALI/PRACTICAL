import java.util.Scanner;
public class W09_P5{
	public static void main(String args[]){
		Scanner sc = new Scanner(System.in);
		String input = sc.nextLine(); // Read as string, e.g., 5+6
        // Declare and initialize the required variable(s)

// Split the input string into character array

/*
Write your method to separate two operands
and operators and then perform the required operation.
*/

// Print the output as stated in the question
char operator = ' ';
        String operand1 = "", operand2 = "";
        boolean isSecondOperand = false;

        for (int i = 0; i < input.length(); i++) {
            char ch = input.charAt(i);

            if (Character.isDigit(ch)) {
                if (!isSecondOperand) {
                    operand1 += ch;
                } else {
                    operand2 += ch;
                }
            } else if (ch == '+' || ch == '-' || ch == '*' || ch == '/') {
                operator = ch;
                isSecondOperand = true;
            }
        }

        int num1 = Integer.parseInt(operand1);
        int num2 = Integer.parseInt(operand2);
        int result = 0;

        switch (operator) {
            case '+':
                result = num1 + num2;
                break;
            case '-':
                result = num1 - num2;
                break;
            case '*':
                result = num1 * num2;
                break;
            case '/':
                if (num2 != 0) {
                    result = num1 / num2;
                } else {
                    System.out.println("Error: Division by zero");
                    return;
                }
                break;
            default:
                System.out.println("Invalid operator");
                return;
        }

        // Display input and output in the correct format
        System.out.println(input + " = " + result);

}
}