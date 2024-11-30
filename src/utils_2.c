/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apaterno <apaterno@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/27 11:51:17 by apaterno          #+#    #+#             */
/*   Updated: 2024/11/30 12:59:36 by apaterno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/philo.h"

void	increase_safe_long(pthread_mutex_t *mutex, long *value)
{
	pthread_mutex_lock(mutex);
	(*value)++;
	pthread_mutex_unlock(mutex);
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
