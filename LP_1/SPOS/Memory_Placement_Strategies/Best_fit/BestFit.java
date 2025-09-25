import java.util.Scanner;

public class BestFit {

    public static void bestFit(int blockSize[], int m, int processSize[], int n, int allocation[]) {
        // initialize allocation to -1 (not allocated)
        for (int i = 0; i < n; i++) {
            allocation[i] = -1;
        }

        // loop through each process
        for (int i = 0; i < n; i++) {
            int bestIdx = -1;

            // find the best (smallest) block for process i
            for (int j = 0; j < m; j++) {
                if (blockSize[j] >= processSize[i]) {
                    if (bestIdx == -1 || blockSize[j] < blockSize[bestIdx]) {
                        bestIdx = j;
                    }
                }
            }

            // if found, allocate
            if (bestIdx != -1) {
                allocation[i] = bestIdx;
                blockSize[bestIdx] -= processSize[i];
            }
        }
    }

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);

        // Input memory blocks
        System.out.print("Enter number of memory blocks: ");
        int m = sc.nextInt();
        int[] blockSize = new int[m];
        int totalMemory = 0;

        System.out.println("Enter size of each memory block: ");
        for (int i = 0; i < m; i++) {
            blockSize[i] = sc.nextInt();
            totalMemory += blockSize[i];
        }

        // Input processes
        System.out.print("Enter number of processes: ");
        int n = sc.nextInt();
        int[] processSize = new int[n];
        int[] allocation = new int[n];

        for (int i = 0; i < n; i++) {
            System.out.print("Enter size of process " + (i + 1) + ": ");
            processSize[i] = sc.nextInt();
        }

        // Perform Best Fit Allocation
        bestFit(blockSize, m, processSize, n, allocation);

        // Output allocation
        System.out.println("\nProcess No.\tProcess Size\tBlock No.");
        int usedMemory = 0;
        for (int i = 0; i < n; i++) {
            System.out.print("   " + (i + 1) + "\t\t" + processSize[i] + "\t\t");
            if (allocation[i] != -1) {
                System.out.println(allocation[i] + 1);
                usedMemory += processSize[i];
            } else {
                System.out.println("Not Allocated");
            }
        }

        // Memory statistics
        int totalFragmentation = totalMemory - usedMemory;
        double memoryUsage = ((double) usedMemory / totalMemory) * 100;

        System.out.println("\nTotal Fragmentation: " + totalFragmentation);
        System.out.printf("Memory Usage: %.2f%%\n", memoryUsage);

        sc.close();
    }
}
