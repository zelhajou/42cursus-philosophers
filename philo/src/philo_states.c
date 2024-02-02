/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_states.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zelhajou <zelhajou@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/25 16:40:58 by zelhajou          #+#    #+#             */
/*   Updated: 2024/01/31 17:11:21 by zelhajou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosopher.h"

void	start_sleeping(t_philo *philosopher)
{
	pthread_mutex_lock(philosopher->protection_mutex);
	print_status(philosopher, "is sleeping");
	pthread_mutex_unlock(philosopher->protection_mutex);
	ft_sleep(philosopher->time_to_eat);
}

void	start_thinking(t_philo *philosopher)
{
	pthread_mutex_lock(philosopher->protection_mutex);
	print_status(philosopher, "is thinking");
	pthread_mutex_unlock(philosopher->protection_mutex);
}
