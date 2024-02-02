/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   health_monitor.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zelhajou <zelhajou@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/26 11:29:06 by zelhajou          #+#    #+#             */
/*   Updated: 2024/02/02 17:16:08 by zelhajou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosopher.h"

t_philo	*setup_health_monitor(t_philo *philosopher)
{
	t_philo	*monitor;

	monitor = malloc(sizeof(t_philo));
	if (!monitor)
		return (NULL);
	monitor->id = 0;
	monitor->meals_eaten = philosopher->meals_eaten;
	monitor->time_to_die = philosopher->time_to_die;
	monitor->time_to_eat = philosopher->time_to_eat;
	monitor->time_to_sleep = philosopher->time_to_sleep;
	monitor->num_must_eat = philosopher->num_must_eat;
	monitor->last_meal_time = philosopher->last_meal_time;
	monitor->num_forks = philosopher->num_philosophers;
	monitor->num_philosophers = philosopher->num_philosophers;
	monitor->fork_mutex = NULL;
	monitor->protection_mutex = malloc(sizeof(pthread_mutex_t));
	pthread_mutex_init(monitor->protection_mutex, NULL);
	return (monitor);
}

void	link_philosophers_to_monitor(t_philo *philosophers, t_philo *monitor)
{
	int	i;

	i = 0;
	while (i < monitor->num_philosophers)
	{
		philosophers[i].protection_mutex = monitor->protection_mutex;
		i++;
	}
	monitor->start_time = ft_get_time();
}

bool	check_meals_eaten(t_philo *monitor)
{
	int	i;

	i = 0;
	if (monitor->num_must_eat == -1)
		return (true);
	while (i < monitor->num_philosophers)
	{
		pthread_mutex_lock(monitor->protection_mutex);
		if (monitor->meals_eaten[i] < monitor->num_must_eat)
			return (pthread_mutex_unlock(monitor->protection_mutex), true);
		pthread_mutex_unlock(monitor->protection_mutex);
		i++;
	}
	pthread_mutex_lock(monitor->protection_mutex);
	return (false);
}

void	*check_philosopher_health(void *philosopher)
{
	t_philo		*monitor;
	int			i;
	long long	time;

	monitor = (t_philo *)philosopher;
	i = 0;
	// ft_sleep(10);
	while (i < monitor->num_philosophers && check_meals_eaten(monitor))
	{
		pthread_mutex_lock(monitor->protection_mutex);
		time = ft_get_time() - monitor->last_meal_time[i];
		pthread_mutex_unlock(monitor->protection_mutex);
		if (time >= monitor->time_to_die)
		{
			pthread_mutex_lock(monitor->protection_mutex);
			rest_in_peace(i + 1, ft_get_time() - monitor->start_time);
			return (NULL);
		}
		if (i + 1 == monitor->num_philosophers)
			i = -1;
		i++;
	}
	return (NULL);
}
