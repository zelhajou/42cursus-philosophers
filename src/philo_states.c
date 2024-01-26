/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_states.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zelhajou <zelhajou@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/25 16:40:58 by zelhajou          #+#    #+#             */
/*   Updated: 2024/01/26 13:51:48 by zelhajou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosopher.h"

void start_sleeping(t_philo *philo)
{
	pthread_mutex_lock(philo->protection_mutex);
	print_status(philo, "is sleeping");
	pthread_mutex_unlock(philo->protection_mutex);
	usleep(philo->time_to_eat * 1000);
}

void start_thinking(t_philo *philo)
{
	pthread_mutex_lock(philo->protection_mutex);
	print_status(philo, "is thinking");
	pthread_mutex_unlock(philo->protection_mutex);
}