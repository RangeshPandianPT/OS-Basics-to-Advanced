Page Replacement Algorithms
FIFO – LRU – LFU

Aim

To implement and compare three commonly used page replacement algorithms:

FIFO (First-In First-Out)

LRU (Least Recently Used)

LFU (Least Frequently Used)

Description

Virtual memory allows processes to use more memory than what is physically available. When memory frames are full and a new page needs to be loaded, the OS must decide which page to remove.
Page replacement algorithms choose the page to evict to minimize page faults.

*FIFO (First-In, First-Out)

Uses a queue structure

Oldest loaded page is removed first

Simple but not always efficient

*LRU (Least Recently Used)

Replaces the page that has not been used for the longest time

Based on recent usage history

Produces fewer faults than FIFO

*LFU (Least Frequently Used)

Evicts the page with the lowest access count

If tie → the oldest among them is removed

Tracks page-reference frequency


C Program — FIFO, LRU, LFU Page Replacement

#include <stdio.h>

int search(int key, int frame[], int f) {
    for (int i = 0; i < f; i++)
        if (frame[i] == key)
            return i;
    return -1;
}

void FIFO(int pages[], int n, int f) {
    int frame[10], index = 0, faults = 0;

    for (int i = 0; i < f; i++)
        frame[i] = -1;

    printf("\nFIFO Page Replacement:\n");

    for (int i = 0; i < n; i++) {
        if (search(pages[i], frame, f) == -1) {
            frame[index] = pages[i];
            index = (index + 1) % f;
            faults++;
        }
        printf("After page %d --> ", pages[i]);
        for (int j = 0; j < f; j++)
            printf("%d ", frame[j]);
        printf("\n");
    }

    printf("Total Page Faults (FIFO): %d\n", faults);
}

void LRU(int pages[], int n, int f) {
    int frame[10], used[10], time = 0, faults = 0;

    for (int i = 0; i < f; i++)
        frame[i] = -1;

    printf("\nLRU Page Replacement:\n");

    for (int i = 0; i < n; i++) {
        int pos = search(pages[i], frame, f);

        if (pos == -1) {
            int min = 999, replace = -1;
            for (int j = 0; j < f; j++) {
                if (used[j] < min) {
                    min = used[j];
                    replace = j;
                }
            }
            frame[replace] = pages[i];
            faults++;
            used[replace] = ++time;
        } else {
            used[pos] = ++time;
        }

        printf("After page %d --> ", pages[i]);
        for (int j = 0; j < f; j++)
            printf("%d ", frame[j]);
        printf("\n");
    }

    printf("Total Page Faults (LRU): %d\n", faults);
}

void LFU(int pages[], int n, int f) {
    int frame[10], freq[10], age[10];
    int faults = 0, timer = 0;

    for (int i = 0; i < f; i++) {
        frame[i] = -1;
        freq[i] = 0;
        age[i] = 0;
    }

    printf("\nLFU Page Replacement:\n");

    for (int i = 0; i < n; i++) {
        timer++;
        int pos = search(pages[i], frame, f);

        if (pos != -1) {
            freq[pos]++;
            age[pos] = timer;
        } else {
            int minFreq = 999, replace = -1;

            for (int j = 0; j < f; j++) {
                if (frame[j] == -1) {
                    replace = j;
                    break;
                }
                if (freq[j] < minFreq || (freq[j] == minFreq && age[j] < age[replace])) {
                    minFreq = freq[j];
                    replace = j;
                }
            }

            frame[replace] = pages[i];
            freq[replace] = 1;
            age[replace] = timer;
            faults++;
        }

        printf("After page %d --> ", pages[i]);
        for (int j = 0; j < f; j++)
            printf("%d ", frame[j]);
        printf("\n");
    }

    printf("Total Page Faults (LFU): %d\n", faults);
}

int main() {
    int n, f;

    printf("Enter number of pages: ");
    scanf("%d", &n);

    int pages[n];
    printf("Enter page reference string:\n");
    for (int i = 0; i < n; i++)
        scanf("%d", &pages[i]);

    printf("Enter number of frames: ");
    scanf("%d", &f);

    FIFO(pages, n, f);
    LRU(pages, n, f);
    LFU(pages, n, f);

    return 0;
}


Sample Output (Format)
FIFO Page Replacement:
After page 7 → 7 -1 -1
After page 0 → 7 0 -1
After page 1 → 7 0 1
...
Total Page Faults (FIFO): X

Result

Thus, FIFO, LRU, and LFU page replacement algorithms are successfully implemented and tested.
This project clearly demonstrates how different algorithms yield different page faults.