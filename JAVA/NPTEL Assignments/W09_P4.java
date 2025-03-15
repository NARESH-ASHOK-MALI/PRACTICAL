import java.util.Scanner;
public class W09_P4{
	public static void main(String args[]){
		Scanner sc = new Scanner(System.in);
		String input = sc.nextLine();
        // Write code below...
        // Write code below...

        String operand1 = "";
        String operand2 = "";
        char operator = ' ';
        boolean isSecondOperand = false;

        for (int i = 0; i < input.length(); i++) {
            char mappedChar = gui_map(input.charAt(i));

            if (Character.isDigit(mappedChar) || mappedChar == '.') {
                if (!isSecondOperand) {
                    operand1 += mappedChar;
                } else {
                    operand2 += mappedChar;
                }
            } else if (mappedChar == '+' || mappedChar == '-' || mappedChar == 'X' || mappedChar == '/') {
                operator = mappedChar;
                isSecondOperand = true;
            } else if (mappedChar == '=') {
                break; // Stop processing once '=' is found
            }
        }

        double result = 0;
        if (!operand1.isEmpty() && !operand2.isEmpty()) {
            double num1 = Double.parseDouble(operand1);
            double num2 = Double.parseDouble(operand2);

            switch (operator) {
                case '+':
                    result = num1 + num2;
                    break;
                case '-':
                    result = num1 - num2;
                    break;
                case 'X':
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
            }
            System.out.printf("%.1f\n", result); // Output result to one decimal place
        }

        sc.close();
    
        }// The main() method ends here.
	
// A method that takes a character as input and returns the corresponding GUI character	

	static char gui_map(char in){
		char out = 'N';// N = Null/Empty
		char gm[][]={{'a','.'}
					,{'b','0'}
					,{'c','='}
					,{'d','+'}
					,{'e','1'}
					,{'f','2'}
					,{'g','3'}
					,{'h','-'}
					,{'i','4'}
					,{'j','5'}
					,{'k','6'}
					,{'l','X'}
					,{'m','7'}
					,{'n','8'}
					,{'o','9'}
					,{'p','/'}};
					
		// Checking for maps
		for(int i=0; i<gm.length; i++){
			if(gm[i][0]==in){
				out=gm[i][1];
				break;
			}
		}
		return out;
	}
}