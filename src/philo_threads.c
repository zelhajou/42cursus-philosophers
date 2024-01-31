/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_threads.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zelhajou <zelhajou@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/25 17:16:58 by zelhajou          #+#    #+#             */
/*   Updated: 2024/01/31 17:09:55 by zelhajou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosopher.h"

void	*philo_lifecycle(void *philo)
{
	t_philo	*philosopher;

	philosopher = (t_philo *)philo;
	if (philosopher->id % 2 == 0)
		ft_sleep(10);
	while (1)
	{
		get_fork(philosopher);
		start_eating(philosopher);
		release_forks(philosopher);
		start_sleeping(philosopher);
		start_thinking(philosopher);
	}
}

void	start_philosopher_threads(t_philo *philosophers)
{
	int	i;

	i = 0;
	while (i < philosophers->num_philosophers)
	{
		philosophers[i].start_time = ft_get_time();
		pthread_create(&philosophers[i].philo_thread, NULL,
			philo_lifecycle, &philosophers[i]);
		pthread_detach(philosophers[i].philo_thread);
		i++;
	}
}
