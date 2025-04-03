import java.sql.*; // Required for JDBC classes

public class W10_P4 {
    public static void main(String[] args) {
        try {
            // Set SQLite temp directory to avoid native driver errors in restricted environments
            System.setProperty("org.sqlite.tmpdir", "/tempfs");

            // Create a connection to the SQLite database
            Connection conn = DriverManager.getConnection("jdbc:sqlite:/tempfs/studentdb");

            // Create a Statement object to send SQL statements to the database
            Statement stmt = conn.createStatement();

            // SQL query string to create the 'students' table
            String sql = "CREATE TABLE students(roll INTEGER, name VARCHAR(30))";
            // ================================================
            // NOTE TO STUDENTS:
            // Try to solve the task on your own before referring to external help.
            // Avoid using online sources or tools unless absolutely necessary.
            // Engaging with the problem independently will improve your understanding and confidence.
            // ================================================
            stmt.executeUpdate(sql);

            // TODO: Execute the SQL command to create the table using the Statement object

            /*
             Hint (if needed):
             - Use the executeUpdate(...) method of the Statement object
             - Pass the SQL string variable 'sql' as the argument

             Pseudocode:
             stmt.executeUpdate(...Todo....);
            */
            // If the table is created without exceptions, print success
            System.out.println("success");

            // Close statement and connection to release resources
            stmt.close();
            conn.close();
        } catch (Exception e) {
            System.out.println(e);
        }
    }
}