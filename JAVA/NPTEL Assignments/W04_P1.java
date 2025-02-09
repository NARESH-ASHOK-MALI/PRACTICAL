// Import the required package(s) and/or class(es)

//HINT1:  Import of pre-defined package java.util and class Scanner
//HINT2:  Import of pre-defined package java.lang and class System and all of its member
import java.util.Scanner;
import static java.lang.System.out; 

public class W04_P1 {
    public static void main(String[] args) {
        // Scanner object is created
        Scanner scanner = new Scanner(System.in);
         // Read String input using scanner class
        String courseName = scanner.nextLine(); 
         // Print the scanned String
        out.println("Course: " + courseName); 
        scanner.close();
      }
}
