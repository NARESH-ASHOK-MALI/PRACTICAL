import java.util.*;
public class W01_P5{
    public static void main(String[] args) {
        Scanner inr = new Scanner(System.in);
        int n = inr.nextInt();
        for (int i = n; i >= 1; i--) {
            for (int j = 1; j <= i; j++) {
                System.out.print("*");
            }
            System.out.println();
        }
        
        // Print increasing part of the pattern
        for (int i = 2; i <= n; i++) {
            for (int j = 1; j <= i; j++) {
                System.out.print("*");
            }
            System.out.println(" ");
            }
        inr.close();
    }
}