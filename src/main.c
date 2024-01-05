/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zelhajou <zelhajou@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/04 19:09:29 by zelhajou          #+#    #+#             */
/*   Updated: 2024/01/05 14:10:22 by zelhajou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosopher.h"

int	main(int argc, char **argv)
{
	int		i;
	t_philo	*philo;

	i = 0;
	if (!initialize_simulation(argc, argv, &philo))
	{
		ft_putstr_fd("Simulation initialization failed.\n", 2);
		return (1);
	}
	while (i < (philo->nb_philo))
	{
		printf("Philosopher %d:\n", i + 1);
		printf("Time to Die: %d\n", philo->philosophers[i].time_to_die);
		printf("Time to Eat: %d\n", philo->philosophers[i].time_to_eat);
		printf("Time to Sleep: %d\n", philo->philosophers[i].time_to_sleep);
		printf("Number of Times Must Eat: %d\n", philo->philosophers[i].nb_must_eat);
		printf("Last Eat Time: %ld\n", philo->philosophers[i].last_eat);
		printf("Forks: %d\n", philo->philosophers[i].forks);
		i++;
	}
	return (0);
}
