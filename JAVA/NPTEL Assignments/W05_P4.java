//Prefixed Fixed Code:
import java.util.Scanner;
import java.util.InputMismatchException;

public class W05_P4 {
  public static void main(String[] args) {
      Scanner sc = new Scanner(System.in); 
	int length = sc.nextInt(); 
	// create an array to save user input 
	int[] name = new int[length];
     int sum=0;//save the total sum of the array.
     /* 
Define try-catch block to save user input in the array "name"
If there is an exception then catch the exception otherwise print the total sum of the array. 
*/


     //try{
       //#traverse the array to find the total sum of the array.		  
     //}
     //  catch(InputMismatchException e) {
     //   System.out.print("You entered bad data.");
     //}
     try {
        // Traverse the array to save user input and compute sum
        for (int i = 0; i < length; i++) {
            name[i] = sc.nextInt(); // Read integer input
            sum += name[i]; // Add to sum
        }

        // Print total sum
        System.out.print(sum);
    } 
    catch (InputMismatchException e) { // Catch invalid input exception
        System.out.print("You entered bad data.");
    } 
    finally {
        sc.close(); // Close the Scanner
    }
    }
}