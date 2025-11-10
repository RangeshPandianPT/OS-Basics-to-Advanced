Thread Creation and Management using pthread in C

AIM

To write a C program to demonstrate various thread-related concepts such as creating, executing, and synchronizing multiple threads using the POSIX thread library (pthread).

PROCEDURE
A. Create a New Thread
int pthread_create(pthread_t *thread, const pthread_attr_t *attr,
                   void *(*start_routine)(void *), void *arg);


Parameters:

thread → Pointer to a variable that returns the thread ID of the created thread.

attr → Thread attributes (set to NULL for default).

start_routine → Function pointer executed by the thread (must return void *).

arg → Argument passed to the thread function.

B. Terminate a Thread
void pthread_exit(void *retval);


Used to terminate a thread and optionally return a value.

C. Wait for a Thread to Finish
int pthread_join(pthread_t thread, void **retval);


Makes the calling thread wait for the specified thread to terminate.

D. Get the Current Thread ID
pthread_t pthread_self(void);

E. Compare Two Threads
int pthread_equal(pthread_t t1, pthread_t t2);


Returns non-zero if both thread IDs refer to the same thread.

Question 1: Creating Multiple Threads
Problem Statement

Create three threads:

One to calculate the sum of even numbers and list them

One to calculate the sum of odd numbers and list them

One to calculate the sum of natural numbers

Answer: Completed Program
#include <pthread.h>  /* include suitable header file */
#include <stdio.h>
#define NUM_THREADS 3

int je, jo, evensum = 0, sumn = 0, oddsum = 0, evenarr[50], oddarr[50];

void *Even(void *threadid) {
    int i, n;
    je = 0;
    n = (int)threadid;
    for (i = 1; i <= n; i++) {
        if (i % 2 == 0) {
            evenarr[je] = i;
            evensum = evensum + i;
            je++;
        }
    }
    pthread_exit(NULL);
}

void *Odd(void *threadid) {
    int i, n;
    jo = 0;
    n = (int)threadid;
    for (i = 1; i <= n; i++) {  // start from 1
        if (i % 2 != 0) {       // logic to allow only odd numbers
            oddarr[jo] = i;     // store odd number
            oddsum = oddsum + i; // calculate sum of odd numbers
            jo++;
        }
    }
    pthread_exit(NULL);
}

void *SumN(void *threadid) {
    int i, n;
    n = (int)threadid;
    for (i = 1; i <= n; i++) {
        sumn = sumn + i; // sum of natural numbers
    }
    pthread_exit(NULL);
}

int main() {
    pthread_t threads[NUM_THREADS];
    int i, t;

    printf("Enter a number\n");
    scanf("%d", &t);

    pthread_create(&threads[0], NULL, Even, (void *)t);
    pthread_create(&threads[1], NULL, Odd, (void *)t);
    pthread_create(&threads[2], NULL, SumN, (void *)t);

    for (i = 0; i < NUM_THREADS; i++) {
        pthread_join(threads[i], NULL);
    }

    printf("The sum of first N natural numbers is %d\n", sumn);
    printf("The sum of first N even numbers is %d\n", evensum);
    printf("The sum of first N odd numbers is %d\n", oddsum);

    printf("The first N Even numbers are----\n");
    for (i = 0; i < je; i++)
        printf("%d ", evenarr[i]);
    printf("\n");

    printf("The first N Odd numbers are ----\n");
    for (i = 0; i < jo; i++)
        printf("%d ", oddarr[i]);
    printf("\n");

    pthread_exit(NULL);
}

ample Output
Enter a number
10
The sum of first N natural numbers is 55
The sum of first N even numbers is 30
The sum of first N odd numbers is 25
The first N Even numbers are----
2 4 6 8 10
The first N Odd numbers are ----
1 3 5 7 9

Concepts Covered

Thread creation and execution using pthread_create()

Thread synchronization using pthread_join()

Parallel computation of multiple tasks (odd, even, and natural sums)

Thread-safe termination using pthread_exit()

Use of global variables for sharing data between threads

Conclusion

This experiment demonstrates how to create and manage multiple threads using the POSIX thread library in C. It shows how independent threads can perform computations simultaneously (like finding odd, even, and natural sums) while maintaining proper synchronization using pthread_join().