import java.util.Scanner;

class Employee {
    private String name;
    private double salary;
    // ================================
    // TODO: Implement the constructor to initialize name and salary.
    //       Implement getDetails() method to return employee details in the required format.
    //

    // Constructor to initialize name and salary
    public Employee(String name, double salary) {
        this.name = name;
        this.salary = salary;
    }

    // Method to return employee details in the required format
    public String getDetails() {
        return "Employee: " + name + ", Salary: " + salary;
    }
}

    public class W07_P3 {
        public static void main(String[] args) {
            Scanner scanner = new Scanner(System.in);
            String empName = scanner.next();
            double empSalary = scanner.nextDouble();
    
            Employee emp = new Employee(empName, empSalary);
            System.out.print(emp.getDetails());
    
            scanner.close();
        }
    }