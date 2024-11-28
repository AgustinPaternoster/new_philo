/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apaterno <apaterno@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/27 11:51:17 by apaterno          #+#    #+#             */
/*   Updated: 2024/11/28 17:12:35 by apaterno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/philo.h"

void	ft_print_state(t_philo *philo, char *state)
{
	ssize_t	time;
	ssize_t	start_time;

	start_time = get_safe_long(&philo->philo_mutex,
				&philo->data->start_time);
	time = get_date_time() - start_time;
	pthread_mutex_lock(&philo->data->print);
	if (!dead_loop(philo->data))
		printf("%ld %d %s\n", time, philo->philo_id, state);
	pthread_mutex_unlock(&philo->data->print);
}

t_bool	get_safe_bool(pthread_mutex_t *mutex, t_bool *boolean)
{
	t_bool	result;

	pthread_mutex_lock(mutex);
	result = *boolean;
	pthread_mutex_unlock(mutex);
	return (result);
}

void	set_safe_bool(pthread_mutex_t *mutex, t_bool *var, t_bool value)
{
	pthread_mutex_lock(mutex);
	*var = value;
	pthread_mutex_unlock(mutex);
}

long	get_safe_long(pthread_mutex_t *mutex, long *var)
{
	long	result;

	pthread_mutex_lock(mutex);
	result = *var;
	pthread_mutex_unlock(mutex);
	return (result);
}

void	set_safe_long(pthread_mutex_t *mutex, long *var, long value)
{
	pthread_mutex_lock(mutex);
	*var = value;
	pthread_mutex_unlock(mutex);
}
