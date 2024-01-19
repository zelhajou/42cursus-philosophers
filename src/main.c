/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zelhajou <zelhajou@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/04 19:09:29 by zelhajou          #+#    #+#             */
/*   Updated: 2024/01/18 23:08:18 by zelhajou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosopher.h"

void is_eating(t_philo *philo)
{
	pthread_mutex_lock(philo->mut);
	if (philo->id == 1)
		pthread_mutex_lock(philo->philosophers[philo->nb_philo - 1].mut);
	else
		pthread_mutex_lock(philo->philosophers[philo->id - 1].mut);
	printf(" Time : %lld philo Id : %d is eating ...\n", ft_get_time() - philo->time_start, philo->id);
	usleep(philo->time_to_eat * 1000);
	
	return;
}


void is_sleeping(t_philo *philo)
{
	pthread_mutex_unlock(philo->mut);
	if (philo->id == 1)
		pthread_mutex_unlock(philo->philosophers[philo->nb_philo - 1].mut);
	else
		pthread_mutex_unlock(philo->philosophers[philo->id - 1].mut);
	printf(" Time : %lld philo Id : %d is sleeping ...\n", ft_get_time() - philo->time_start, philo->id);
	usleep(philo->time_to_eat * 1000);
	printf("is thinking ...");
	return;
}

void *routine(void *param)
{
	t_philo *philo = (t_philo *)param;

	if (philo->id % 2 == 0)
		usleep(100);
	while (1)
	{
		is_eating(philo);
		// is_sleeping(philo);
	}
}

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
	while (i < philo->nb_philo)
	{
	
		philo->philosophers[i].mut = (pthread_mutex_t *)malloc(sizeof(pthread_mutex_t));
		pthread_mutex_init(philo->philosophers[i].mut, NULL);
		i++;
	}

	i = 0;

	long long time =  ft_get_time();

	while (i < philo->nb_philo)
	{
		philo->philosophers[i].time_start = time;
		pthread_create(&philo->philosophers[i].th_philo, NULL, routine, &philo->philosophers[i]);
		pthread_detach(philo->philosophers[i].th_philo);
		i++;
	}

	// while (i < (philo->nb_philo))
	// {
	// 	printf("Philosopher %d:\n", i + 1);
	// 	printf("Time to Die: %d\n", philo->philosophers[i].time_to_die);
	// 	printf("Time to Eat: %d\n", philo->philosophers[i].time_to_eat);
	// 	printf("Time to Sleep: %d\n", philo->philosophers[i].time_to_sleep);
	// 	printf("Number of Times Must Eat: %d\n", philo->philosophers[i].nb_must_eat);
	// 	printf("Last Eat Time: %ld\n", philo->philosophers[i].last_eat);
	// 	printf("Forks: %d\n", philo->philosophers[i].forks);
	// 	i++;
	// }
	return (0);
}
