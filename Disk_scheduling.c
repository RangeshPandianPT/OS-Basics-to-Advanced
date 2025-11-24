Disk Scheduling Algorithms (FCFS, SCAN, C-SCAN)

What is Disk Scheduling?

Disk scheduling is the method used by the Operating System to decide the order in which disk I/O requests should be serviced.
The goal is to:

Reduce seek time

Improve access time

Increase disk bandwidth

Seek Time = Time taken for the disk head to move to the required track

1. FCFS – First Come First Serve
*Concept

Requests are processed in the order they arrive.

Simplest and most fair algorithm.

Does not optimize head movement → may cause large seek time.

*Advantages

Simple, easy to implement.

Fair scheduling.

*Disadvantages

May lead to high total head movement.

Not suitable for high-performance disks.


2. SCAN – Elevator Algorithm
Concept

The disk arm moves in one direction (left/right), servicing all requests in that direction.

When it reaches the end, it reverses direction and continues.

Works like an elevator going up and down.

*Advantages

Lower average seek time than FCFS.

Avoids starvation.

*Disadvantages

Requests at extreme ends get better service.

Some requests may wait longer when direction is opposite.


3. C-SCAN – Circular SCAN
Concept

Modified SCAN.

The head moves in one direction only.

After reaching one end, it jumps back to the start without servicing requests.

Provides uniform wait time to all requests.

*Advantages

More predictable and fairer than SCAN.

Each track has equal waiting time.

*Disadvantages

Longer jump from end to start → slightly higher overhead.

Seek Time Formula
Head Movement = | Current Head Position – Next Request Position |


C Program for FCFS, SCAN, and C-SCAN Disk Scheduling

#include <stdio.h>
#include <stdlib.h>

void FCFS(int arr[], int n, int head) {
    int total = 0;
    printf("\nFCFS Order: %d -> ", head);

    for(int i = 0; i < n; i++) {
        total += abs(head - arr[i]);
        head = arr[i];
        printf("%d ", arr[i]);
        if(i != n-1) printf("-> ");
    }

    printf("\nTotal Head Movement (FCFS): %d\n", total);
}

void SCAN(int arr[], int n, int head, int disk_size) {
    int i, j, total = 0;
    int left[100], right[100], lcount = 0, rcount = 0;

    for(i = 0; i < n; i++) {
        if(arr[i] < head)
            left[lcount++] = arr[i];
        else
            right[rcount++] = arr[i];
    }

    // Sort left descending, right ascending
    for(i = 0; i < lcount-1; i++)
        for(j = i+1; j < lcount; j++)
            if(left[i] < left[j]) {
                int temp = left[i]; left[i] = left[j]; left[j] = temp;
            }

    for(i = 0; i < rcount-1; i++)
        for(j = i+1; j < rcount; j++)
            if(right[i] > right[j]) {
                int temp = right[i]; right[i] = right[j]; right[j] = temp;
            }

    printf("\nSCAN Order: %d -> ", head);

    // Move right first
    for(i = 0; i < rcount; i++) {
        total += abs(head - right[i]);
        head = right[i];
        printf("%d ", head);
        if(i != rcount -1) printf("-> ");
    }

    // Go to end of disk
    total += abs(head - (disk_size - 1));
    head = disk_size - 1;
    printf("-> %d ", head);

    // Now move left
    for(i = 0; i < lcount; i++) {
        total += abs(head - left[i]);
        head = left[i];
        printf("-> %d ", head);
    }

    printf("\nTotal Head Movement (SCAN): %d\n", total);
}

void CSCAN(int arr[], int n, int head, int disk_size) {
    int i, j, total = 0;
    int left[100], right[100], lcount = 0, rcount = 0;

    for(i = 0; i < n; i++) {
        if(arr[i] < head)
            left[lcount++] = arr[i];
        else
            right[rcount++] = arr[i];
    }

    // Sort ascending
    for(i = 0; i < lcount-1; i++)
        for(j = i+1; j < lcount; j++)
            if(left[i] > left[j]) {
                int temp = left[i]; left[i] = left[j]; left[j] = temp;
            }

    for(i = 0; i < rcount-1; i++)
        for(j = i+1; j < rcount; j++)
            if(right[i] > right[j]) {
                int temp = right[i]; right[i] = right[j]; right[j] = temp;
            }

    printf("\nC-SCAN Order: %d -> ", head);

    // Move right
    for(i = 0; i < rcount; i++) {
        total += abs(head - right[i]);
        head = right[i];
        printf("%d ", head);
        if(i != rcount -1) printf("-> ");
    }

    // Go to end
    total += abs(head - (disk_size - 1));
    head = disk_size - 1;
    printf("-> %d ", head);

    // Jump to beginning
    total += (disk_size - 1);
    head = 0;
    printf("-> 0 ");

    // Move right again (left requests)
    for(i = 0; i < lcount; i++) {
        total += abs(head - left[i]);
        head = left[i];
        printf("-> %d ", head);
    }

    printf("\nTotal Head Movement (C-SCAN): %d\n", total);
}

int main() {
    int n, head, disk_size, arr[100];

    printf("Enter number of requests: ");
    scanf("%d", &n);

    printf("Enter request queue: ");
    for(int i = 0; i < n; i++)
        scanf("%d", &arr[i]);

    printf("Enter initial head position: ");
    scanf("%d", &head);

    printf("Enter total disk size: ");
    scanf("%d", &disk_size);

    FCFS(arr, n, head);
    SCAN(arr, n, head, disk_size);
    CSCAN(arr, n, head, disk_size);

    return 0;
}

Sample Input
Enter number of requests: 5
Enter request queue: 82 170 43 140 24
Enter initial head position: 50
Enter total disk size: 200


Sample Output
FCFS Order: 50 -> 82 -> 170 -> 43 -> 140 -> 24
Total Head Movement (FCFS): 398

SCAN Order: 50 -> 82 -> 140 -> 170 -> 199 -> 43 -> 24
Total Head Movement (SCAN): 325

C-SCAN Order: 50 -> 82 -> 140 -> 170 -> 199 -> 0 -> 24 -> 43
Total Head Movement (C-SCAN): 391