Process Creation in C using fork(), getpid(), getppid(), and wait()

AIM

To create processes using the fork() system call and understand the usage of functions such as getpid(), getppid(), and wait() for process synchronization and management.

PROCEDURE
Compilation and Execution Steps

Open Terminal and Create Program

nano test.c


Compile the Program

gcc test.c


Output file → a.out
or use a custom name:

gcc -o test test.c


Execute the Program

./a.out


or

./test

Key Functions Used
| Function        | Description                                                                                      |
| --------------- | ------------------------------------------------------------------------------------------------ |
| `int fork()`    | Creates a new process. Returns 0 in the child process and the child’s PID in the parent process. |
| `int getpid()`  | Returns the process ID of the current process.                                                   |
| `int getppid()` | Returns the parent process ID.                                                                   |
| `int wait()`    | Makes a parent process wait for the child process to complete execution.                         |
| `vfork()`       | Similar to `fork()`, but both processes share the same address space temporarily.                |


Experiments
Q1: Process Creation using fork()
#include <stdio.h>
#include <unistd.h>

int main() {
    int a = 5, b = 10, pid;
    printf("Before fork a=%d b=%d \n", a, b);
    pid = fork();
    if (pid == 0) {
        a = a + 1;
        b = b + 1;
        printf("In child a=%d b=%d \n", a, b);
    } else {
        sleep(1);
        a = a - 1;
        b = b - 1;
        printf("In Parent a=%d b=%d \n", a, b);
    }
    return 0;
}

Q2: Program using vfork()
#include <stdio.h>
#include <unistd.h>

int main() {
    int a = 5, b = 10, pid;
    printf("Before vfork a=%d b=%d \n", a, b);
    pid = vfork();
    if (pid == 0) {
        a = a + 1;
        b = b + 1;
        printf("In child a=%d b=%d \n", a, b);
    } else {
        sleep(1);
        a = a - 1;
        b = b - 1;
        printf("In Parent a=%d b=%d \n", a, b);
    }
    return 0;
}

Q3: Counting “SRMIST” prints using multiple forks
#include <stdio.h>
#include <unistd.h>

int main() {
    fork();
    fork();
    fork();
    printf("SRMIST\n");
    return 0;
}

Q4: Parent–Child Synchronization with Odd and Even Sums
#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>

int main() {
    int pid, n, oddsum = 0, evensum = 0;
    printf("Enter the value of n: ");
    scanf("%d", &n);

    pid = fork();

    if (pid == 0) {
        // Child process
        for (int i = 1; i <= n; i += 2)
            oddsum += i;
        printf("Sum of odd numbers: %d\n", oddsum);
    } else {
        wait(NULL);  // Wait for child
        for (int i = 2; i <= n; i += 2)
            evensum += i;
        printf("Sum of even numbers: %d\n", evensum);
    }
    return 0;
}

Q5: Counting Child Processes in a Loop
#include <stdio.h>
#include <unistd.h>

int main() {
    int i, n = 3;
    for (i = 0; i < n; i++)
        fork();
    return 0;
}

Q6: Display Process IDs
#include <stdio.h>
#include <unistd.h>

int main() {
    int pid = fork();

    if (pid == 0) {
        printf("In Child Process\n");
        printf("Parent Process ID: %d\n", getppid());
        printf("Child Process ID: %d\n", getpid());
    } else {
        printf("In Parent Process\n");
        printf("Parent Process ID: %d\n", getppid());
        printf("Child Process ID: %d\n", pid);
    }

    return 0;
}

Q7: Complex Fork Expression
#include <stdio.h>
#include <unistd.h>

int main() {
    fork();
    fork() && fork() || fork();
    fork();
    printf("Yes ");
    return 0;
}

Concepts Covered

-Process creation using fork()
-Process hierarchy (parent-child relationships)
-Process synchronization using wait()
-Process identification (getpid(), getppid())
-Shared address space using vfork()
-Exponential process creation via multiple forks
-Understanding process trees and PID values