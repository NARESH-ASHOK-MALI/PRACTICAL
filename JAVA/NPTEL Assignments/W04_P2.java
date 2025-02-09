public class W04_P2 {
    public static void main(String args[]){
		int year; // integer type variable to store year	

                 // Create an object of Calendar class. 
                 java.util.Calendar current; 

                // Use getInstance() method to initialize the Calendar object.
                 current = java.util.Calendar.getInstance();
                 // Initialize the int variable year with the current year
                 year = current.get(java.util.Calendar.YEAR);
                 // Print the current Year
                 System.out.println("Current Year: "+year);

}

}
