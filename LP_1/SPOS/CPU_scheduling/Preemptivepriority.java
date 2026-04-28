import java.util.*;

class Process {
    int pid, at, bt, rt, pr, ct, tat, wt;
    boolean completed = false;

    Process(int pid, int at, int bt, int pr) {
        this.pid = pid;
        this.at = at;
        this.bt = bt;
        this.rt = bt; // remaining time
        this.pr = pr; // priority
    }
}

public class Preemptivepriority {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);

        System.out.print("Enter number of processes: ");
        int n = sc.nextInt();

        List<Process> list = new ArrayList<>();

        for (int i = 0; i < n; i++) {
            System.out.print("Enter AT, BT, Priority for P" + (i + 1) + ": ");
            int at = sc.nextInt();
            int bt = sc.nextInt();
            int pr = sc.nextInt();
            list.add(new Process(i + 1, at, bt, pr));
        }

        int completed = 0, time = 0;
        double totalWT = 0, totalTAT = 0;

        while (completed != n) {
            // Find process with highest priority among arrived and not completed
            Process current = null;
            int highestPriority = Integer.MIN_VALUE;

            for (Process p : list) {
                if (p.at <= time && !p.completed && p.pr > highestPriority) {
                    highestPriority = p.pr;
                    current = p;
                }
            }

            if (current == null) {
                time++;
                continue;
            }

            // Execute for 1 time unit
            current.rt--;
            time++;

            // If process finishes
            if (current.rt == 0) {
                current.completed = true;
                current.ct = time;
                current.tat = current.ct - current.at;
                current.wt = current.tat - current.bt;

                totalWT += current.wt;
                totalTAT += current.tat;
                completed++;
            }
        }

        // Display Results
        System.out.println("\nPID\tAT\tBT\tPR\tCT\tTAT\tWT");
        for (Process p : list) {
            System.out.println("P" + p.pid + "\t" + p.at + "\t" + p.bt + "\t" + p.pr + "\t" + p.ct + "\t" + p.tat + "\t" + p.wt);
        }

        System.out.println("\nAverage Waiting Time: " + (totalWT / n));
        System.out.println("Average Turnaround Time: " + (totalTAT / n));
    }
}
