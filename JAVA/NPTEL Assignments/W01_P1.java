import java.util.Scanner;

public class W01_P1 {
   public W01_P1() {
   }

   public static void main(String[] var0) {
      Scanner var1 = new Scanner(System.in);
      int var2 = var1.nextInt();
      if (var2 == 0) {
         System.out.println(8);
      } else if (var2 % 2 == 0) {
         System.out.print("Even");
      } else {
         System.out.print("Odd");
      }

      var1.close();
   }
}