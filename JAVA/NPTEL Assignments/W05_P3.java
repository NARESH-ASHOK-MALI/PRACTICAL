import java.util.Scanner;
  
  public class W05_P3 {
  public static void main(String[] args) { 
      int a, b;
      Scanner input = new Scanner(System.in);
       // Read any two values for a and b
       int result;  

       a = input.nextInt();
       b = input.nextInt();
       //Get the result of a/b;


//# try block to divide two numbers and display the result
      //#_____ {
              //result = //#____
              //System.out.print(result);
     	  //   }
          //# catch block to catch the ArithmeticException
          //catch (//#_________) {
          //   System.out.print("//#_________");
          //}
          input.close(); 
        try {
            result = a / b;  
            System.out.print(result); 
        } catch (ArithmeticException e) {  
            System.out.print("Exception caught: Division by zero.");
        }
        }
    }