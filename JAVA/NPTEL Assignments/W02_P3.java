import java.util.*;
public class W02_P3{
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int length = sc.nextInt();
        int breadth = sc.nextInt();
        // Define the class Rectangle here
// Use the this keyword in the constructor
// Define the area method

class Rectangle {
    int length, breadth;

    // Constructor
    Rectangle(int length, int breadth) {
        this.length = length; 
        this.breadth = breadth;
    }

    // Method to calculate area
     int area() {
        return length * breadth; //write the correct formula
    }
}
// Create an object of Rectangle and call the area method
Rectangle r = new Rectangle(length, breadth);
System.out.print(r.area());

sc.close();
}
}