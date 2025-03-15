import java.util.Scanner;

public class W08_P3 {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        
        
        int number = scanner.nextInt();
        // TEMPLATE BLOCK (Students should complete the code here)
        
        // TODO: Initialize a variable to store the reversed number
        // TODO: Use a loop to extract and reverse digits
        // TODO: Print the reversed number
        

/* Hints Section (Check only if you are stuck!)
 * ------------------------------------------------
 * - Use modulus (%) to extract digits
 * - Use multiplication to build the reversed number
 */
int reversedNumber = 0; 
        while (number != 0) {
            int digit = number % 10; 
            reversedNumber = reversedNumber * 10 + digit; 
            number /= 10; 
        }
        
        System.out.print(reversedNumber);
scanner.close();
    }
}