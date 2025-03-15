import java.util.Scanner;

public class W08_P1 {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        
        
        int number = scanner.nextInt();
        // TEMPLATE BLOCK (Students should complete the code here)
        
        // TODO: Initialize a variable to store the sum of digits
        // TODO: Use a loop to extract each digit and add it to the sum
        // TODO: Print the sum of the digits
        
       
/* Hints Section (Check only if you are stuck!)
 * ------------------------------------------------
 * - Use modulus (%) to extract the last digit
 * - Use division (/) to remove the last digit
 * - Use a loop until the number becomes zero
 */

 int sum = 0; 
 while (number != 0) {
     int digit = number % 10; 
     sum += digit;
     number /= 10;
 }
 
 System.out.println(sum); 
scanner.close();
    }
}