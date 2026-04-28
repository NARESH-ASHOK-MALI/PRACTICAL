import java.util.*;

class Process {
    int pid;       // Process ID
    int burst;     // Burst Time
    int priority;  // Priority
    int waiting;   // Waiting Time
    int turnaround;// Turnaround Time

    Process(int pid, int burst, int priority) {
        this.pid = pid;
        this.burst = burst;
        this.priority = priority;
        this.waiting = 0;
        this.turnaround = 0;
    }
}

class PriorityScheduling {

    // Method to calculate Waiting and Turnaround Times
    public void schedule(List<Process> processes) {
        // Sort by Priority (higher number = higher priority)
        processes.sort((a, b) -> b.priority - a.priority);

        int currentTime = 0;
        for (Process p : processes) {
            p.waiting = currentTime;
            p.turnaround = p.waiting + p.burst;
            currentTime += p.burst;
        }
    }

    // Method to display process details
    public void display(List<Process> processes) {
        System.out.println("PID\tBurst\tPriority\tWaiting\tTurnaround");
        int totalWait = 0, totalTAT = 0;

        for (Process p : processes) {
            System.out.println(p.pid + "\t" + p.burst + "\t" + p.priority + "\t\t" + p.waiting + "\t" + p.turnaround);
            totalWait += p.waiting;
            totalTAT += p.turnaround;
        }

        System.out.println("\nAverage Waiting Time: " + (totalWait / (float) processes.size()));
        System.out.println("Average Turnaround Time: " + (totalTAT / (float) processes.size()));
    }
}

public class Priority {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        List<Process> processes = new ArrayList<>();

        System.out.print("Enter number of processes: ");
        int n = sc.nextInt();

        for (int i = 0; i < n; i++) {
            System.out.print("Enter Burst Time for Process " + (i + 1) + ": ");
            int burst = sc.nextInt();
            System.out.print("Enter Priority for Process " + (i + 1) + ": ");
            int priority = sc.nextInt();
            processes.add(new Process(i + 1, burst, priority));
        }

        PriorityScheduling scheduler = new PriorityScheduling();
        scheduler.schedule(processes);
        scheduler.display(processes);

        sc.close();
    }
}
