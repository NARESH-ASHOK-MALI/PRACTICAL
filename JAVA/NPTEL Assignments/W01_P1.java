import java.util.Scanner;

public class W01_P1 {
    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);
        int number = in.nextInt();
        // Check if the number is even or odd
	        
		 if(number==0){
            System.out.println("You have Entered zero");
            }else if ( number%2==0){
                System.out.print("Even");
            }else{
                System.out.print("Odd");
            }
            in.close();
        }
    }