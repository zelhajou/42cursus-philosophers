/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_actions.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zelhajou <zelhajou@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/25 16:11:17 by zelhajou          #+#    #+#             */
/*   Updated: 2024/02/01 16:30:48 by zelhajou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosopher.h"

void	get_fork(t_philo *philosopher)
{
	pthread_mutex_lock(&philosopher->fork_mutex[philosopher->id - 1]);
	if (philosopher->id == 1)
		pthread_mutex_lock(&philosopher
			->fork_mutex[philosopher->num_philosophers - 1]);
	else
		pthread_mutex_lock(&philosopher->fork_mutex[philosopher->id - 2]);
	pthread_mutex_lock(philosopher->protection_mutex);
	print_status(philosopher, "has taken a fork");
	pthread_mutex_unlock(philosopher->protection_mutex);
}

void	start_eating(t_philo *philosopher)
{
	pthread_mutex_lock(philosopher->protection_mutex);
	print_status(philosopher, "is eating");
	philosopher->last_meal_time[philosopher->id - 1] = ft_get_time();
	philosopher->meals_eaten[philosopher->id - 1]++;
	pthread_mutex_unlock(philosopher->protection_mutex);
	ft_sleep(philosopher->time_to_eat);
}

void	release_forks(t_philo *philosopher)
{
	pthread_mutex_unlock(&philosopher->fork_mutex[philosopher->id - 1]);
	if (philosopher->id == 1)
		pthread_mutex_unlock(&philosopher
			->fork_mutex[philosopher->num_philosophers - 1]);
	else
		pthread_mutex_unlock(&philosopher->fork_mutex[philosopher->id - 2]);
}
