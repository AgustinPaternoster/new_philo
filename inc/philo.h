/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apaterno <apaterno@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/27 12:13:50 by apaterno          #+#    #+#             */
/*   Updated: 2024/11/27 12:13:50 by apaterno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <unistd.h>
# include <pthread.h>
# include <sys/time.h>
# include <stdlib.h>
# include <stdio.h>
# include <limits.h>

# define RULES "Error\n\
1. The number of arguments must be 4 or 5.\n\
2. Only positive integers are allowed.\n\
3. The number of philosophers must be greater than 1.\n\
4. The number of meals must be greater than 0.\n\
5. the time must be bigger than 59ms\n"

//States
# define SLEEP "is sleeping"
# define FORK1 "has taken a first fork"
# define FORK2 "has taken a second fork"
# define THINK "is thinking"
# define EAT "is eating"
# define DIED "is dead"

//Errors
# define MALLOC "Malloc error\n"
# define MUTEX "Mutex error\n"
# define THREAD "Thread error\n"

typedef enum s_bool
{
	FALSE,
	TRUE
}	t_bool;

typedef struct s_forks
{
	int				fork_nb;
	pthread_mutex_t	fork;
}	t_forks;

typedef struct c_philo
{
	pthread_t		thread_id;
	int				philo_id;
	int				meals;
	long			last_meal;
	t_bool			is_full;
	t_forks			*first_fork;
	t_forks			*second_fork;
	pthread_mutex_t	philo_mutex;
	struct s_data	*data;
}	t_philo;

typedef struct s_data
{
	t_philo			*philo;
	t_forks			*forks;
	pthread_t		monitor;
	int				philo_nb;
	long			time_eat;
	long			time_sleep;
	long			time_die;
	int				meals_nb;
	t_bool			dead_flag;
	long			start_time;
	t_bool			all_ready;
	pthread_mutex_t	print;
	pthread_mutex_t	read_table;
}	t_data;

// utils
long	ft_atol(const char *nptr);
long	get_date_time(void);
void	ft_usleep(int miliseconds);
t_bool	ft_isnumber(char c);
void	ft_print_state(t_philo *philo, char *state);
void	ft_putstr_fd(char *str, int fd);
void	error_exit(char *msg, int exit_code);
t_bool	dead_loop(t_data *data);
//void ft_print_state(t_philo *philo,char *state, int forknb);
// init
t_bool	init_data(t_data *data, char **argv, int arc);
// threads
t_bool	start_simulation(t_data *data);
void	*philo_rutine(void *philos);
t_bool	dead_checker(t_philo *philo);
void	*monitor_rutine(void *data);
//getter & setter
long	get_safe_long(pthread_mutex_t *mutex, long *var);
void	set_safe_long(pthread_mutex_t *mutex, long *var, long value);
t_bool	get_safe_bool(pthread_mutex_t *mutex, t_bool *boolean);
void	set_safe_bool(pthread_mutex_t *mutex, t_bool *var, t_bool value);

#endif