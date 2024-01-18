/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zelhajou <zelhajou@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/04 19:06:32 by zelhajou          #+#    #+#             */
/*   Updated: 2024/01/17 16:57:52 by zelhajou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosopher.h"

void	ft_error_parse_msg(void)
{
	ft_putstr_fd("Error: Invalid number of arguments\n", 2);
	ft_putstr_fd("Usage:\n./philo [number_of_philosophers] [time_to_die] ", 2);
	ft_putstr_fd("[time_to_eat] [time_to_sleep] (optional)", 2);
	ft_putstr_fd("[number_of_times_each_philosopher_must_eat]\n\n", 2);
	ft_putstr_fd("Example:\n./philo 5 800 200 200 3\n", 2);
	exit(1);
}

bool	parse_arguments(int argc, char **argv, t_philo *philo)
{
	int	i;

	i = 1;
	if (argc < 5 || argc > 6)
	{
		ft_error_parse_msg();
		return (false);
	}
	philo->nb_philo = ft_atoi(argv[1]);
	philo->time_to_die = ft_atoi(argv[2]);
	philo->time_to_eat = ft_atoi(argv[3]);
	philo->time_to_sleep = ft_atoi(argv[4]);
	if (argc == 6)
		philo->nb_must_eat = ft_atoi(argv[5]);
	else
		philo->nb_must_eat = -1;
	if (philo->nb_philo <= 0 || philo->time_to_die <= 0
		|| philo->time_to_eat <= 0 || philo->time_to_sleep <= 0
		|| (argc == 6 && philo->nb_must_eat <= 0))
	{
		ft_putstr_fd("Error: Invalid arguments\n", 2);
		return (false);
	}
	return (true);
}

bool	initialize_philosophers(t_philo *philo)
{
	int	i;

	i = 0;
	philo->philosophers = malloc(sizeof(t_philo) * philo->nb_philo);
	if (!philo->philosophers)
		return (false);
	while (i < philo->nb_philo)
	{
		philo->philosophers[i].id = i + 1;
		philo->philosophers[i].is_eating = false;
		philo->philosophers[i].is_sleeping = false;
		philo->philosophers[i].is_thinking = false;
		philo->philosophers[i].is_dead = false;
		philo->philosophers[i].nb_eat = 0;
		philo->philosophers[i].time_to_die = philo->time_to_die;
		philo->philosophers[i].time_to_eat = philo->time_to_eat;
		philo->philosophers[i].time_to_sleep = philo->time_to_sleep;
		philo->philosophers[i].nb_must_eat = philo->nb_must_eat;
		philo->philosophers[i].last_eat = ft_get_time();
		philo->philosophers[i].forks = philo->nb_philo;
		philo->philosophers[i].nb_philo = philo->nb_philo;
		i++;
	}
	return (true);
}

bool	initialize_simulation(int argc, char **argv, t_philo **philosophers)
{
	*philosophers = malloc(sizeof(t_philo));
	if (!*philosophers)
		return (false);
	if (!parse_arguments(argc, argv, *philosophers))
	{
		free(*philosophers);
		exit(1);
	}
	if (!initialize_philosophers(*philosophers))
	{
		free(*philosophers);
		return (false);
	}
	return (true);
}
