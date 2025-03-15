import java.util.Scanner;
public class W09_P2{
	public static void main(String args[]){
		Scanner sc = new Scanner(System.in);
         char[][] matrix = new char[5][5];
        for (int i = 0; i < 5; i++) {
            String row = sc.next(); // Read each row as a string
            if (row.length() != 5) {
                return;
            }
            for (int j = 0; j < 5; j++) {
                matrix[i][j] = row.charAt(j);
            }
        }

        // Side-by-side reflection
        for (int i = 0; i < 5; i++) {
            for (int j = 0; j < 5 / 2; j++) {
                // Swap elements symmetrically across the middle
                char temp = matrix[i][j];
                matrix[i][j] = matrix[i][4 - j];
                matrix[i][4 - j] = temp;
            }
        }
        for (int i = 0; i < 5; i++) {
            for (int j = 0; j < 5; j++) {
                System.out.print(matrix[i][j]);
            }
            System.out.println(); // Newline after each row
        }

        sc.close();
} // The main() method ends here
} // The main class end