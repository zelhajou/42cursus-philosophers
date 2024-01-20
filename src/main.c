/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zelhajou <zelhajou@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/04 19:09:29 by zelhajou          #+#    #+#             */
/*   Updated: 2024/01/20 10:40:31 by zelhajou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosopher.h"

void is_eating(t_philo *philo)
{
	pthread_mutex_lock(&philo->mut[philo->id - 1]);
	printf(Y " Time %lld: philo Id : %d take a fork ...\n" RST, ft_get_time() - philo->time_start, philo->id);
	if (philo->id == 1)
	{
		pthread_mutex_lock(&philo->mut[philo->nb_philo - 1]);
		printf(Y " Time %lld: philo Id : %d take a fork ...\n" RST, ft_get_time() - philo->time_start, philo->id );
	}
	else
	{
		pthread_mutex_lock(&philo->mut[philo->id - 2]);
		printf(Y " Time %lld: philo Id : %d take a fork ...\n" RST, ft_get_time() - philo->time_start, philo->id);
	}
	printf(G " Time %lld: philo Id : %d is eating ...\n" RST, ft_get_time() - philo->time_start, philo->id);
	philo->last_eat[philo->id - 1] = ft_get_time();
	usleep(philo->time_to_eat * 1000);
	return;
}

void is_sleeping(t_philo *philo)
{
	pthread_mutex_unlock(&philo->mut[philo->id - 1]);
	if (philo->id == 1)
		pthread_mutex_unlock(&philo->mut[philo->nb_philo - 1]);
	else
		pthread_mutex_unlock(&philo->mut[philo->id - 2]);
	printf(W " Time : %lld philo Id : %d is sleeping ...\n" RST, ft_get_time() - philo->time_start, philo->id);
	usleep(philo->time_to_eat * 1000);
	printf(C "is thinking ...\n" RST);
	return;
}

void *routine(void *param)
{
	t_philo *philo = (t_philo *)param;
	printf("philo %d\n", philo->id);

	if (philo->id % 2 == 0)
		usleep(100);

	while (1)
	{
		is_eating(philo);
		is_sleeping(philo);
	}
}

t_philo *death_init(t_philo *philo, t_philo *death)
{
	death = malloc(sizeof(t_philo));
	if (!death)
		return (NULL);
	death->id = 0;
	death->nb_eat = 0;
	death->time_to_die = philo->time_to_die;
	death->time_to_eat = philo->time_to_eat;
	death->time_to_sleep = philo->time_to_sleep;
	death->nb_must_eat = philo->nb_must_eat;
	death->last_eat = philo->last_eat;
	death->forks = philo->nb_philo;
	death->nb_philo = philo->nb_philo;
	death->mut = NULL;
	pthread_mutex_init(&death->protect, NULL);
	return (death);
}

void	*check_death(void *param)
{
	t_philo *death;
	int i;

	death = (t_philo *)param;
	i = 0;
	usleep(1000);
	while (i < death->nb_philo)
	{
		if (ft_get_time() - death->last_eat[i] >= death->time_to_die)
		{
			pthread_mutex_lock(&death->protect);
			printf(R "is Dead %d\n" RST, i+1);
			return (NULL);
		}
		if (i + 1 <= death->nb_philo)
			i = -1;
		i++;
	}
	return (NULL);
}

int	main(int argc, char **argv)
{
	int		i;
	t_philo	*philo;
	t_philo *death;

	i = 0;
	philo = initialize_simulation(argc, argv, &philo);
	if (!philo)
	{
		ft_putstr_fd("Simulation initialization failed.\n", 2);
		return (1);
	}
	death = death_init(philo, death);
	death->time_start = ft_get_time();
	while (i < philo->nb_philo)
	{
		philo[i].time_start = death->time_start;
		pthread_create(&philo[i].th_philo, NULL, routine, &philo[i]);
		pthread_detach(philo[i].th_philo);
		i++;
	}
	pthread_create(&death->th_philo, NULL, check_death, death);
	pthread_join(death->th_philo, NULL);
	return (0);
}
