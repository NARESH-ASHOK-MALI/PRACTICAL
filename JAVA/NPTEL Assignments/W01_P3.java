import java.util.Scanner;

public class W01_P3 {
    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);
        int n = in.nextInt();
        // Print the multiplication table of number n
        for (int i = 1; i <= 5; i++) {
              System.out.println(n + " x " + i + " = " + n * i);
        }
        in.close();
    }
}