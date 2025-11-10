Mutual Exclusion using Semaphores & Reader–Writer Problem

AIM

To demonstrate mutual exclusion, process synchronization, and the reader–writer solution using:

-System V Semaphores
-POSIX Semaphores
-Threads (pthread) and Mutex Locks

DESCRIPTION

A semaphore is a synchronization primitive used to protect a critical section shared among multiple processes or threads.
Semaphores ensure that only one entity can access the shared resource at a time, thus maintaining data consistency.

System V Semaphore Overview

Include these headers:

#include <sys/ipc.h>
#include <sys/sem.h>
#include <sys/types.h>

Important System Calls
| Function   | Description                                 |
| ---------- | ------------------------------------------- |
| `semget()` | Creates a semaphore set                     |
| `semop()`  | Performs semaphore operations (wait/signal) |
| `semctl()` | Controls semaphore values                   |
| `fork()`   | Used to create a child process              |

Q1: Mutual Exclusion using System V Semaphore
#include <sys/ipc.h>
#include <sys/sem.h>
#include <sys/types.h>
#include <stdio.h>
#include <unistd.h>

int main() {
    int pid, semid, val;
    struct sembuf sop;
    semid = semget((key_t)6, 1, IPC_CREAT | 0666);
    pid = fork();
    sop.sem_num = 0;
    sop.sem_op = 0;
    sop.sem_flg = 0;

    if (pid != 0) {
        sleep(1);
        printf("The Parent waits for WAIT signal\n");
        semop(semid, &sop, 1);
        printf("The Parent WAKED UP & doing her job\n");
        sleep(10);
        printf("Parent Over\n");
    } else {
        printf("The Child sets WAIT signal & doing her job\n");
        semctl(semid, 0, SETVAL, 1);
        sleep(10);
        printf("The Child sets WAKE signal & finished her job\n");
        semctl(semid, 0, SETVAL, 0);
        printf("Child Over\n");
    }
    return 0;
}

Sample Output
The Child sets WAIT signal & doing her job
The Parent waits for WAIT signal
The Child sets WAKE signal & finished her job
Child Over
The Parent WAKED UP & doing her job
Parent Over


Explanation:

The child process locks the semaphore (WAIT signal).

The parent process waits until the semaphore is released (WAKE signal).

Demonstrates mutual exclusion between parent and child processes.


Q2: POSIX Semaphore with Threads (Increment/Decrement Shared Variable)
Code
#include <pthread.h>
#include <stdio.h>
#include <semaphore.h>
#include <unistd.h>

void *fun1();
void *fun2();

int shared = 1; // shared variable
sem_t s;        // semaphore variable

int main() {
    sem_init(&s, 0, 1); // initialize semaphore
    pthread_t thread1, thread2;

    pthread_create(&thread1, NULL, fun1, NULL);
    sleep(1);
    pthread_create(&thread2, NULL, fun2, NULL);

    pthread_join(thread1, NULL);
    pthread_join(thread2, NULL);

    printf("Final value of shared is %d\n", shared);
    sem_destroy(&s);
}

void *fun1() {
    int x;
    sem_wait(&s); // wait operation
    x = shared;
    printf("Thread1 reads the value as %d\n", x);
    x++;
    printf("Local updation by Thread1: %d\n", x);
    sleep(1);
    shared = x;
    printf("Value of shared variable updated by Thread1 is: %d\n", shared);
    sem_post(&s); // signal operation
    pthread_exit(NULL);
}

void *fun2() {
    int y;
    sem_wait(&s); // wait operation
    y = shared;
    printf("Thread2 reads the value as %d\n", y);
    y--;
    printf("Local updation by Thread2: %d\n", y);
    sleep(1);
    shared = y;
    printf("Value of shared variable updated by Thread2 is: %d\n", shared);
    sem_post(&s);
    pthread_exit(NULL);
}

Sample Output
Thread1 reads the value as 1
Local updation by Thread1: 2
Value of shared variable updated by Thread1 is: 2
Thread2 reads the value as 2
Local updation by Thread2: 1
Value of shared variable updated by Thread2 is: 1
Final value of shared is 1

Explanation:

The semaphore ensures only one thread enters the critical section at a time.

Both threads safely modify the shared variable without conflicts.

The final shared value remains consistent (1).

Q3: Reader–Writer Problem using Semaphores
Code
#include <pthread.h>
#include <semaphore.h>
#include <stdio.h>

sem_t wrt;
pthread_mutex_t mutex;
int cnt = 1;
int numreader = 0;

void *writer(void *wno) {
    sem_wait(&wrt);
    cnt = cnt * 2;
    printf("Writer %d modified cnt to %d\n", *((int *)wno), cnt);
    sem_post(&wrt);
    pthread_exit(NULL);
}

void *reader(void *rno) {
    pthread_mutex_lock(&mutex);
    numreader++;
    if (numreader == 1)
        sem_wait(&wrt); // first reader blocks writers
    pthread_mutex_unlock(&mutex);

    printf("Reader %d: read cnt as %d\n", *((int *)rno), cnt);

    pthread_mutex_lock(&mutex);
    numreader--;
    if (numreader == 0)
        sem_post(&wrt); // last reader unblocks writers
    pthread_mutex_unlock(&mutex);

    pthread_exit(NULL);
}

int main() {
    pthread_t read[10], write[5];
    pthread_mutex_init(&mutex, NULL);
    sem_init(&wrt, 0, 1);
    int a[10] = {1,2,3,4,5,6,7,8,9,10};

    for (int i = 0; i < 10; i++)
        pthread_create(&read[i], NULL, reader, &a[i]);

    for (int i = 0; i < 5; i++)
        pthread_create(&write[i], NULL, writer, &a[i]);

    for (int i = 0; i < 10; i++)
        pthread_join(read[i], NULL);
    for (int i = 0; i < 5; i++)
        pthread_join(write[i], NULL);

    pthread_mutex_destroy(&mutex);
    sem_destroy(&wrt);
    return 0;
}

Sample Output
Reader 1: read cnt as 1
Reader 2: read cnt as 1
Reader 3: read cnt as 1
Reader 4: read cnt as 1
Reader 5: read cnt as 1
Writer 1 modified cnt to 2
Reader 6: read cnt as 2
Reader 7: read cnt as 2
Writer 2 modified cnt to 4
Reader 8: read cnt as 4
Writer 3 modified cnt to 8
Writer 4 modified cnt to 16
Writer 5 modified cnt to 32


Explanation:

Readers can access data concurrently, as long as no writer is active.

Writers get exclusive access, ensuring no data inconsistency.

Uses both mutex locks (for reader count) and semaphores (for write access).

Concepts Demonstrated

Mutual exclusion using semaphores

Synchronization among threads/processes

POSIX semaphores in multithreading

Classic Reader–Writer problem solution

---

Conclusion

This experiment successfully demonstrates process and thread synchronization using both System V and POSIX semaphores. It highlights the use of semaphores and mutexes to enforce mutual exclusion, prevent race conditions, and solve classic concurrency problems like the Reader–Writer scenario.
