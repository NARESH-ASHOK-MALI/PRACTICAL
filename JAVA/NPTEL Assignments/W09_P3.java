import java.util.Scanner;
public class W09_P3{
	public static void main(String args[]){
		Scanner sc = new Scanner(System.in);
        // Input 5X5 2D Array using Scanner Class


// Perform 45-Degree rotation keeping center same (use your own logic)


// Print the transformed output 5X5 2D Array
char[][] matrix = new char[5][5];
char[][] rotated = new char[5][5];

// Input the matrix
for (int i = 0; i < 5; i++) {
    String row = sc.next();
    for (int j = 0; j < 5; j++) {
        matrix[i][j] = row.charAt(j);
        rotated[i][j] = '0'; // Initialize rotated matrix with '0'
    }
}

// Perform 45-degree anti-clockwise rotation
rotated[0][0] = matrix[2][0];
rotated[0][4] = matrix[0][2];
rotated[4][0] = matrix[4][2];
rotated[4][4] = matrix[2][4];

rotated[1][1] = matrix[2][1];
rotated[1][3] = matrix[1][2];
rotated[3][1] = matrix[3][2];
rotated[3][3] = matrix[2][3];

rotated[2][2] = matrix[2][2]; // Keep center unchanged

// Output the rotated matrix
for (int i = 0; i < 5; i++) {
    for (int j = 0; j < 5; j++) {
        System.out.print(rotated[i][j]);
    }
    System.out.println(); // Move to the next line after each row
}

sc.close();
} // The main() method ends here
} // The main class ends here