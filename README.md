![ascii-text-art](https://github.com/zelhajou/Philosophers/assets/39954629/e65a4d3e-10a2-44b6-bf27-f79c71b4f7e6)

# Philosophers Project
## Description
This project simulates a classic problem in computer science, *the dining philosophers problem*. It involves philosophers sitting at a table, doing one of three things: eating, thinking, or sleeping. While eating, they need two forks, which are shared with neighbors.
*The Dining Philosophers problem* is a classic puzzle in computer science, often used to illustrate the challenges of resource allocation and synchronization in concurrent programming. At first glance, it might seem like a quirky thought experiment, but it mirrors real-world scenarios in computing quite closely

<!--
![MOSHED-2024-1-5-16-52-54](https://github.com/zelhajou/Philosophers/assets/39954629/d1660b4a-5adc-44e3-8177-0fffb4ef238a)
-->
![MOSHED-2024-1-5-16-56-57](https://github.com/zelhajou/Philosophers/assets/39954629/9b0f1688-34ab-4c6c-b60c-62ea236a0f95)

## The Basic Setup
Imagine five philosophers who spend their lives just thinking and eating. They sit around a round table with a bowl of spaghetti in front of each of them. Here’s the catch: there are only five forks available, placed between each pair of adjacent philosophers. To eat, a philosopher needs to use two forks – one on their left and one on their right.

## The Problem
The issue arises when every philosopher picks up the fork on their left at the same time. Each of them is left waiting for the fork on their right to become available. Since everyone is holding one fork, no one has two forks to start eating. This results in a deadlock where all philosophers are stuck waiting indefinitely – a situation we want to avoid in real-world systems.

## The Setup
<img width="600" alt="Screen Shot 2024-01-05 at 5 39 38 PM" src="https://github.com/zelhajou/Philosophers/assets/39954629/2baf18f2-2b9e-4091-b6f8-1a4f77363eff">

- **Five Philosophers:** They alternate between thinking and eating.
- **Five Forks:** One between each philosopher.
- **The Problem:** To eat, a philosopher needs both forks on either side.

## The Challenge
The catch is simple yet complex. If every philosopher simultaneously picks up the left fork, they all wait for the right fork indefinitely – a deadlock. This situation perfectly mimics real-world scenarios in computing where processes wait indefinitely for resources, leading to system freezes.

## Solving the Problem
Several strategies have been proposed to solve this deadlock:

1. **Semaphore Solution:** Limit the number of philosophers that can try to pick up forks simultaneously. If we allow only four philosophers to reach for the forks at any time, at least one philosopher will be able to eat, preventing a deadlock.
2. **Designate a Left-Handed Philosopher:** If one philosopher picks up the right fork first and then the left, it breaks the cycle of everyone reaching for the left fork simultaneously, preventing a deadlock.
3. **The Waiter Approach:** Introduce a waiter who decides when a philosopher can pick up forks. The waiter ensures that not all forks are picked up at once, preventing a deadlock.
4. **Resource Hierarchy:** Number the forks and always have the philosophers pick up the lower-numbered fork first and the higher-numbered fork next. This order prevents the circular wait condition.

## Why It Matters
Understanding the Dining Philosophers problem is crucial in computer science because it teaches us about managing resources in multi-threaded or multi-process environments. It's not just about preventing deadlock but also ensuring fair access to resources and preventing starvation (where a process never gets the resources it needs).

## Conclusion
The Dining Philosophers Problem is more than just a puzzle; it's a fundamental concept that helps in understanding complex scenarios in multi-threading and resource sharing in computing. By learning about this problem, one can gain insights into solving real-world issues in system design and process management.

## How to Run
Compile with `make` and run the program as follows:

```bash
./philo [number_of_philosophers] [time_to_die] [time_to_eat] [time_to_sleep] [number_of_times_each_philosopher_must_eat (optional)]
```
## Implementation
The simulation is done using threads and mutexes. Each philosopher is a thread and forks are represented as mutexes.

## Features
- Argument validation
- Philosopher activities simulation
- Resource management to avoid deadlocks
