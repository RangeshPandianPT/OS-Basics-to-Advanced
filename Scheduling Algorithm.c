SCHEDULING ALGORITHMS – Priority & Round Robin

1. PRIORITY SCHEDULING ALGORITHM
Aim

To write a C program to simulate the CPU Priority Scheduling Algorithm.

Description

In Priority Scheduling, each process is assigned a priority.
The CPU is allocated to the process with the highest priority (lowest priority number).

To calculate average waiting time:

Sort processes based on priority

Waiting time of each process = sum of burst times of all previous processes

Algorithm

Start the process

Accept the number of processes

Assign Process ID, Burst Time, and Priority

Sort the processes according to priority

Set waiting time of first process = 0

For each process:

WT[i] = WT[i-1] + BT[i-1]

TAT[i] = WT[i] + BT[i]

Calculate:

Average Waiting Time

Average Turnaround Time

Display the results

Stop


Q1. C Program – Priority Scheduling

#include <stdio.h>

int main() {
    int n, i, j;
    printf("Enter number of processes: ");
    scanf("%d", &n);

    int bt[n], priority[n], pid[n], wt[n], tat[n];

    printf("Enter Burst Time and Priority for each process:\n");
    for (i = 0; i < n; i++) {
        pid[i] = i + 1;
        printf("P%d Burst Time: ", i + 1);
        scanf("%d", &bt[i]);
        printf("P%d Priority: ", i + 1);
        scanf("%d", &priority[i]);
    }

    // Sorting based on priority (lower value = higher priority)
    for (i = 0; i < n - 1; i++) {
        for (j = 0; j < n - i - 1; j++) {
            if (priority[j] > priority[j + 1]) {
                // Swap Burst Time
                int temp = bt[j];
                bt[j] = bt[j + 1];
                bt[j + 1] = temp;

                // Swap Priority
                temp = priority[j];
                priority[j] = priority[j + 1];
                priority[j + 1] = temp;

                // Swap Process ID
                temp = pid[j];
                pid[j] = pid[j + 1];
                pid[j + 1] = temp;
            }
        }
    }

    // Waiting time for first process
    wt[0] = 0;

    // Calculate waiting time
    for (i = 1; i < n; i++) {
        wt[i] = wt[i - 1] + bt[i - 1];
    }

    // Calculate turnaround time
    for (i = 0; i < n; i++) {
        tat[i] = wt[i] + bt[i];
    }

    printf("\nProcess\tBT\tPriority\tWT\tTAT\n");
    int totalWT = 0, totalTAT = 0;

    for (i = 0; i < n; i++) {
        printf("P%d\t%d\t%d\t\t%d\t%d\n", pid[i], bt[i], priority[i], wt[i], tat[i]);
        totalWT += wt[i];
        totalTAT += tat[i];
    }

    printf("\nAverage Waiting Time = %.2f", (float)totalWT / n);
    printf("\nAverage Turnaround Time = %.2f\n", (float)totalTAT / n);

    return 0;
}

2. ROUND ROBIN SCHEDULING ALGORITHM
Aim

To simulate the CPU scheduling algorithm using Round Robin Technique.

Description

Round Robin uses a fixed Time Quantum.
Each process gets CPU for that time slice.
If its burst time is not finished, it goes back to the ready queue.

This ensures fairness and avoids starvation.

Algorithm

Start the process

Input number of processes and time quantum

Input burst time for each process

Use a circular queue to schedule processes

For each process:

If remaining BT > time quantum → subtract TQ and continue

Else → process completes

Calculate:

Waiting Time

Turnaround Time

Display results

Stop


Q2. C Program – Round Robin Scheduling
#include <stdio.h>

int main() {
    int n, tq, i;
    printf("Enter number of processes: ");
    scanf("%d", &n);

    int bt[n], rem_bt[n], wt[n], tat[n];

    printf("Enter burst time for each process:\n");
    for (i = 0; i < n; i++) {
        printf("P%d: ", i + 1);
        scanf("%d", &bt[i]);
        rem_bt[i] = bt[i];
        wt[i] = 0;
    }

    printf("Enter Time Quantum: ");
    scanf("%d", &tq);

    int t = 0;  // Current time

    // Round Robin logic
    while (1) {
        int done = 1;

        for (i = 0; i < n; i++) {
            if (rem_bt[i] > 0) {
                done = 0;

                if (rem_bt[i] > tq) {
                    t += tq;
                    rem_bt[i] -= tq;
                } else {
                    t += rem_bt[i];
                    wt[i] = t - bt[i];
                    rem_bt[i] = 0;
                }
            }
        }

        if (done == 1)  // All processes completed
            break;
    }

    // Turnaround time
    for (i = 0; i < n; i++) {
        tat[i] = bt[i] + wt[i];
    }

    printf("\nProcess\tBT\tWT\tTAT\n");
    int totalWT = 0, totalTAT = 0;

    for (i = 0; i < n; i++) {
        printf("P%d\t%d\t%d\t%d\n", i + 1, bt[i], wt[i], tat[i]);
        totalWT += wt[i];
        totalTAT += tat[i];
    }

    printf("\nAverage Waiting Time = %.2f", (float)totalWT / n);
    printf("\nAverage Turnaround Time = %.2f\n", (float)totalTAT / n);

    return 0;
}


Result

Thus, the Priority Scheduling and Round Robin Scheduling algorithms have been implemented, executed successfully, and verified.
