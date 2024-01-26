/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_threads.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zelhajou <zelhajou@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/25 17:16:58 by zelhajou          #+#    #+#             */
/*   Updated: 2024/01/26 12:01:20 by zelhajou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosopher.h"

void *philo_lifecycle(void *param)
{
	t_philo *philo = (t_philo *)param;
	if (philo->id % 2 == 0)
		usleep(100);
	while (1)
	{
		get_left_fork(philo);
		get_right_fork(philo);
		start_eating(philo);
		release_forks(philo);
		start_sleeping(philo);
		start_thinking(philo);
	}
}

void	start_philosopher_threads(t_philo *philosophers)
{
	size_t i;

	i = 0;
	while (i < philosophers->num_philosophers)
	{
		pthread_create(&philosophers[i].philo_thread, NULL, philo_lifecycle, &philosophers[i]);
		pthread_detach(philosophers[i].philo_thread);
		i++;
	}
}
