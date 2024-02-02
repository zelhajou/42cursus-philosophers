/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosopher.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zelhajou <zelhajou@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/04 19:06:37 by zelhajou          #+#    #+#             */
/*   Updated: 2024/02/02 19:55:10 by zelhajou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILOSOPHER_H
# define PHILOSOPHER_H

# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <pthread.h>
# include <unistd.h>
# include <sys/time.h>
# include <stdbool.h>

# define RESET			"\033[0m"
# define BLACK			"\033[30m"
# define RED			"\033[31m"
# define GREEN			"\033[32m"
# define YELLOW			"\033[33m"
# define BLUE			"\033[34m"
# define MAGENTA		"\033[35m"
# define CYAN			"\033[36m"
# define WHITE			"\033[37m"

typedef struct s_philo
{
	int				id;
	int				*meals_eaten;
	int				time_to_die;
	int				time_to_eat;
	int				time_to_sleep;
	int				num_must_eat;
	long long		*last_meal_time;
	int				num_forks;
	int				num_philosophers;
	pthread_t		philo_thread;
	pthread_mutex_t	*fork_mutex;
	pthread_mutex_t	*protection_mutex;
	long long		start_time;
}	t_philo;

// philo_actions
void			get_fork(t_philo *philosopher);
void			start_eating(t_philo *philosopher);
void			release_forks(t_philo *philosopher);
// philo_states
void			start_sleeping(t_philo *philosopher);
void			start_thinking(t_philo *philosopher);
// philo_threads
void			*philo_lifecycle(void *philosopher);
void			start_philosopher_threads(t_philo *philosophers);
// simulation_init
pthread_mutex_t	*initialize_forks(int num_philosophers);
long long		*initialize_last_meal_time(int num_philosophers);
void			initialize_philos_data(t_philo *philosophers_initialized,
					t_philo *philo, pthread_mutex_t *num_forks,
					long long *last_meal_time);
t_philo			*initialize_philosophers(t_philo *philo_info);
t_philo			*initialize_simulation(int argc, char **argv);
// health_monitor
t_philo			*setup_health_monitor(t_philo *philosopher);
void			*check_philosopher_health(void *philosopher);
void			link_philosophers_to_monitor(t_philo *philosophers,
					t_philo *monitor);
// parse and validate argus
bool			parse_arguments(int argc, char **argv, t_philo *philo_info);
bool			validate_num_philosophers(const char *arg);
bool			validate_time_argument(const char *arg);
bool			validate_num_must_eat(const char *arg);

// print_prompt
void			ft_putnbr_fd(int n, int fd);
void			print_status(t_philo *philo, char *action);
void			rest_in_peace(int id, long long time);
void			ft_error_parse_msg(void);
// utils
void			ft_putstr_fd(char *s, int fd);
int				ft_atoi(const char *str);
long long		ft_get_time(void);
void			ft_sleep(long long time);
size_t			ft_strlen(char *str);
bool			ft_is_numeric(const char *str);
int				ft_isdigit(int c);
void			clean_garbage(t_philo *philosophers, t_philo *health_monitor);

#endif
