import java.util.*;
public class  W02_P2{
    String name;
    int age;
    String grade;

    public  W02_P2(String name, int age) {
        this.name = name;
        this.age = age;
    }

    public  W02_P2(String name, int age, String grade) {
        this.name = name;
        this.age = age;
        this.grade = grade;
    }

    public void displayInfo() {
        System.out.println("Name: " + name);
        System.out.println("Age: " + age);
        if(!grade.isEmpty()||grade!=null) System.out.print("Grade: " + grade);
    }

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        String name = sc.nextLine();
        int age = sc.nextInt();
        String grade= null;

        // Check if grade is provided or not
        if(sc.hasNextLine())
        {
         sc.nextLine();
         grade =  sc.nextLine();
         }
        
        // Create the student object
        W02_P2 student;
        // Write the appropriate constructor call code in the given spaces
if (grade == null ||grade.isEmpty()) {
    student = new  W02_P2(name , age );  // Add your code to call the constructor when grade is not given in input
} else {
    student = new  W02_P2(name , age ,grade );  // Add your code to call the constructor when grade is given in input
}

// code to call displayInfo function to display the information
student.displayInfo();  // Call the displayInfo method to display the student's information
sc.close();
    }
}