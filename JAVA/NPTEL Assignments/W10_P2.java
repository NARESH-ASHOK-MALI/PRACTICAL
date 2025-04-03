import java.sql.*;  // Import required for JDBC classes

public class W10_P2 {
    public static void main(String[] args) {
        try {
            // We will attempt to load the SQLite JDBC driver class.
            // If successful, we'll print true.
            // If the driver class isn't available, we'll catch the error and print false.
            // ================================================
            // NOTE TO STUDENTS:
            // Try to solve the task on your own before referring to external help.
            // Avoid using online sources or tools unless absolutely necessary.
            // Engaging with the problem independently will improve your understanding and confidence.
            // ================================================

            // TODO: Load the JDBC driver class for SQLite using Class.forName

            /*
             Hint (read only if necessary):
             - The Class.forName() method is used to load a class at runtime by its fully qualified name.
             - For the SQLite JDBC driver, the class name to load is: "org.sqlite.JDBC"
             
             Pseudocode:
             Class.forName("org.sqlite......");
             
            */
            Class.forName("org.sqlite.JDBC");

            // If the driver loads successfully, this line will execute.
            System.out.println(true);
        } catch (Exception e) {
            // If there is any error in loading the driver, this line will execute.
            System.out.println(false);
        }
    }
}