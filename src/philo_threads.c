/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_threads.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zelhajou <zelhajou@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/25 17:16:58 by zelhajou          #+#    #+#             */
/*   Updated: 2024/01/29 17:42:23 by zelhajou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosopher.h"

void *philo_lifecycle(void *param)
{
	t_philo *philo = (t_philo *)param;
	if (philo->id % 2 == 0)
		ft_usleep(10);
	while (1)
	{
		get_right_fork(philo);
		get_left_fork(philo);
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
		philosophers[i].start_time = ft_get_time();
		pthread_create(&philosophers[i].philo_thread, NULL, philo_lifecycle, &philosophers[i]);
		pthread_detach(philosophers[i].philo_thread);
		i++;
	}
}
