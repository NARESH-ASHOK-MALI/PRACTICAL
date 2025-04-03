import java.sql.*;

public class W11_P5 {
    public static void main(String args[]) {
        try {
            // Set SQLite temp directory for NPTEL-compatible runtime
            System.setProperty("org.sqlite.tmpdir", "/tempfs");

            // Connect to database
            Connection conn = DriverManager.getConnection("jdbc:sqlite:/tempfs/db");

            // Create 'players' table and insert sample data
            Statement stmt = conn.createStatement();
            String CREATE_TABLE_SQL = "CREATE TABLE IF NOT EXISTS players (UID INT, First_Name VARCHAR(45), Last_Name VARCHAR(45), Age INT);";
            stmt.executeUpdate(CREATE_TABLE_SQL);

            // Clear old records and insert fresh test data
            stmt.executeUpdate("DELETE FROM players");
            stmt.executeUpdate("INSERT INTO players VALUES(6, 'Kiran', 'Devi', 20)");
            stmt.executeUpdate("INSERT INTO players VALUES(7, 'Suresh', 'Nair', 23)");

            // SQL query to count total records in table
            String sql = "SELECT COUNT(*) FROM players";
            // ================================================
            // NOTE TO STUDENTS:
            // Execute the query using the statement and store result in 'rs'
            // ================================================

            // TODO: Run the count query using stmt and assign result to 'rs'

            /*
             Guided pseudocode:

             // Use stmt to execute the SQL query and assign to rs
             ResultSet rs = stmt.executeQuery( ___ ); // TODO: Fill the blank with correct variable
            */
            // Move to first row of the result and print the count
            ResultSet rs = stmt.executeQuery(sql);

            if (rs.next()) {
                int count = rs.getInt(1); // Get count from first column
                System.out.println("Number of records: " + count);
            }

            // Close resources
            conn.close();
        } catch (Exception e) {
            System.out.println(e);
        }
    }
}