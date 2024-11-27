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

static bool	init_mutex(t_data *data)
{
	int	i;

	i = 0;
	data->forks = malloc(sizeof(t_forks) * data->philo_nb);
	if (data->forks == NULL)
		return (FALSE);
	while (i < data->philo_nb)
	{
		data->forks[i].fork_nb = i;
		if (pthread_mutex_init(&data->forks[i].fork, NULL) != 0)
			return (FALSE);
		i++;
	}
	if (pthread_mutex_init(&data->print, NULL) != 0)
		return (FALSE);
	if (pthread_mutex_init(&data->dead, NULL) != 0)
		return (FALSE);
	if (pthread_mutex_init(&data->meals, NULL) != 0)
		return (FALSE);
	if (pthread_mutex_init(&data->time, NULL) != 0)
		return (FALSE);
	if (pthread_mutex_init(&data->syncro, NULL) != 0)
		return (FALSE);
	return (TRUE);
}

static bool	init_philo(t_data *data)
{
	int	i;

	i = 0;
	data->philo = malloc(sizeof(t_philo) * data->philo_nb);
	if (data->philo == NULL)
		return (FALSE);
	while (i < data->philo_nb)
	{
		data->philo[i].philo_id = i + 1;
		data->philo[i].meals = 0;
		data->philo[i].data = data;
		data->philo[i].right_fork = &data->forks[i];
		data->philo[i].left_fork = &data->forks[(i + 1) % data->philo_nb];
		i++;
	}
	return (TRUE);
}

bool	init_data(t_data *data, char **argv, int arc)
{
	data->philo_nb = ft_atol(argv[1]);
	data->time_die = ft_atol(argv[2]);
	data->time_eat = ft_atol(argv[3]);
	data->time_sleep = ft_atol(argv[4]);
	data->dead_flag = FALSE;
	data->all_ready = FALSE;
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
