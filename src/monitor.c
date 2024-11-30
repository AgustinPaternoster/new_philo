/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   monitor.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apaterno <apaterno@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/26 15:06:28 by apaterno          #+#    #+#             */
/*   Updated: 2024/11/26 15:06:28 by apaterno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/philo.h"

static t_bool	philo_run(pthread_mutex_t *mutex, long *threads, long philo_nb)
{
	t_bool	ret;

	ret = FALSE;
	pthread_mutex_lock(mutex);
	if (*threads == philo_nb)
		ret = TRUE;
	pthread_mutex_unlock(mutex);
	return (ret);
}

static t_bool	is_dead(t_philo *philo)
{
	long	result;
	long	time_to_die;

	if (get_safe_bool(&philo->philo_mutex, &philo->is_full))
		return (FALSE);
	result = get_date_time() - get_safe_long(&philo->philo_mutex,
			&philo->last_meal);
	time_to_die = philo->data->time_die;
	if (result > time_to_die)
		return (TRUE);
	return (FALSE);
}

void	*monitor_rutine(void *thread_data)
{
	t_data	*data;
	int		i;

	data = (t_data *)thread_data;
	while (!philo_run(&data->read_table, &data->philo_running, data->philo_nb))
		;
	while (!dead_loop(data))
	{
		i = 0;
		while (i < data->philo_nb && !dead_loop(data))
		{
			if (is_dead(&data->philo[i]))
			{
				ft_print_state(&data->philo[i], DIED);
				set_safe_bool(&data->read_table, &data->dead_flag, TRUE);
			}
			i++;
		}
	}
	return (NULL);
}
