import java.util.*;

class Process {
    int pid, at, bt, ct, tat, wt, rt;

    Process(int pid, int at, int bt) {
        this.pid = pid;
        this.at = at;
        this.bt = bt;
        this.rt = bt; // Remaining time initially equals burst time
    }
}

public class roundrobin {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        System.out.print("Enter number of processes: ");
        int n = sc.nextInt();
        
        System.out.print("Enter time quantum: ");
        int tq = sc.nextInt();
        
        double twt = 0;
        double ttat = 0;

        List<Process> list = new ArrayList<>();
        for (int i = 0; i < n; i++) {
            System.out.print("Enter AT and BT for P" + (i + 1) + ": ");
            list.add(new Process(i + 1, sc.nextInt(), sc.nextInt()));
        }

        // Sort by arrival time
        list.sort(Comparator.comparingInt(p -> p.at));

        Queue<Process> queue = new LinkedList<>();
        int time = 0;
        int completed = 0;
        int idx = 0;

        // Add first process to queue
        if (idx < n) {
            queue.add(list.get(idx));
            idx++;
        }

        while (completed < n) {
            if (queue.isEmpty()) {
                // CPU idle, jump to next arrival
                time = list.get(idx).at;
                queue.add(list.get(idx));
                idx++;
                continue;
            }

            Process p = queue.poll();

            // Execute process for time quantum or remaining time
            int execTime = Math.min(tq, p.rt);
            p.rt -= execTime;
            time += execTime;

            // Add newly arrived processes to queue
            while (idx < n && list.get(idx).at <= time) {
                queue.add(list.get(idx));
                idx++;
            }

            // If process completed
            if (p.rt == 0) {
                p.ct = time;
                p.tat = p.ct - p.at;
                p.wt = p.tat - p.bt;
                twt += p.wt;
                ttat += p.tat;
                completed++;
            } else {
                // Process not completed, add back to queue
                queue.add(p);
            }
        }

        System.out.println("\nPID\tAT\tBT\tCT\tTAT\tWT");
        for (Process p : list) {
            System.out.println("P" + p.pid + "\t" + p.at + "\t" + p.bt + "\t" + 
                             p.ct + "\t" + p.tat + "\t" + p.wt);
        }
        
        System.out.println("\nAverage Waiting Time: " + (twt / n));
        System.out.println("Average Turn Around Time: " + (ttat / n));
        
        sc.close();
    }
}
