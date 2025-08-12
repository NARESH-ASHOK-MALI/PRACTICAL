import java.util.*;

class Process {
    int pid, at, bt, ct, tat, wt;

    Process(int pid, int at, int bt) {
        this.pid = pid;
        this.at = at;
        this.bt = bt;
    }
}

public class fcfs {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        System.out.print("Enter number of processes: ");
        int n = sc.nextInt();
        double twt=0;
        double ttat=0;

        List<Process> list = new ArrayList<>();
        for (int i = 0; i < n; i++) {
            System.out.print("Enter AT and BT for P" + (i + 1) + ": ");
            list.add(new Process(i + 1, sc.nextInt(), sc.nextInt()));
        }

        list.sort(Comparator.comparingInt(p -> p.at));

        int time = 0;
        for (Process p : list) {
            if (time < p.at) time = p.at;
            p.ct = time + p.bt;
            p.tat = p.ct - p.at;
            p.wt = p.tat - p.bt;
            time = p.ct;
            twt=twt+p.wt;
            ttat=ttat+p.tat;
        }

        System.out.println("\nPID\tAT\tBT\tCT\tTAT\tWT");
        for (Process p : list)
            System.out.println("P" + p.pid + "\t" + p.at + "\t" + p.bt + "\t" + p.ct + "\t" + p.tat + "\t" + p.wt);
        System.out.println("Average waiting time is :"+(twt/n));
        System.out.println("Average turn aroun time is :"+(ttat/n));
    }
}
