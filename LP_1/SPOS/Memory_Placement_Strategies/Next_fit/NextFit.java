import java.util.Scanner;

public class NextFit {

    public static void nextFit(int blockSize[], int m, int processSize[], int n, int allocation[]) {
        // keep track of where last allocation happened
        int lastAllocatedIndex = 0;

        // initialize allocation to -1 (not allocated)
        for (int i = 0; i < n; i++) {
            allocation[i] = -1;
        }

        // loop through processes
        for (int i = 0; i < n; i++) {
            int count = 0; // to ensure we don't loop infinitely
            boolean allocated = false;

            // start from last allocated index and loop circularly
            int j = lastAllocatedIndex;

            while (count < m) {
                if (blockSize[j] >= processSize[i]) {
                    // allocate this block
                    allocation[i] = j;
                    blockSize[j] -= processSize[i];
                    lastAllocatedIndex = j; // update pointer
                    allocated = true;
                    break;
                }

                // move to next block (circular)
                j = (j + 1) % m;
                count++;
            }

            if (!allocated) {
                allocation[i] = -1; // not allocated
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

        // Perform Next Fit Allocation
        nextFit(blockSize, m, processSize, n, allocation);

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
