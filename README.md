![ascii-text-art](https://github.com/zelhajou/Philosophers/assets/39954629/e65a4d3e-10a2-44b6-bf27-f79c71b4f7e6)

# Philosophers Project
## Description
This project simulates a classic problem in computer science, the dining philosophers problem. It involves philosophers sitting at a table, doing one of three things: eating, thinking, or sleeping. While eating, they need two forks, which are shared with neighbors.

<!--
![MOSHED-2024-1-5-16-52-54](https://github.com/zelhajou/Philosophers/assets/39954629/d1660b4a-5adc-44e3-8177-0fffb4ef238a)
-->
![MOSHED-2024-1-5-16-56-57](https://github.com/zelhajou/Philosophers/assets/39954629/9b0f1688-34ab-4c6c-b60c-62ea236a0f95)



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
