import java.io.*;

public class Optimal {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        int frames, hit = 0, fault = 0, ref_len;
        int buffer[];
        int reference[];
        int mem_layout[][];

        System.out.print("Enter the Number of Frames: ");
        frames = Integer.parseInt(br.readLine());

        System.out.print("Enter the Length of Reference String: ");
        ref_len = Integer.parseInt(br.readLine());

        reference = new int[ref_len];
        buffer = new int[frames];
        mem_layout = new int[frames][ref_len];

        // Initialize buffer with -1
        for (int j = 0; j < frames; j++)
            buffer[j] = -1;

        System.out.println("Please enter the reference string: ");
        for (int i = 0; i < ref_len; i++) {
            reference[i] = Integer.parseInt(br.readLine());
        }

        for (int i = 0; i < ref_len; i++) {
            int search = -1;

            // Check for hit
            for (int j = 0; j < frames; j++) {
                if (buffer[j] == reference[i]) {
                    search = j;
                    hit++;
                    break;
                }
            }

            // Page Fault
            if (search == -1) {
                int pos = -1, farthest = i;

                // Check for empty frame
                for (int j = 0; j < frames; j++) {
                    if (buffer[j] == -1) {
                        pos = j;
                        break;
                    }
                }

                // If no empty frame, find farthest future use
                if (pos == -1) {
                    for (int j = 0; j < frames; j++) {
                        int next_use = -1;
                        for (int k = i + 1; k < ref_len; k++) {
                            if (buffer[j] == reference[k]) {
                                next_use = k;
                                break;
                            }
                        }
                        if (next_use == -1) { 
                            pos = j;
                            break;
                        }
                        if (next_use > farthest) {
                            farthest = next_use;
                            pos = j;
                        }
                    }
                }

                buffer[pos] = reference[i];
                fault++;
            }

            // Save buffer state for this step
            for (int j = 0; j < frames; j++) {
                mem_layout[j][i] = buffer[j];
            }
        }

        // Print Table
        System.out.println("\nOptimal Page Replacement Table:\n");

        System.out.print("Ref String : ");
        for (int i = 0; i < ref_len; i++) {
            System.out.printf("%3d ", reference[i]);
        }
        System.out.println();

        for (int i = 0; i < frames; i++) {
            System.out.printf("Frame %d   : ", i + 1);
            for (int j = 0; j < ref_len; j++) {
                if (mem_layout[i][j] == -1)
                    System.out.print("  - ");
                else
                    System.out.printf("%3d ", mem_layout[i][j]);
            }
            System.out.println();
        }

        System.out.println("\nTotal Hits: " + hit);
        System.out.printf("Hit Ratio: %.2f\n", (float) hit / ref_len);
        System.out.println("Total Faults: " + fault);
    }
}
