import java.util.*;
public class lec2inputoutput {
    public static void main (String [] args){
        System.out.println("This is the first program to demonstrate Java language");
        System.out.println("Enter The Two Numbers");
        Scanner sc = new Scanner(System.in);
        int a=sc.nextInt();
        Scanner sc1 = new Scanner(System.in);
        int b=sc1.nextInt();
        System.out.print("Sum is ");
        System.out.println(a+b);
        System.out.print("Difference is ");
        System.out.println(b-a);
        System.out.print("Multiplication  of given numeber is ");
        System.out.println(a*b);
    }
}
