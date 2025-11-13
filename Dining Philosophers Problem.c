Dining Philosophers Problem — Concept

The Dining Philosophers Problem is a classic synchronization and concurrency problem introduced by Edsger Dijkstra. It models the challenges of allocating limited resources among multiple processes without causing deadlock, starvation, or race conditions.

This problem is widely used to understand how modern operating systems handle shared resources in parallel environments.

Problem Overview

There are five philosophers sitting around a circular table.

Each philosopher repeatedly thinks and eats.

To eat, a philosopher needs two chopsticks:

One on their left

One on their right

There are five chopsticks placed between them.

A philosopher can only use a chopstick if it is not currently held by another philosopher.

The Real Challenge

If all philosophers pick up their left chopstick at the same time, none of them can pick up the right one →
This leads to deadlock, where all processes wait forever.

Thus, the problem focuses on designing a solution that ensures:

No Deadlock
No Starvation (everyone eventually eats)
Mutual Exclusion (no double use of chopsticks)
Proper Synchronization
Why It Is Important

The Dining Philosophers Problem represents real OS challenges, such as:

Sharing limited resources (printers, memory, CPU)

Avoiding circular waits

Ensuring fairness between processes

Preventing deadlocks and starvation in multi-threaded systems

It helps students understand how threads and semaphores can be used to control concurrent access to shared resources.

Typical Solution Strategy

To prevent deadlock, one common solution is:

Allow only 4 philosophers to pick chopsticks simultaneously

(using a semaphore called room)

This breaks circular wait and ensures at least one philosopher always completes eating and releases chopsticks.

Each chopstick is a binary semaphore

Only one philosopher can hold it at a time.

Summary

The Dining Philosophers Problem teaches:

How concurrency issues arise

How to use semaphores for synchronization

How operating systems prevent deadlocks

How to allocate shared resources safely


Code in C:

Dining Philosophers Problem (Using Semaphores)
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <semaphore.h>
#include <unistd.h>

sem_t room;
sem_t chopstick[5];

void eat(int phil) {
    printf("Philosopher %d is eating\n", phil);
    sleep(2); // simulate eating
}

void *philosopher(void *num) {
    int phil = *(int *)num;

    printf("Philosopher %d is thinking\n", phil);
    sleep(1);   // simulate thinking

    sem_wait(&room);   // allow only 4 philosophers inside the room

    // Pick up left chopstick
    sem_wait(&chopstick[phil]);
    printf("Philosopher %d picked up left chopstick\n", phil);

    // Pick up right chopstick
    sem_wait(&chopstick[(phil + 1) % 5]);
    printf("Philosopher %d picked up right chopstick\n", phil);

    // Eat
    eat(phil);

    // Put down right chopstick
    sem_post(&chopstick[(phil + 1) % 5]);
    printf("Philosopher %d put down right chopstick\n", phil);

    // Put down left chopstick
    sem_post(&chopstick[phil]);
    printf("Philosopher %d put down left chopstick\n", phil);

    sem_post(&room);  // philosopher leaves the room

    return NULL;
}

int main() {
    int i, a[5];
    pthread_t tid[5];

    sem_init(&room, 0, 4); // allow 4 philosophers at a time

    for (i = 0; i < 5; i++)
        sem_init(&chopstick[i], 0, 1);

    // create philosopher threads
    for (i = 0; i < 5; i++) {
        a[i] = i;
        pthread_create(&tid[i], NULL, philosopher, (void *)&a[i]);
    }

    // wait for threads
    for (i = 0; i < 5; i++)
        pthread_join(tid[i], NULL);

    return 0;
}

Output:

Philosopher 0 is thinking
Philosopher 1 is thinking
Philosopher 2 is thinking
Philosopher 3 is thinking
Philosopher 4 is thinking

Philosopher 0 picked up left chopstick
Philosopher 0 picked up right chopstick
Philosopher 0 is eating

Philosopher 1 picked up left chopstick
Philosopher 1 picked up right chopstick
Philosopher 1 is eating

Philosopher 0 put down right chopstick
Philosopher 0 put down left chopstick

Philosopher 2 picked up left chopstick
Philosopher 2 picked up right chopstick
Philosopher 2 is eating

Philosopher 1 put down right chopstick
Philosopher 1 put down left chopstick

Philosopher 3 picked up left chopstick
Philosopher 3 picked up right chopstick
Philosopher 3 is eating

Philosopher 2 put down right chopstick
Philosopher 2 put down left chopstick

Philosopher 4 picked up left chopstick
Philosopher 4 picked up right chopstick
Philosopher 4 is eating

Philosopher 3 put down right chopstick
Philosopher 3 put down left chopstick

Philosopher 4 put down right chopstick
Philosopher 4 put down left chopstick
