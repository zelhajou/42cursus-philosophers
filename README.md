![ascii-text-art](https://github.com/zelhajou/Philosophers/assets/39954629/e65a4d3e-10a2-44b6-bf27-f79c71b4f7e6)

# Philosophers Project
## Description
This project simulates a classic problem in computer science, *the dining philosophers problem*. It involves philosophers sitting at a table, doing one of three things: eating, thinking, or sleeping. While eating, they need two forks, which are shared with neighbors.

*The Dining Philosophers problem* is a classic puzzle in computer science, often used to illustrate the challenges of resource allocation and synchronization in concurrent programming. At first glance, it might seem like a quirky thought experiment, but it mirrors real-world scenarios in computing quite closely

<!--
![MOSHED-2024-1-5-16-52-54](https://github.com/zelhajou/Philosophers/assets/39954629/d1660b4a-5adc-44e3-8177-0fffb4ef238a)

<div align="center">
<img width="600" alt="Screen Shot 2024-01-05 at 5 39 38 PM" src="https://github.com/zelhajou/Philosophers/assets/39954629/9b0f1688-34ab-4c6c-b60c-62ea236a0f95">
</div>

![MOSHED-2024-1-26-21-17-8](https://github.com/zelhajou/42-Philosophers/assets/39954629/741244de-ff8f-4d8e-a172-ea819bff1a91)
![MOSHED-2024-1-26-21-4-22](https://github.com/zelhajou/42-Philosophers/assets/39954629/dd21e550-70ef-473f-abab-828f78b68b85)

-->
![MOSHED-2024-1-26-21-17-8](https://github.com/zelhajou/42-Philosophers/assets/39954629/78efd080-7891-44b8-80bc-e3fcfb64d8b3)


## The Basic Setup
Imagine five philosophers who spend their lives just thinking and eating. They sit around a round table with a bowl of spaghetti in front of each of them. Here’s the catch: there are only five forks available, placed between each pair of adjacent philosophers. To eat, a philosopher needs to use two forks – one on their left and one on their right.

## Understanding the Problem
The issue arises when every philosopher picks up the fork on their left at the same time. Each of them is left waiting for the fork on their right to become available. Since everyone is holding one fork, no one has two forks to start eating. This results in a deadlock where all philosophers are stuck waiting indefinitely – a situation we want to avoid in real-world systems.
- [DINING-PHILOSOPHERS PROBLEM: SIMPLIFIED](https://www.youtube.com/watch?v=VSkvwzqo-Pk&ab_channel=ZaynabZakiyah) 📹

## The Scenario 
Imagine a round table with several philosophers (threads) sitting around it. Each philosopher wants to eat (access a critical resource like a fork), but there are only a limited number of forks (resources) available.

<div align="center">
<img width="600" alt="Screen Shot 2024-01-05 at 5 39 38 PM" src="https://github.com/zelhajou/42-Philosophers/assets/39954629/ba9d0d13-ce07-4a27-b043-060bcf3cd0ae">  
</div>

- **Five Philosophers:** They alternate between thinking and eating.
- **Five Forks:** One between each philosopher.
- **The Problem:** To eat, a philosopher needs both forks on either side.

## The Challenge
The catch is simple yet complex. If every philosopher simultaneously picks up the left fork, they all wait for the right fork indefinitely – a *deadlock*. This situation perfectly mimics real-world scenarios in computing where processes wait indefinitely for *resources*, leading to system freezes.

## Why It Matters
Understanding the Dining Philosophers' problem is crucial in computer science because it teaches us about managing resources in multi-threaded or multi-process environments. It's not just about preventing deadlock but also ensuring fair access to resources and preventing starvation (where a process never gets the resources it needs).

## Building the Philosophers
The simulation is done using threads and mutexes. Each philosopher is a thread and forks are represented as mutexes.
- **Define a philosopher thread**: Each philosopher should be a separate thread with its own loop. Each loop iteration should involve several activities:
  - **Thinking**: Simulate thinking time using a sleep function.
  - **Trying to eat**:
    - Check if both its left and right forks are available.
    - If both are available, acquire them (using mutexes or semaphores) and start eating.
    - If not, wait for a while and try again later.
  - **Eating**: Simulate eating time using a sleep function.
  - **Releasing forks**: Release both forks once finished eating.
  - **Sleeping**: Simulate a rest period before thinking again.

## Implementing Synchronization
- **Mutexes**: This is a common approach. Each fork has a mutex associated with it. A philosopher can only acquire both fork mutexes if both are free, preventing another philosopher from grabbing a single fork and causing a deadlock.
- **Semaphores**: You can use semaphores to limit the number of philosophers that can be eating at the same time, ensuring there are always enough forks available.
  - [What is the difference between lock, mutex and semaphore?](https://stackoverflow.com/questions/2332765/what-is-the-difference-between-lock-mutex-and-semaphore)
  - [What is a Semaphore](https://stackoverflow.com/questions/34519/what-is-a-semaphore/40238#40238)
  - [Mutex vs Semaphore](https://www.geeksforgeeks.org/mutex-vs-semaphore/)
## Logging and Testing:
- Implement logging statements to track each philosopher's actions (thinking, eating, sleeping).
- Test your program with different numbers of philosophers and ensure there are no deadlocks or starvation situations.


## External functions
**Mandatory Part**:
<details>
  <summary>
    <code>usleep()</code>
  </summary>
A function is used to introduce a delay in the program for a specified number of microseconds (1 microsecond = 1 millionth of a second).

```c
#include <stdio.h>
#include <unistd.h>

int main() {
    printf("This is before usleep()\n");

    // Introducing a delay of 2 seconds (2000000 microseconds)
    usleep(2000000);

    printf("This is after usleep()\n");

    return 0;
}
```
</details>

<details>
  <summary>
    <code>gettimeofday()</code>
  </summary>
A function is commonly used to get the current time, including microseconds. It takes a pointer to a struct timeval as an argument, and this structure holds the seconds and microseconds components of the current time.

```c
#include <stdio.h>
#include <sys/time.h>

int main() {
    // Declare a struct timeval to store the result
    struct timeval current_time;

    // Get the current time
    gettimeofday(&current_time, NULL);

    // Display the current time in seconds and microseconds
    printf("Seconds: %ld\n", current_time.tv_sec);
    printf("Microseconds: %ld\n", current_time.tv_usec);

    return 0;
}
```
</details>

<details>
  <summary>
    <code>pthread_create()</code>
  </summary>
A function is used to create a new thread. Threads allow a program to execute multiple tasks concurrently, providing a way to improve performance by parallelizing operations.

```c
#include <pthread.h>

int pthread_create(pthread_t *restrict thread, const pthread_attr_t *restrict attr, void *(*start_routine)(void *), void *restrict arg);
```

1. A pointer to a pthread_t variable, which will be used to identify the newly created thread.
2. A pointer to a pthread_attr_t structure specifying thread attributes. You can typically set it to NULL for default attributes.
3. A pointer to the function that will be executed by the new thread.
4. A void pointer that is passed as an argument to the function specified in parameter 3.

```c
#include <stdio.h>
#include <pthread.h>

// Function to be executed by the new thread
void *threadFunction(void *arg) {
    printf("This is the new thread.\n");
    return NULL;
}

int main() {
    pthread_t newThread; // Thread identifier
    int threadCreationStatus;

    // Create a new thread
    threadCreationStatus = pthread_create(&newThread, NULL, threadFunction, NULL);

    if (threadCreationStatus != 0) {
        fprintf(stderr, "Error creating thread: %d\n", threadCreationStatus);
        return 1;
    }

    printf("This is the main thread.\n");

    // Wait for the new thread to finish (optional)
    pthread_join(newThread, NULL);

    return 0;
}
```

</details>

<details>
  <summary>
    <code>pthread_join()</code>
  </summary>
A function used to make a calling thread wait until the specified thread terminates. It allows the calling thread to synchronize its execution with the completion of another thread.

1. The `pthread_t` variable representing the thread to be joined.
2. A pointer to a location where the exit status of the joined thread will be stored.

```c
#include <stdio.h>
#include <pthread.h>

void *threadFunction(void *arg) {
    printf("This is the new thread.\n");
    return (void *)42;
}

int main() {
    pthread_t newThread; // Thread identifier
    int threadCreationStatus;

    // Create a new thread
    threadCreationStatus = pthread_create(&newThread, NULL, threadFunction, NULL);

    if (threadCreationStatus != 0) {
        fprintf(stderr, "Error creating thread: %d\n", threadCreationStatus);
        return 1;
    }

    printf("This is the main thread.\n");

    // Wait for the new thread to finish and retrieve its exit status
    void *threadExitStatus;
    pthread_join(newThread, &threadExitStatus);

    printf("The new thread has finished with exit status: %ld\n", (long)threadExitStatus);

    return 0;
}
```
</details>

<details>
  <summary>
    <code>pthread_detach()</code>
  </summary>
A function  used to mark a thread as detached. A detached thread automatically releases its resources when it exits, without requiring the main thread to join and wait for its completion. 


```c
#include <stdio.h>
#include <pthread.h>
#include <unistd.h>

void *threadFunction(void *arg) {
    printf("This is the detached thread.\n");
    // Simulate some work in the thread
    sleep(2);
    printf("The detached thread is done.\n");
    // No need to explicitly call pthread_exit() in a detached thread
    return NULL;
}

int main() {
    pthread_t detachedThread; // Thread identifier
    int threadCreationStatus;

    // Create a detached thread
    threadCreationStatus = pthread_create(&detachedThread, NULL, threadFunction, NULL);

    if (threadCreationStatus != 0) {
        fprintf(stderr, "Error creating thread: %d\n", threadCreationStatus);
        return 1;
    }

    // Detach the thread
    threadCreationStatus = pthread_detach(detachedThread);

    if (threadCreationStatus != 0) {
        fprintf(stderr, "Error detaching thread: %d\n", threadCreationStatus);
        return 1;
    }

    printf("This is the main thread.\n");

    // Main thread continues its execution without waiting for the detached thread

    // Note: The detached thread cleans up its resources automatically upon termination

    return 0;
}
```
</details>

<details>
  <summary>
    <code>pthread_mutex_init()</code>
  </summary>
A function used to initialize a mutex, which is a synchronization primitive used to protect shared resources from concurrent access by multiple threads.

```c
#include <stdio.h>
#include <pthread.h>

// Shared data protected by the mutex
int sharedData = 0;

// Mutex declaration
pthread_mutex_t myMutex;

void *threadFunction(void *arg) {
    // Lock the mutex before accessing the shared data
    pthread_mutex_lock(&myMutex);

    // Critical section: Access and modify the shared data
    printf("Thread %ld is modifying the shared data.\n", (long)arg);
    sharedData++;
    printf("Thread %ld has finished modifying the shared data.\n", (long)arg);

    // Unlock the mutex after finishing the critical section
    pthread_mutex_unlock(&myMutex);

    return NULL;
}

int main() {
    // Initialize the mutex
    if (pthread_mutex_init(&myMutex, NULL) != 0) {
        fprintf(stderr, "Error initializing mutex.\n");
        return 1;
    }

    pthread_t thread1, thread2;

    // Create two threads
    pthread_create(&thread1, NULL, threadFunction, (void *)1);
    pthread_create(&thread2, NULL, threadFunction, (void *)2);

    // Wait for the threads to finish
    pthread_join(thread1, NULL);
    pthread_join(thread2, NULL);

    // Destroy the mutex after its use is done
    pthread_mutex_destroy(&myMutex);

    printf("Final value of sharedData: %d\n", sharedData);

    return 0;
}
```
</details>

<details>
  <summary>
    <code>pthread_mutex_destroy()</code>
  </summary>
function used to destroy a previously initialized mutex. After a mutex has been successfully destroyed, it cannot be used again unless it is reinitialized using pthread_mutex_init()

```c
#include <stdio.h>
#include <pthread.h>

// Shared data protected by the mutex
int sharedData = 0;

// Mutex declaration
pthread_mutex_t myMutex;

void *threadFunction(void *arg) {
    // Lock the mutex before accessing the shared data
    pthread_mutex_lock(&myMutex);

    // Critical section: Access and modify the shared data
    printf("Thread %ld is modifying the shared data.\n", (long)arg);
    sharedData++;
    printf("Thread %ld has finished modifying the shared data.\n", (long)arg);

    // Unlock the mutex after finishing the critical section
    pthread_mutex_unlock(&myMutex);

    return NULL;
}

int main() {
    // Initialize the mutex
    if (pthread_mutex_init(&myMutex, NULL) != 0) {
        fprintf(stderr, "Error initializing mutex.\n");
        return 1;
    }

    pthread_t thread1, thread2;

    // Create two threads
    pthread_create(&thread1, NULL, threadFunction, (void *)1);
    pthread_create(&thread2, NULL, threadFunction, (void *)2);

    // Wait for the threads to finish
    pthread_join(thread1, NULL);
    pthread_join(thread2, NULL);

    // Destroy the mutex after its use is done
    if (pthread_mutex_destroy(&myMutex) != 0) {
        fprintf(stderr, "Error destroying mutex.\n");
        return 1;
    }

    printf("Final value of sharedData: %d\n", sharedData);

    return 0;
}
```
</details>

<details>
  <summary>
    <code>pthread_mutex_lock()</code>
  </summary>
function used to lock a mutex, providing exclusive access to a critical section of code for the calling thread. If the mutex is already locked by another thread, the calling thread will block until the mutex becomes available

```c
#include <stdio.h>
#include <pthread.h>

// Shared data protected by the mutex
int sharedData = 0;

// Mutex declaration
pthread_mutex_t myMutex;

void *threadFunction(void *arg) {
    // Lock the mutex before accessing the shared data
    pthread_mutex_lock(&myMutex);

    // Critical section: Access and modify the shared data
    printf("Thread %ld is modifying the shared data.\n", (long)arg);
    sharedData++;
    printf("Thread %ld has finished modifying the shared data.\n", (long)arg);

    // Unlock the mutex after finishing the critical section
    pthread_mutex_unlock(&myMutex);

    return NULL;
}

int main() {
    // Initialize the mutex
    if (pthread_mutex_init(&myMutex, NULL) != 0) {
        fprintf(stderr, "Error initializing mutex.\n");
        return 1;
    }

    pthread_t thread1, thread2;

    // Create two threads
    pthread_create(&thread1, NULL, threadFunction, (void *)1);
    pthread_create(&thread2, NULL, threadFunction, (void *)2);

    // Wait for the threads to finish
    pthread_join(thread1, NULL);
    pthread_join(thread2, NULL);

    // Destroy the mutex after its use is done
    if (pthread_mutex_destroy(&myMutex) != 0) {
        fprintf(stderr, "Error destroying mutex.\n");
        return 1;
    }

    printf("Final value of sharedData: %d\n", sharedData);

    return 0;
}
```
</details>

<details>
  <summary>
    <code>pthread_mutex_unlock()</code>
  </summary>
 function in C is used to release the lock on a mutex that was previously acquired using pthread_mutex_lock(). It allows other threads to acquire the mutex and enter the critical section protected by that mutex.

```c
#include <stdio.h>
#include <pthread.h>

// Shared data protected by the mutex
int sharedData = 0;

// Mutex declaration
pthread_mutex_t myMutex;

void *threadFunction(void *arg) {
    // Lock the mutex before accessing the shared data
    pthread_mutex_lock(&myMutex);

    // Critical section: Access and modify the shared data
    printf("Thread %ld is modifying the shared data.\n", (long)arg);
    sharedData++;
    printf("Thread %ld has finished modifying the shared data.\n", (long)arg);

    // Unlock the mutex after finishing the critical section
    pthread_mutex_unlock(&myMutex);

    return NULL;
}

int main() {
    // Initialize the mutex
    if (pthread_mutex_init(&myMutex, NULL) != 0) {
        fprintf(stderr, "Error initializing mutex.\n");
        return 1;
    }

    pthread_t thread1, thread2;

    // Create two threads
    pthread_create(&thread1, NULL, threadFunction, (void *)1);
    pthread_create(&thread2, NULL, threadFunction, (void *)2);

    // Wait for the threads to finish
    pthread_join(thread1, NULL);
    pthread_join(thread2, NULL);

    // Destroy the mutex after its use is done
    if (pthread_mutex_destroy(&myMutex) != 0) {
        fprintf(stderr, "Error destroying mutex.\n");
        return 1;
    }

    printf("Final value of sharedData: %d\n", sharedData);

    return 0;
}
```
</details>


## Explanation

The concept of threads is fundamental to concurrent programming, allowing multiple tasks to execute concurrently within a single process

> [!NOTE]
> Concurrent programming is an advanced programming technique that enables the execution of multiple tasks at the same time. It is a powerful approach for improving the performance and responsiveness of a program, particularly in systems with multiple processor units. In concurrent programming, individual tasks are known as threads or processes, which can run independently, share resources, and interact with each other.

When working with concurrent programming, you need to understand the basic principles and concepts behind this technique. Some key principles include:

- **Parallelism**: Concurrent programs can run multiple processes or threads simultaneously, utilizing multiple processing units available in today's computer systems.
- **Non-determinism**: Due to the unpredictable order of execution, concurrent programs can give different results on different runs, making debugging and testing more complex. Non-determinism arises from the uncertain order in which threads or processes access shared resources and interact with each other.
- **Synchronization**: Concurrent programs use synchronization mechanisms to coordinate access to shared resources and ensure mutually exclusive access or resource protection to prevent data inconsistency and race conditions.

![background-processes](https://github.com/user-attachments/assets/da2b36de-f429-45e7-9446-9266ac1e614f)


### Concurrency Meaning in Programming: A Detailed Overview
- **Processes and threads**: Concurrency is achieved by running multiple tasks in parallel, either as processes or threads. Processes are independent units of execution with their own memory space, while threads belong to a single process and share memory with other threads in that process.
- **Interprocess communication (IPC)**: In concurrent programming, processes may need to exchange data and signals. IPC mechanisms, such as pipes, file-based communication, shared memory, and message-passing systems, facilitate this data exchange between processes.
- **Deadlocks and livelocks**: In some cases, processes or threads become trapped in a state of waiting for access to resources or for other processes or threads to complete, leading to deadlocks and livelocks. These situations can cause the concurrent program to hang or slow down, so it is essential to detect and handle them effectively.

### Concurrency in Multiple Cores
  - [What is the difference between multicore and concurrent programming](https://stackoverflow.com/questions/5372861/what-is-the-difference-between-multicore-and-concurrent-programming)
  - [Concurrency in Multicore systems](https://cs.stackexchange.com/questions/140793/concurrency-in-multiple-core)


### The Details of Threads in Computer Programming:
#### 1. Thread Definition:
- **Definition**: A thread is the smallest unit of execution within a process. It represents an independent sequence of instructions that can be scheduled to run concurrently with other threads in the same process.
- **Characteristics**: Threads within the same process share the same resources, such as memory space and file descriptors.

#### 2. Process vs. Thread:
Processes and threads are the basic building blocks of a computer program. They are the smallest units of execution in a program. A process is an instance of a program that is being executed. A thread is a sequence of instructions within a process that can be executed independently of other code.
- **Process**:
  - An independent program in execution with its own memory space.
  - Processes do not share memory, necessitating inter-process communication mechanisms.
- **Thread**:
  - A lightweight, independent unit of a process with shared resources.
  - Threads share memory, making communication and data sharing more efficient.
  
  ![processes](https://github.com/user-attachments/assets/08007d6f-6bbb-4443-b971-0944ac1c0650)
  ![threads](https://github.com/user-attachments/assets/b0c2adb5-4b58-4541-9c4c-34e2960b7f38)


[Whats the difference between Process and a Thread?](https://www.quora.com/What-is-the-difference-between-a-process-and-a-thread)

#### 3. Creating Threads:
Example :

```c
#include <pthread.h>

void* thread_function(void* arg) {
    // Thread code
}

int main() {
    pthread_t thread;
    pthread_create(&thread, NULL, thread_function, NULL);
    pthread_join(thread, NULL); // Wait for the thread to finish
    return 0;
}
```

#### 4. Thread Lifecycle:

- **Creation**: A thread is created using the `pthread_create` function or an equivalent function in other threading libraries.
- **Running**: The thread starts executing its designated function.
- **Termination**: The thread completes its execution or is explicitly terminated using.
- **Joining**: The main thread or another thread may wait for a thread to finish using `pthread_join`.

#### 5. Thread Synchronization:
- Threads may need to synchronize their execution to avoid **race conditions** and **conflicts**.
- Synchronization mechanisms include **mutexes**, **semaphores**, and **condition variables**.

![mutexes](https://github.com/user-attachments/assets/f21ad45c-be9f-4629-8429-51edfdae133b)


Example :

```c
#include <pthread.h>

pthread_mutex_t mutex = PTHREAD_MUTEX_INITIALIZER;
int shared_data = 0;

void* thread_function(void* arg) {
    pthread_mutex_lock(&mutex);
    // Critical section
    shared_data++;
    pthread_mutex_unlock(&mutex);
    pthread_exit(NULL);
}
```

### Common Pitfalls in Multithreaded

When working with threads, several common issues and pitfalls should be aware of and strive to avoid

- **Race conditions**: Concurrent data access without sync leads to unpredictable behavior. (mutex, locks, semaphores)
- **Deadlocks**: Threads stuck waiting for each other's resources, forever blocked. (lock order, deadlock detection)
- **Priority inversion**: Low-pri thread delays high-pri by holding needed resource. (priority inheritance, ceiling)
- **Data races**: Unprotected shared data access causing unpredictable results. (sync mechanisms, atomic operations)
- **Thread leaks**: Unreleased threads wasting resources and hurting performance. (join/detach properly)
- **Thread starvation**: Some threads never run due to others hogging resources. (fair allocation, avoid long tasks)

## Conclusion
The Dining Philosophers Problem is more than just a puzzle; it's a fundamental concept that helps in understanding complex scenarios in multi-threading and resource sharing in computing. By learning about this problem, one can gain insights into solving real-world issues in system design and process management.

## How to Run
Compile with `make` and run the program as follows:

```bash
./philo [number_of_philosophers] [time_to_die] [time_to_eat] [time_to_sleep] [number_of_times_each_philosopher_must_eat (optional)]
```

## Features
- Argument validation
- Philosopher activities simulation
- Resource management to avoid deadlocks

## Useful Links
- https://www.scaler.com/topics/cpp/concurrent-programming/
- https://www.studysmarter.co.uk/explanations/computer-science/computer-programming/concurrent-programming/
- [Threads, Mutexes and Concurrent Programming in C](https://www.codequoi.com/en/threads-mutexes-and-concurrent-programming-in-c/)
- [Multithreaded Programming with ThreadMentor](https://pages.mtu.edu/~shene/NSF-3/e-Book/index.html)
- [Introduction To Threads (pthreads) ](https://youtu.be/ldJ8WGZVXZk)
- [Philosophers: The dinning problem](https://medium.com/@ridwaneelfilali/philosophers-the-dinning-problem-8ea3c0fc8cc7)
- https://github.com/qingqingqingli/philosophers/wiki




<!-- 
Benefits of Using Threads:

1. **Concurrency**: Threads provide a way to achieve concurrency, enabling different parts of a program to execute independently.
Concurrency is essential for improving the responsiveness of applications, particularly in scenarios where tasks can be performed simultaneously.

2. **Parallelism**: Threads facilitate parallelism by allowing multiple threads to execute in parallel, taking advantage of multi-core processors.
Parallelism can lead to better utilization of system resources and improved performance for certain types of tasks.

3. **Responsiveness**: Threads are often used in graphical user interfaces and interactive applications to maintain responsiveness. For example, a background thread might handle file I/O or network requests, allowing the main thread to remain responsive to user input.

4. **Resource Sharing**:
   - Threads within a process share the same resources, such as memory space, file descriptors, and other process-related attributes.
   - While sharing resources enables efficient communication between threads, it also introduces challenges related to synchronization and avoiding data corruption.

5. **Synchronization**:
   - Synchronization mechanisms, such as mutexes, semaphores, and condition variables, are crucial for managing shared resources and avoiding race conditions.
   - Proper synchronization ensures that threads can safely access and modify shared data without conflicts.

Modularity: Tasks can be modularized and executed independently in separate threads.

6. **Thread Safety**:
   - Thread safety refers to the ability of a program to function correctly in a multithreaded environment.
   - Thread-safe code ensures that shared resources are accessed and modified in a way that avoids data corruption and unexpected behavior.

7. **Multithreading Challenges**: Multithreading introduces challenges such as deadlocks (circular dependencies on resources), race conditions (unpredictable outcomes due to interleaved execution), and priority inversion (lower-priority threads delaying higher-priority threads).

8. **Scalability**:
   - Threads provide a way to achieve scalability in applications by distributing work among multiple threads.
   - Scalability is important for handling increased workloads and taking advantage of modern, multi-core processors.
-->
