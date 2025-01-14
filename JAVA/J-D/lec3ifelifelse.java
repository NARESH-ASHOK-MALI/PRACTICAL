import java.util.*;
public class lec3ifelifelse {
    public static void main (String [] args){
        Scanner sc= new Scanner(System.in);
        System.out.println("Enter Number to check if it is even or Odd");
        int a=sc.nextInt();
        if (a%2==0) {
            System.out.println("No. is Even");
        }else{
            System.out.println("Odd");
        }
        System.out.println("Enter Number to check if it is equal to next Number");
        Scanner sc1= new Scanner(System.in);
        Scanner sc2= new Scanner(System.in);
        int b=sc1.nextInt();
        int c=sc2.nextInt();
        if(b>c){
            System.out.println("first Number is greater");
        }else if(b==c){
            System.out.println("both Entries are Equal");
        }else{
            System.out.println("Second Number is greater");
        }
        // System.out.println("Enter button");
        // Scanner sc3= new Scanner (System.in);
        // int bt=sc3.nextInt();
        // if(bt==1)
        // System.out.println("Hello");
        // else if (bt==2)
        // System.out.println("Namaste");
        // else if (bt==3)
        // System.out.println("Bounjour");
        // else
        // System.out.println("Invalid Button");
        System.out.println("Enter button");
        Scanner sc4= new Scanner( System.in);
        int button=sc4.nextInt();
        switch(button){
            case 1:System.out.println("Hello");
            break;
            case 2:System.out.println("Namaste");
            break;
            case 3:System.out.println("Bounjour");
            break;
            default:System.out.println("Invalid button Pressed");
        }



    }
}
