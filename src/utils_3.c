/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_3.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apaterno <apaterno@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/27 16:47:39 by apaterno          #+#    #+#             */
/*   Updated: 2024/11/30 13:09:45 by apaterno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/philo.h"

void	error_exit(char *msg, int exit_code)
{
	ft_putstr_fd(msg, STDERR_FILENO);
	exit(exit_code);
}
void	ft_print_state(t_philo *philo, char *state)
{
	ssize_t	time;
	ssize_t	start_time;

	start_time = get_safe_long(&philo->philo_mutex, &philo->data->start_time);
	time = get_date_time() - start_time;
	pthread_mutex_lock(&philo->data->print);
	if (!dead_loop(philo->data))
		printf("%ld %d %s\n", time, philo->philo_id, state);
	pthread_mutex_unlock(&philo->data->print);
}
