/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_actions.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zelhajou <zelhajou@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/25 16:11:17 by zelhajou          #+#    #+#             */
/*   Updated: 2024/01/26 13:35:58 by zelhajou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosopher.h"

void	get_left_fork(t_philo *philo)
{
	pthread_mutex_lock(&philo->fork_mutex[philo->id - 1]);
	pthread_mutex_lock(philo->protection_mutex);
	print_status(philo, "has taken a left fork");
	pthread_mutex_unlock(philo->protection_mutex);
}

void	get_right_fork(t_philo *philo)
{
	if (philo->id == 1)
		pthread_mutex_lock(&philo->fork_mutex[philo->num_philosophers - 1]);
	else
		pthread_mutex_lock(&philo->fork_mutex[philo->id - 2]);
	pthread_mutex_lock(philo->protection_mutex);
	print_status(philo, "has taken a right fork");
	pthread_mutex_unlock(philo->protection_mutex);
}

void	start_eating(t_philo *philo)
{
	pthread_mutex_lock(philo->protection_mutex);
	print_status(philo, "is eating");
	philo->last_meal_time[philo->id - 1] = ft_get_time();
	pthread_mutex_unlock(philo->protection_mutex);
	usleep(philo->time_to_eat * 1000);
}

void	release_forks(t_philo *philo)
{
	pthread_mutex_unlock(&philo->fork_mutex[philo->id - 1]);
	if (philo->id == 1)
		pthread_mutex_unlock(&philo->fork_mutex[philo->num_philosophers - 1]);
	else
		pthread_mutex_unlock(&philo->fork_mutex[philo->id - 2]);
}
