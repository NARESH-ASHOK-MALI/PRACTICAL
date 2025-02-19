import java.util.Scanner;
public class W05_P5{
      public static void main (String   args[ ] ) {
		Scanner scan = new Scanner(System.in);
          int i=scan.nextInt();
          int j;
          scan.close(); // Closing the scanner

        try {
            switch (i) {
                case 0:
                    int zero = 0;
                    j = 92 / zero; 
                    break;
                case 1:
                    int b[] = null;
                    j = b[0];
                    break;
                default:
                    System.out.print("No exception");
            }
        } 
        catch (ArithmeticException e) {
            System.out.print("java.lang.ArithmeticException: / by zero");
        } 
        catch (NullPointerException e) {
            System.out.print("java.lang.NullPointerException");
        }

    }
    
}