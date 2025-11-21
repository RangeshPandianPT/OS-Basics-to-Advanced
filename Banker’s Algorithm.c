Banker’s Algorithm – Deadlock Avoidance (C Program)

Aim

To simulate the Banker’s Algorithm for deadlock avoidance by checking whether a given state is safe and handling dynamic resource requests safely.

Description

Deadlock occurs when two or more processes are waiting indefinitely for resources held by each other.

Banker's Algorithm prevents deadlock by checking safety whenever resources are requested.

Key Concepts:

Each process declares its maximum resource need.

Before allocating requested resources, the OS verifies:

Is the request valid?

Does the system remain in a safe state after allocation?

Data Structures
| Structure                       | Meaning                                        |
| ------------------------------- | ---------------------------------------------- |
| `n`                             | Number of processes                            |
| `m`                             | Number of resource types                       |
| `Available[m]`                  | Instances of each resource currently available |
| `Max[n][m]`                     | Maximum possible demand of each process        |
| `Allocation[n][m]`              | Currently allocated resources                  |
| `Need[n][m] = Max - Allocation` | Remaining resource needs                       |


Safety Algorithm

Initialize Work = Available, Finish = false for all processes.

Find a process Pi such that:

Finish[i] == false

Need[i] <= Work

Pretend Pi finishes and releases resources:

Work = Work + Allocation[i]

Finish[i] = true

If all processes finish → System is Safe
Else → System Unsafe

Resource Request Algorithm

When Pi makes a request Request[i]:

Check Request[i] <= Need[i]

Check Request[i] <= Available

Pretend to allocate:

Available -= Request

Allocation += Request

Need -= Request

If resulting state is safe → grant request
Otherwise → rollback and force process to wait



C Program – Banker's Algorithm
#include <stdio.h>
#include <stdbool.h>

bool need_leq_work(int Need[], int Work[], int m) {
    for (int j = 0; j < m; ++j)
        if (Need[j] > Work[j]) return false;
    return true;
}

bool isSafe(int Available[], int Allocation[][50], int Need[][50],
            int n, int m, int safeSeq[]) {

    int Work[50], Finish[50], count = 0;

    for (int j = 0; j < m; ++j) Work[j] = Available[j];
    for (int i = 0; i < n; ++i) Finish[i] = false;

    while (count < n) {
        bool found = false;

        for (int i = 0; i < n; ++i) {
            if (!Finish[i] && need_leq_work(Need[i], Work, m)) {
                for (int j = 0; j < m; ++j)
                    Work[j] += Allocation[i][j];

                safeSeq[count++] = i;
                Finish[i] = true;
                found = true;
            }
        }

        if (!found) break;
    }

    for (int i = 0; i < n; ++i)
        if (!Finish[i]) return false;

    return true;
}

bool requestResources(int pid, int Request[], int Available[],
                      int Allocation[][50], int Need[][50], int n, int m) {

    for (int j = 0; j < m; ++j) {
        if (Request[j] > Need[pid][j]) {
            printf("Error: Process exceeded maximum claim.\n");
            return false;
        }
        if (Request[j] > Available[j]) {
            printf("Resources unavailable, Process must wait.\n");
            return false;
        }
    }

    for (int j = 0; j < m; ++j) {
        Available[j] -= Request[j];
        Allocation[pid][j] += Request[j];
        Need[pid][j] -= Request[j];
    }

    int safeSeq[50];
    if (isSafe(Available, Allocation, Need, n, m, safeSeq)) {
        printf("Request granted. Safe sequence: ");
        for (int i = 0; i < n; ++i)
            printf("P%d ", safeSeq[i]);
        printf("\n");
        return true;
    } else {
        for (int j = 0; j < m; ++j) {
            Available[j] += Request[j];
            Allocation[pid][j] -= Request[j];
            Need[pid][j] += Request[j];
        }
        printf("Unsafe state! Request denied.\n");
        return false;
    }
}

int main() {
    int n, m;
    printf("Enter number of processes: ");
    scanf("%d", &n);
    printf("Enter number of resource types: ");
    scanf("%d", &m);

    int Available[50], Max[50][50], Allocation[50][50], Need[50][50];

    printf("\nEnter Available resources:\n");
    for (int j = 0; j < m; ++j) scanf("%d", &Available[j]);

    printf("\nEnter Max matrix:\n");
    for (int i = 0; i < n; ++i)
        for (int j = 0; j < m; ++j)
            scanf("%d", &Max[i][j]);

    printf("\nEnter Allocation matrix:\n");
    for (int i = 0; i < n; ++i)
        for (int j = 0; j < m; ++j)
            scanf("%d", &Allocation[i][j]);

    for (int i = 0; i < n; ++i)
        for (int j = 0; j < m; ++j)
            Need[i][j] = Max[i][j] - Allocation[i][j];

    int safeSeq[50];
    if (isSafe(Available, Allocation, Need, n, m, safeSeq)) {
        printf("\nSystem is SAFE.\nSafe sequence: ");
        for (int i = 0; i < n; ++i) printf("P%d ", safeSeq[i]);
        printf("\n");
    } else {
        printf("\nSystem is UNSAFE.\n");
    }

    return 0;
}


Result

Thus, the program successfully simulates the Banker’s Algorithm and verifies safe/unsafe system states.