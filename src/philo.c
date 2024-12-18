/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apaterno <apaterno@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/26 15:09:29 by apaterno          #+#    #+#             */
/*   Updated: 2024/12/02 16:21:16 by apaterno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/philo.h"

void	lone_philo(t_philo *philos)
{
	t_philo	*philo;

	philo = (t_philo *)philos;
	set_safe_long(&philo->philo_mutex, &philo->last_meal, get_date_time());
	ft_print_state(philo, FORK1);
	while ((get_date_time() - philo->last_meal) <= philo->data->time_die)
		usleep(200);
	ft_print_state(philo, DIED);
}

t_bool	dead_loop(t_data *data)
{
	return (get_safe_bool(&data->read_table, &data->dead_flag));
}

void	start_sleeping(t_philo *philo)
{
	ft_print_state(philo, SLEEP);
	ft_usleep(philo->data->time_sleep);
}

void	star_eating(t_philo *philo)
{
	pthread_mutex_lock(&philo->first_fork->fork);
	ft_print_state(philo, FORK1);
	pthread_mutex_lock(&philo->second_fork->fork);
	ft_print_state(philo, FORK2);
	set_safe_long(&philo->philo_mutex, &philo->last_meal, get_date_time());
	philo->meals++;
	ft_print_state(philo, EAT);
	ft_usleep(philo->data->time_eat);
	if (philo->data->meals_nb > 0 && philo->meals == philo->data->meals_nb)
		set_safe_bool(&philo->philo_mutex, &philo->is_full, TRUE);
	pthread_mutex_unlock(&philo->first_fork->fork);
	pthread_mutex_unlock(&philo->second_fork->fork);
}

void	*philo_rutine(void *philos)
{
	t_philo	*philo;

	philo = (t_philo *)philos;
	while (!get_safe_bool(&philo->data->read_table, &philo->data->all_ready))
		;
	set_safe_long(&philo->philo_mutex, &philo->last_meal, get_date_time());
	increase_safe_long(&philo->data->read_table, &philo->data->philo_running);
	while (!dead_loop(philo->data) && !philo->is_full)
	{
		if (philo->is_full)
			break ;
		star_eating(philo);
		start_sleeping(philo);
		ft_print_state(philo, THINK);
	}
	return (NULL);
}
