import java.util.Scanner;
class QuestionScope {
int sum(int a, int b){ //non-static method
        return a + b;
    }
static int multiply(int a, int b){ //static method
        return a * b;
    }
}
public class W03_P5{
public static void main( String[] args ) {
        Scanner sc = new Scanner(System.in);
	 int n1=sc.nextInt();
     int n2=sc.nextInt();
     QuestionScope st= new QuestionScope(); // Create an object to call non-static method
//Call the method sum() to find the sum of two numbers and store in result1
//Call the method multiply() to find the product of two numbers and store in result2
int result1 = st.sum(n1, n2);

int result2 = QuestionScope.multiply(n1, n2);
System.out.println(result1);
	System.out.print(result2);  
  }
}