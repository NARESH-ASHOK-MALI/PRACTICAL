// ================================================
// NOTE TO STUDENTS:
// Try to solve the task on your own before referring to external help.
// Avoid using online answers or tools unless absolutely necessary.
// Struggling with the problem is a part of the learning process and will help you build long-term understanding.
// ================================================

// TODO: Add the necessary import statements below so that the program can compile and connect to a database using JDBC.

/*
 What is this program about?
 - The goal is to write a Java program that establishes a database connection using JDBC (Java Database Connectivity).

 Why are import statements important?
 - In Java, import statements allow you to use classes and interfaces that are part of external packages.
 - If required classes are not imported, the program will not compile.

 How should you approach this?
 - Read through the code and identify which classes are being used.
 - Determine which packages these classes belong to.

 Helpful guidelines:
 - All JDBC-related classes such as Connection and DriverManager are found in the java.sql package.
 - The java.lang package is automatically imported, but can be explicitly mentioned for clarity.

 Example:
 - If you see a class like Connection being used, import it using:
   import java.sql.Connection;

 Your task:
 - Identify the required classes.
 - Import them from the correct packages using proper syntax.
 - Do not include unnecessary imports.
*/
import java.sql.Connection;
import java.sql.DriverManager;
import java.sql.SQLException;
public class W10_P1 {
    public static void main(String args[]) {
        try {
            Connection conn = null;
            String DB_URL = "jdbc:sqlite:/tempfs/db";
            System.setProperty("org.sqlite.tmpdir", "/tempfs");

            // Try to connect to the database
            conn = DriverManager.getConnection(DB_URL);
            System.out.print(conn.isValid(1));

            conn.close();
        } catch (Exception e) {
            System.out.println(e);
        }
    }
}