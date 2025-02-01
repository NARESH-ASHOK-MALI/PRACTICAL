import java.util.Scanner;
class W03_P1{
    //Create recursive method to find factorial of a number
public static long factorial(int n) {
    if (n == 0 || n == 1) { // Base case
        return 1;
    }
    return n * factorial(n - 1); // Recursive call
}
public static void main(String[] args) {
    Scanner in = new Scanner(System.in);
    int x;
    x = in.nextInt();
    System.out.print(factorial(x));   
    in.close();
}
}