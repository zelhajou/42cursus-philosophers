/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosopher.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zelhajou <zelhajou@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/04 19:06:37 by zelhajou          #+#    #+#             */
/*   Updated: 2024/01/05 13:59:19 by zelhajou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILOSOPHER_H
# define PHILOSOPHER_H

# include <stdio.h>
# include <stdlib.h>
# include <pthread.h>
# include <unistd.h>
# include <sys/time.h>
# include <stdbool.h>

# define EAT 0
# define SLEEP 1
# define THINK 2
# define DEAD 3
# define FORK 4

typedef struct s_philo
{
	int				id;
	bool			is_eating;
	bool			is_sleeping;
	bool			is_thinking;
	bool			is_dead;
	int				nb_eat;
	int				time_to_die;
	int				time_to_eat;
	int				time_to_sleep;
	int				nb_must_eat;
	long			last_eat;
	int				forks;
	int				nb_philo;
	struct s_philo	*philosophers;
}		t_philo;

bool	parse_arguments(int argc, char **argv, t_philo *philo);
bool	initialize_philosophers(t_philo *philosophers);
bool	initialize_simulation(int argc, char **argv, t_philo **philosophers);

// utils
void	ft_putstr_fd(char *s, int fd);
bool	ft_is_digit(char c);
int		skip_space(int *i, const char *str);
int		ft_atoi(const char *str);
long	get_time(void);
void	ft_error_parse_msg(void);
#endif
