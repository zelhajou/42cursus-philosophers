/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosopher.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zelhajou <zelhajou@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/04 19:06:37 by zelhajou          #+#    #+#             */
/*   Updated: 2024/01/23 18:36:54 by zelhajou         ###   ########.fr       */
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

/*
** ANSI Escape Sequences for Bold Text Colors
** Usage: 
**     printf(R "This is red text." RST);
**     printf(B "This is blue text." RST);
** Remember to use RST to reset the color after setting it.
*/

# define RST    "\033[0m"      /* Reset to default color */
# define R		"\033[1;31m"   /* Bold Red */
# define G      "\033[1;32m"   /* Bold Green */
# define Y      "\033[1;33m"   /* Bold Yellow */
# define B      "\033[1;34m"   /* Bold Blue */
# define M      "\033[1;35m"   /* Bold Magenta */
# define C      "\033[1;36m"   /* Bold Cyan */
# define W      "\033[1;37m"   /* Bold White */


typedef struct s_philo
{
	int				id;
	int				nb_eat;
	int				time_to_die;
	int				time_to_eat;
	int				time_to_sleep;
	int				nb_must_eat;
	long long		*last_eat;
	int				forks;
	int				nb_philo;
	pthread_t		th_philo;
	pthread_mutex_t	*mut;
	pthread_mutex_t *protect;
	long long time_start;
}		t_philo;


bool	parse_arguments(int argc, char **argv, t_philo *philo);
t_philo	*initialize_philosophers(t_philo *philosophers);
t_philo	*initialize_simulation(int argc, char **argv, t_philo **philosophers);

// utils
void	ft_putstr_fd(char *s, int fd);
bool	ft_is_digit(char c);
int		skip_space(int *i, const char *str);
int		ft_atoi(const char *str);
long long	ft_get_time(void);
void	ft_error_parse_msg(void);
#endif
