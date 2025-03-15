import java.util.Scanner;
public class W09_P1 {
	public static void main(String args[]){
		Scanner sc = new Scanner(System.in);
        int[][] matrix = new int[5][5];

        // Input handling for continuous digits without spaces
        for (int i = 0; i < 5; i++) {
            String row = sc.next(); // Read entire row as a string
            for (int j = 0; j < 5; j++) {
                char ch = row.charAt(j);
                if (ch == '0' || ch == '1') {
                    matrix[i][j] = ch - '0'; // Convert char to integer
                } else {
                    System.out.println("Invalid input. Only 0 or 1 allowed.");
                    return; // Exit if input is invalid
                }
            }
        }

        // Flip-Flop operation
        for (int i = 0; i < 5; i++) {
            for (int j = 0; j < 5; j++) {
                matrix[i][j] = (matrix[i][j] == 0) ? 1 : 0;
            }
        }

        // Output the matrix
        for (int i = 0; i < 5; i++) {
            for (int j = 0; j < 5; j++) {
                System.out.print(matrix[i][j]);
            }
            System.out.println();
        }

        sc.close();
} // The main() ends here
} // The main class ends here