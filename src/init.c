/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apaterno <apaterno@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/26 14:59:24 by apaterno          #+#    #+#             */
/*   Updated: 2024/11/26 14:59:24 by apaterno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/philo.h"

static void	select_forks(t_data *data, int i)
{
	if (data->philo[i].philo_id % 2 == 0)
	{
		data->philo[i].first_fork = &data->forks[i];
		data->philo[i].second_fork = &data->forks[(i + 1) % data->philo_nb];
	}
	else
	{
		data->philo[i].first_fork = &data->forks[(i + 1) % data->philo_nb];
		data->philo[i].second_fork = &data->forks[i];
	}
}

static t_bool	init_mutex(t_data *data)
{
	int	i;

	i = 0;
	data->forks = malloc(sizeof(t_forks) * data->philo_nb);
	if (data->forks == NULL)
		error_exit(MALLOC, 1);
	while (i < data->philo_nb)
	{
		data->forks[i].fork_nb = i;
		if (pthread_mutex_init(&data->forks[i].fork, NULL) != 0)
			error_exit(MUTEX, 2);
		i++;
	}
	if (pthread_mutex_init(&data->read_table, NULL) != 0)
		error_exit(MUTEX, 2);
	if (pthread_mutex_init(&data->print, NULL) != 0)
		error_exit(MUTEX, 2);
	return (TRUE);
}

static t_bool	init_philo(t_data *data)
{
	int	i;

	i = 0;
	data->philo = malloc(sizeof(t_philo) * data->philo_nb);
	if (data->philo == NULL)
		error_exit(MALLOC, 1);
	while (i < data->philo_nb)
	{
		data->philo[i].philo_id = i + 1;
		data->philo[i].meals = 0;
		data->philo[i].data = data;
		data->philo[1].is_full = FALSE;
		select_forks(data, i);
		if (pthread_mutex_init(&data->philo[i].philo_mutex, NULL) != 0)
			error_exit(MUTEX, 2);
		i++;
	}
	return (TRUE);
}

t_bool	init_data(t_data *data, char **argv, int arc)
{
	data->philo_nb = ft_atol(argv[1]);
	data->time_die = ft_atol(argv[2]);
	data->time_eat = ft_atol(argv[3]);
	data->time_sleep = ft_atol(argv[4]);
	data->dead_flag = FALSE;
	data->all_ready = FALSE;
	data->philo_running = 0;
	if (arc == 5)
		data->meals_nb = -1;
	else
		data->meals_nb = ft_atol(argv[5]);
	if (!init_mutex(data))
		return (FALSE);
	if (!init_philo(data))
		return (FALSE);
	return (TRUE);
}
