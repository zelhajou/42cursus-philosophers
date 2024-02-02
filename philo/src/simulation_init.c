/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   simulation_init.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zelhajou <zelhajou@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/25 17:13:48 by zelhajou          #+#    #+#             */
/*   Updated: 2024/02/02 19:14:37 by zelhajou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosopher.h"

t_philo	*initialize_simulation(int argc, char **argv)
{
	t_philo	*philo_info;
	t_philo	*philosophers_initialized;

	philo_info = malloc(sizeof(t_philo));
	if (!philo_info)
		return (NULL);
	if (!parse_arguments(argc, argv, philo_info))
	{
		free(philo_info);
		return (NULL);
	}
	philosophers_initialized = initialize_philosophers(philo_info);
	if (!philosophers_initialized)
	{
		free(philo_info);
		return (NULL);
	}
	return (philosophers_initialized);
}

t_philo	*initialize_philosophers(t_philo *philo_info)
{
	t_philo			*philos_initialized;
	pthread_mutex_t	*forks;
	long long		*last_meal_time;

	philos_initialized = malloc(sizeof(t_philo)
			* philo_info->num_philosophers);
	if (!philos_initialized)
		return (NULL);
	forks = initialize_forks(philo_info->num_philosophers);
	last_meal_time = initialize_last_meal_time(philo_info->num_philosophers);
	initialize_philos_data(philos_initialized, philo_info,
		forks, last_meal_time);
	return (philos_initialized);
}

pthread_mutex_t	*initialize_forks(int num_philosophers)
{
	int				i;
	pthread_mutex_t	*forks;

	i = 0;
	forks = malloc(sizeof(pthread_mutex_t) * num_philosophers);
	if (!forks)
		return (NULL);
	while (i < num_philosophers)
	{
		pthread_mutex_init(&forks[i], NULL);
		i++;
	}
	return (forks);
}

long long	*initialize_last_meal_time(int num_philosophers)
{
	int			i;
	long long	*last_meal_time;

	i = 0;
	last_meal_time = malloc(sizeof(long long) * num_philosophers);
	if (!last_meal_time)
		return (NULL);
	while (i < num_philosophers)
	{
		last_meal_time[i] = ft_get_time();
		i++;
	}
	return (last_meal_time);
}

void	initialize_philos_data(t_philo *philosophers_initialized,
		t_philo *philo, pthread_mutex_t *num_forks,
		long long *last_meal_time)
{
	int	i;
	int	*meals;

	meals = malloc(sizeof(int) * philo->num_philosophers);
	if (!meals)
		return ;
	memset(meals, 0, sizeof(int) * philo->num_philosophers);
	i = 0;
	while (i < philo->num_philosophers)
	{
		philosophers_initialized[i].id = i + 1;
		philosophers_initialized[i].meals_eaten = meals;
		philosophers_initialized[i].time_to_die = philo->time_to_die;
		philosophers_initialized[i].time_to_eat = philo->time_to_eat;
		philosophers_initialized[i].time_to_sleep = philo->time_to_sleep;
		philosophers_initialized[i].num_must_eat = philo->num_must_eat;
		philosophers_initialized[i].last_meal_time = last_meal_time;
		philosophers_initialized[i].num_forks = philo->num_philosophers;
		philosophers_initialized[i].num_philosophers = philo->num_philosophers;
		philosophers_initialized[i].fork_mutex = num_forks;
		i++;
	}
	free(philo);
}
