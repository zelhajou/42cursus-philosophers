/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zelhajou <zelhajou@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/04 19:09:29 by zelhajou          #+#    #+#             */
/*   Updated: 2024/02/01 19:08:07 by zelhajou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosopher.h"

void clean_garbage(t_philo *philosophers, t_philo *health_monitor)
{
	int	i;

	i = 0;
	while (i < philosophers->num_philosophers)
	{
		pthread_mutex_destroy(&philosophers[i].fork_mutex[i]);
		pthread_mutex_destroy(philosophers[i].protection_mutex);
		i++;
	}
	pthread_mutex_destroy(health_monitor->protection_mutex);
	free(philosophers->fork_mutex);
	free(philosophers->meals_eaten);
	free(philosophers->last_meal_time);
	free(philosophers->protection_mutex);
	free(philosophers);
	philosophers = NULL;
	// philosophers->fork_mutex = NULL;
	// philosophers->protection_mutex = NULL;
	// health_monitor->protection_mutex = NULL;
	free(health_monitor);
}

void	clear_screen(void)
{
	system("leaks philo");	
}

int	main(int argc, char **argv)
{
	t_philo	*philosophers;
	t_philo	*health_monitor;

	atexit(clear_screen);
	philosophers = initialize_simulation(argc, argv);
	if (!philosophers)
	{
		write(2, RED, strlen(RED));
		ft_putstr_fd("Simulation initialization failed.\n", 2);
		write(2, RESET, strlen(RESET));
		return (1);
	}
	health_monitor = setup_health_monitor(philosophers);
	if(!health_monitor)
	{
		write(2, RED, strlen(RED));
		ft_putstr_fd("Health monitor initialization failed.\n", 2);
		write(2, RESET, strlen(RESET));
		return (1);
	}
	link_philosophers_to_monitor(philosophers, health_monitor);
	printf("Time\tindex\taction\n");
	start_philosopher_threads(philosophers);
	pthread_create(&health_monitor->philo_thread, NULL,
		check_philosopher_health, health_monitor);
	pthread_join(health_monitor->philo_thread, NULL);
	clean_garbage(philosophers, health_monitor);
	return (0);
}
