import java.sql.*;

public class W11_P4 {
    public static void main(String args[]) {
        try {
            // Set SQLite temp path (required for NPTEL environment)
            System.setProperty("org.sqlite.tmpdir", "/tempfs");

            // Establish database connection
            Connection conn = DriverManager.getConnection("jdbc:sqlite:/tempfs/db");

            // Create table and insert records
            Statement stmt = conn.createStatement();
            String CREATE_TABLE_SQL = "CREATE TABLE IF NOT EXISTS players (UID INT, First_Name VARCHAR(45), Last_Name VARCHAR(45), Age INT);";
            stmt.executeUpdate(CREATE_TABLE_SQL);

            // Clear previous rows and add new ones
            stmt.executeUpdate("DELETE FROM players");
            stmt.executeUpdate("INSERT INTO players VALUES(4, 'Neha', 'Sharma', 25)");
            stmt.executeUpdate("INSERT INTO players VALUES(5, 'Aman', 'Verma', 21)");

            // Define the SQL query string
            String sql = "SELECT * FROM players";
            // ================================================
            // NOTE TO STUDENTS:
            // Execute the above query using the Statement object.
            // Store the returned results in a ResultSet variable.
            // ================================================

            // TODO: Run the query using stmt and assign result to 'rs'

            /*
             Guided pseudocode:

             // Use stmt to execute the query and assign to ResultSet
             ResultSet rs = stmt.executeQuery( ___ ); // TODO: What goes inside the parentheses?
            */
            // Print out each row from the result set
            ResultSet rs = stmt.executeQuery(sql);
            while (rs.next()) {
                System.out.println(rs.getInt(1) + "  " +
                                   rs.getString(2) + "  " +
                                   rs.getString(3) + "  " +
                                   rs.getInt(4));
            }

            // Close connection
            conn.close();
        } catch (Exception e) {
            System.out.println(e);
        }
    }
}