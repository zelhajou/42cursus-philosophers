/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zelhajou <zelhajou@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/04 19:09:29 by zelhajou          #+#    #+#             */
/*   Updated: 2024/02/02 12:50:50 by zelhajou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosopher.h"

int	main(int argc, char **argv)
{
	t_philo	*philosophers;
	t_philo	*health_monitor;

	philosophers = initialize_simulation(argc, argv);
	if (!philosophers)
	{
		write(2, RED, ft_strlen(RED));
		ft_putstr_fd("Simulation initialization failed.\n", 2);
		write(2, RESET, ft_strlen(RESET));
		return (1);
	}
	health_monitor = setup_health_monitor(philosophers);
	if(!health_monitor)
	{
		write(2, RED, ft_strlen(RED));
		ft_putstr_fd("Health monitor initialization failed.\n", 2);
		write(2, RESET, ft_strlen(RESET));
		return (1);
	}
	link_philosophers_to_monitor(philosophers, health_monitor);
	start_philosopher_threads(philosophers);
	pthread_create(&health_monitor->philo_thread, NULL,
	check_philosopher_health, health_monitor);
	pthread_join(health_monitor->philo_thread, NULL);
	return (clean_garbage(philosophers, health_monitor), 0);
}
