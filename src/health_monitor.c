/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   health_monitor.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zelhajou <zelhajou@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/26 11:29:06 by zelhajou          #+#    #+#             */
/*   Updated: 2024/01/29 17:47:50 by zelhajou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosopher.h"


void link_philosophers_to_monitor(t_philo *philosophers, t_philo *monitor)
{
	int i;

	i = 0;
	while (i < monitor->num_philosophers)
	{
		philosophers[i].protection_mutex = monitor->protection_mutex;
		i++;
	}
	monitor->start_time = ft_get_time();
}

t_philo *setup_health_monitor(t_philo *philo)
{
	t_philo *monitor;

	monitor = malloc(sizeof(t_philo));
	if (!monitor)
		return (NULL);
	monitor->id = 0;
	monitor->meals_eaten = 0;
	monitor->time_to_die = philo->time_to_die;
	monitor->time_to_eat = philo->time_to_eat;
	monitor->time_to_sleep = philo->time_to_sleep;
	monitor->num_must_eat = philo->num_must_eat;
	monitor->last_meal_time = philo->last_meal_time;
	monitor->num_forks = philo->num_philosophers;
	monitor->num_philosophers = philo->num_philosophers;
	monitor->fork_mutex = NULL;
	monitor->protection_mutex = malloc(sizeof(pthread_mutex_t));
	pthread_mutex_init(monitor->protection_mutex, NULL);
	return (monitor);
}

void	*check_philosopher_health(void *param)
{
	t_philo *monitor;
	int i;
	long long time;

	monitor = (t_philo *)param;
	i = 0;
	ft_usleep(10);
	while (i < monitor->num_philosophers)
	{
		pthread_mutex_lock(monitor->protection_mutex);
		time = ft_get_time() - monitor->last_meal_time[i];
		pthread_mutex_unlock(monitor->protection_mutex);
		if (time >= monitor->time_to_die)
		{
			pthread_mutex_lock(monitor->protection_mutex);
			//print_status(&monitor[i], "has Died");
			printf("has Died %d    %lld\n", i+1, time);
			return (NULL);
		}
		if (i + 1 == monitor->num_philosophers)
			i = -1;
		i++;
	}
	return (NULL);
}
