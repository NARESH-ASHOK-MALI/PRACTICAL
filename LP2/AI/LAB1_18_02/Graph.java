// Implement depth first search algorithm and Breadth First Search algorithm, 
// Use an undirected graph and develop a recursive algorithm for searching all 
// the vertices of a graph data structure.
class Graph {

    int V = 10;   // number of vertices
    int[][] adj = new int[V][V];  // adjacency matrix

    // Add edge (Undirected)
    void addEdge(int u, int v) {
        adj[u][v] = 1;
        adj[v][u] = 1;
    }

    // ---------------- DFS (Recursive) ----------------
   void DFS(int v, boolean[] visited) {
    visited[v] = true;          // Step 1: Mark current vertex as visited
    System.out.print(v + " "); // Step 2: Print it (process it)

    for (int i = 0; i < V; i++) {
        if (adj[v][i] == 1 && !visited[i]) {  // Step 3: Find unvisited neighbors
            DFS(i, visited);                   // Step 4: Recurse into them
        }
    }
}

    // ---------------- BFS ----------------
    void BFS(int start) {
    boolean[] visited = new boolean[V];  // Step 1: track visited vertices
    int[] queue = new int[V];            // Step 2: manual queue using an array
    int front = 0, rear = 0;

    visited[start] = true;               // Step 3: mark start as visited
    queue[rear++] = start;               // Step 4: enqueue start vertex

    while (front < rear) {               // Step 5: loop until queue is empty
        int current = queue[front++];    // Step 6: dequeue front element
        System.out.print(current + " "); // Step 7: print/process it

        for (int i = 0; i < V; i++) {
            if (adj[current][i] == 1 && !visited[i]) {  // Step 8: find unvisited neighbors
                visited[i] = true;       // mark before enqueuing (prevents duplicates)
                queue[rear++] = i;       // Step 9: enqueue neighbor
            }
        }
    }
}

    // ---------------- Main ----------------
    public static void main(String[] args) {

        Graph g = new Graph();

        g.addEdge(0, 1);
        g.addEdge(0, 2);
        g.addEdge(0, 3);
        g.addEdge(1, 4);
        g.addEdge(1, 5);
        g.addEdge(2, 6);
        g.addEdge(2, 7);
        g.addEdge(3, 8);
        g.addEdge(3, 9);

        boolean[] visited = new boolean[g.V]; // all false by default

        System.out.println("DFS Traversal:");
        g.DFS(0, visited); // start DFS from vertex 0

        System.out.println("\nBFS Traversal:");
        g.BFS(0); // start BFS from vertex 0
    }
}