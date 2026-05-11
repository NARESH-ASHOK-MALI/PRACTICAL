// Implement A* algorithm to find the shortest path in a 8-puzzle problem.
// Heuristic: Number of misplaced tiles (simple & easy to understand)

import java.util.*;

public class Astar {

    // Goal state we want to reach:
    //  1 2 3
    //  4 5 6
    //  7 8 0    (0 = blank tile)
    static int[][] goal = {
        {1, 2, 3},
        {4, 5, 6},
        {7, 8, 0}
    };

    // ---------- Node class: represents one state of the puzzle ----------
    static class Node implements Comparable<Node> {
        int[][] board;   // current board configuration
        int g;           // cost so far  (number of moves made)
        int h;           // heuristic    (misplaced tiles)
        int f;           // total cost   f = g + h
        Node parent;     // to trace the solution path
        int blankRow, blankCol; // position of the blank (0)

        Node(int[][] board, int g, Node parent) {
            this.board  = board;
            this.g      = g;
            this.parent = parent;
            this.h      = countMisplaced();  // calculate heuristic
            this.f      = this.g + this.h;   // total cost
            findBlank();
        }

        // Heuristic: count how many tiles are NOT in their goal position
        int countMisplaced() {
            int count = 0;
            for (int i = 0; i < 3; i++)
                for (int j = 0; j < 3; j++)
                    if (board[i][j] != 0 && board[i][j] != goal[i][j])
                        count++;
            return count;
        }

        // Find where the blank tile (0) is
        void findBlank() {
            for (int i = 0; i < 3; i++)
                for (int j = 0; j < 3; j++)
                    if (board[i][j] == 0) {
                        blankRow = i;
                        blankCol = j;
                    }
        }

        // Check if this state is the goal
        boolean isGoal() {
            return Arrays.deepEquals(board, goal);
        }

        // Convert board to a string (used to track visited states)
        String boardToString() {
            StringBuilder sb = new StringBuilder();
            for (int[] row : board)
                for (int val : row)
                    sb.append(val).append(",");
            return sb.toString();
        }

        // For priority queue: node with smaller f comes first
        public int compareTo(Node other) {
            return Integer.compare(this.f, other.f);
        }
    }

    // ---------- Copy a 2D array ----------
    static int[][] copyBoard(int[][] board) {
        int[][] copy = new int[3][3];
        for (int i = 0; i < 3; i++)
            copy[i] = board[i].clone();
        return copy;
    }

    // ---------- A* Search ----------
    static void solve(int[][] start) {

        // Priority queue picks the node with lowest f = g + h
        PriorityQueue<Node> open = new PriorityQueue<>();

        // Set to remember boards we already visited
        Set<String> closed = new HashSet<>();

        // Step 1: Create the start node and add it to the open list
        Node startNode = new Node(start, 0, null);
        open.add(startNode);

        // Possible moves: Up, Down, Left, Right
        int[] dRow = {-1, 1, 0, 0};
        int[] dCol = {0, 0, -1, 1};

        System.out.println("Searching for solution...\n");

        // Step 2: Loop until we find the goal or exhaust all states
        while (!open.isEmpty()) {

            // Step 3: Pick the node with the smallest f value
            Node current = open.poll();

            // Step 4: If it's the goal, print the path and stop
            if (current.isGoal()) {
                System.out.println("Solution found!\n");
                printPath(current);
                System.out.println("Total moves: " + current.g);
                return;
            }

            // Step 5: Mark this state as visited
            closed.add(current.boardToString());

            // Step 6: Generate children by moving blank Up/Down/Left/Right
            for (int d = 0; d < 4; d++) {
                int newRow = current.blankRow + dRow[d];
                int newCol = current.blankCol + dCol[d];

                // Check bounds
                if (newRow >= 0 && newRow < 3 && newCol >= 0 && newCol < 3) {

                    // Make a copy and swap blank with the neighbour
                    int[][] newBoard = copyBoard(current.board);
                    newBoard[current.blankRow][current.blankCol] = newBoard[newRow][newCol];
                    newBoard[newRow][newCol] = 0;

                    Node child = new Node(newBoard, current.g + 1, current);

                    // Only add if we haven't visited this state before
                    if (!closed.contains(child.boardToString())) {
                        open.add(child);
                    }
                }
            }
        }

        System.out.println("No solution exists for this configuration.");
    }

    // ---------- Print the path from start to goal ----------
    static void printPath(Node node) {
        List<Node> path = new ArrayList<>();
        while (node != null) {
            path.add(node);
            node = node.parent;
        }
        Collections.reverse(path);

        for (int step = 0; step < path.size(); step++) {
            System.out.println("Step " + step + "  (g=" + path.get(step).g
                    + " h=" + path.get(step).h
                    + " f=" + path.get(step).f + ")");
            printBoard(path.get(step).board);
        }
    }

    // ---------- Pretty-print a board ----------
    static void printBoard(int[][] board) {
        for (int[] row : board) {
            for (int val : row)
                System.out.print((val == 0 ? "_" : val) + " ");
            System.out.println();
        }
        System.out.println();
    }

    // ---------- Main ----------
    public static void main(String[] args) {

        // Starting state (change this to try different puzzles)
        //  1 2 3
        //  4 _ 5
        //  7 8 6
        int[][] start = {
            {1, 2, 3},
            {4, 0, 5},
            {7, 8, 6}
        };

        System.out.println("Start state:");
        printBoard(start);

        System.out.println("Goal state:");
        printBoard(goal);

        solve(start);
    }
}
