![ascii-text-art](https://github.com/zelhajou/Philosophers/assets/39954629/e65a4d3e-10a2-44b6-bf27-f79c71b4f7e6)

# Philosophers Project
## Description
This project simulates a classic problem in computer science, the dining philosophers problem. It involves philosophers sitting at a table, doing one of three things: eating, thinking, or sleeping. While eating, they need two forks, which are shared with neighbors.

<!--
![MOSHED-2024-1-5-16-52-54](https://github.com/zelhajou/Philosophers/assets/39954629/d1660b4a-5adc-44e3-8177-0fffb4ef238a)
-->
![MOSHED-2024-1-5-16-56-57](https://github.com/zelhajou/Philosophers/assets/39954629/9b0f1688-34ab-4c6c-b60c-62ea236a0f95)

## Introduction
Imagine a round table where five philosophers are seated, pondering the mysteries of the universe. But there's a twist – each philosopher needs two forks to eat spaghetti, and there's only one fork between each of them. This scenario is known as the "Dining Philosophers Problem," a classic example in computer science used to demonstrate synchronization issues and resource sharing in multi-threaded programming.

## The Setup

<img width="600" alt="Screen Shot 2024-01-05 at 5 39 38 PM" src="https://github.com/zelhajou/Philosophers/assets/39954629/2baf18f2-2b9e-4091-b6f8-1a4f77363eff">

- **Five Philosophers:** They alternate between thinking and eating.
- **Five Forks:** One between each philosopher.
- **The Problem:** To eat, a philosopher needs both forks on either side.

## The Challenge
The catch is simple yet complex. If every philosopher simultaneously picks up the left fork, they all wait for the right fork indefinitely – a deadlock. This situation perfectly mimics real-world scenarios in computing where processes wait indefinitely for resources, leading to system freezes.

## Solutions
Over the years, various solutions have been proposed:

1. **Semaphore:** Limit the number of philosophers that can attempt to pick up forks at the same time.
2. **Resource Hierarchy:** Assign an order to resources (forks) and require that they be picked up in a specific sequence.
3. **Waiter Approach:** Introduce a 'waiter' or a central authority to control when a philosopher can pick up forks.
4. **Left-Handed Philosopher:** Make one philosopher different, who picks up the right fork first, breaking the symmetry.

## Why It Matters
This problem is not just theoretical. It’s a practical tool used in computer science to understand issues like resource allocation, deadlock, and process synchronization. It's crucial for designing efficient, deadlock-free systems where multiple processes need to access shared resources.

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
