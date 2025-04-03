import java.sql.*; // Required for JDBC classes like Connection and DriverManager

public class W10_P3 {
    public static void main(String[] args) {
        try {
            // Set up a Connection reference to hold the database connection
            Connection conn = null;

            // JDBC URL string pointing to the SQLite database path
            String DB_URL = "jdbc:sqlite:/tempfs/studentdb";

            // This line sets a temporary directory for SQLite to avoid permission issues
            System.setProperty("org.sqlite.tmpdir", "/tempfs");
            // ================================================
            // NOTE TO STUDENTS:
            // Try to solve the task on your own before referring to external help.
            // Avoid using online sources or tools unless absolutely necessary.
            // Engaging with the problem independently will improve your understanding and confidence.
            // ================================================

            // TODO: Establish a connection to the database using DriverManager.getConnection
            System.setProperty("org.sqlite.tmpdir", "/tempfs");

            /*
             Hint (only if needed):
             - Use DriverManager.getConnection(...) method and pass DB_URL as the argument
             - Assign the returned Connection object to the variable 'conn'

             Pseudocode:
             conn = DriverManager.getConnection(......_URL);
            */
            conn = DriverManager.getConnection(DB_URL);

            // If the connection is successful, conn.isValid(1) will return true
            System.out.println(conn.isValid(1));

            // Always close the connection after use
            conn.close();
        } catch (Exception e) {
            System.out.println(e);
        }
    }
}