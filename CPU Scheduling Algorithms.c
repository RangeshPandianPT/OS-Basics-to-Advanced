CPU Scheduling Algorithms – FCFS and SJF

Aim

To demonstrate the working of FCFS and SJF (Non-preemptive) CPU Scheduling algorithms by calculating Waiting Time and Turnaround Time for given processes.

1. FCFS (First Come First Serve) Scheduling Algorithm
Description

First Come First Serve (FCFS) is the simplest CPU scheduling algorithm.
Processes are executed in the order they arrive in the ready queue.
Here, we assume that all processes have arrival time = 0.

Definitions

Turnaround Time = Completion Time – Arrival Time

Waiting Time = Turnaround Time – Burst Time

Algorithm

Input the number of processes and their Burst Times (BT).

Waiting Time for the first process is 0.

For each process i:
wt[i] = bt[i-1] + wt[i-1]

Turnaround Time for each process:
tat[i] = wt[i] + bt[i]

Compute average WT and average TAT.

Display results.


Q1. C Program – FCFS Scheduling
#include <stdio.h>

int main() {
    int n, i;
    printf("Enter number of processes: ");
    scanf("%d", &n);

    int bt[n], wt[n], tat[n];

    printf("Enter burst time for each process:\n");
    for (i = 0; i < n; i++) {
        printf("P%d: ", i + 1);
        scanf("%d", &bt[i]);
    }

    // Waiting time for first process
    wt[0] = 0;

    // Calculating waiting times
    for (i = 1; i < n; i++) {
        wt[i] = bt[i - 1] + wt[i - 1];
    }

    // Calculating turnaround times
    for (i = 0; i < n; i++) {
        tat[i] = wt[i] + bt[i];
    }

    // Displaying results
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



2. Shortest Job First (SJF) – Non-Preemptive Scheduling

Description

SJF selects the process with the smallest burst time next.
This reduces waiting time and improves throughput.

Algorithm

Accept the number of processes.

Input burst time and assign process ID.

Sort processes in ascending order of burst time.

Waiting time for first process = 0.

For each process i:

wt[i] = wt[i-1] + bt[i-1]

tat[i] = wt[i] + bt[i]

Calculate average WT and TAT.

Display results.


Q2. C Program – SJF (Non-preemptive)
#include <stdio.h>

int main() {
    int n, i, j;
    printf("Enter number of processes: ");
    scanf("%d", &n);

    int bt[n], wt[n], tat[n], pid[n];

    printf("Enter burst time for each process:\n");
    for (i = 0; i < n; i++) {
        pid[i] = i + 1;
        printf("P%d: ", i + 1);
        scanf("%d", &bt[i]);
    }

    // Sorting based on burst time (Simple Bubble Sort)
    for (i = 0; i < n - 1; i++) {
        for (j = 0; j < n - i - 1; j++) {
            if (bt[j] > bt[j + 1]) {
                int temp = bt[j];
                bt[j] = bt[j + 1];
                bt[j + 1] = temp;

                temp = pid[j];
                pid[j] = pid[j + 1];
                pid[j + 1] = temp;
            }
        }
    }

    // First process
    wt[0] = 0;

    // Waiting times
    for (i = 1; i < n; i++) {
        wt[i] = wt[i - 1] + bt[i - 1];
    }

    // Turnaround times
    for (i = 0; i < n; i++) {
        tat[i] = wt[i] + bt[i];
    }

    // Print results
    printf("\nProcess\tBT\tWT\tTAT\n");
    int totalWT = 0, totalTAT = 0;

    for (i = 0; i < n; i++) {
        printf("P%d\t%d\t%d\t%d\n", pid[i], bt[i], wt[i], tat[i]);
        totalWT += wt[i];
        totalTAT += tat[i];
    }

    printf("\nAverage Waiting Time = %.2f", (float)totalWT / n);
    printf("\nAverage Turnaround Time = %.2f\n", (float)totalTAT / n);

    return 0;
}
