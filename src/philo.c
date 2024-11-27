/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apaterno <apaterno@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/26 15:09:29 by apaterno          #+#    #+#             */
/*   Updated: 2024/11/27 11:48:05 by apaterno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/philo.h"

bool	dead_loop(t_philo *philo)
{
	return (get_safe_bool(&philo->data->dead, &philo->data->dead_flag));
}

bool	select_fork(t_philo *philo)
{
	if (philo->philo_id % 2 == 0)
		pthread_mutex_lock(&philo->right_fork->fork);
	else
		pthread_mutex_lock(&philo->left_fork->fork);
	ft_print_state(philo, FORK);
	if (philo->philo_id % 2 == 0)
		pthread_mutex_lock(&philo->left_fork->fork);
	else
		pthread_mutex_lock(&philo->right_fork->fork);
	ft_print_state(philo, FORK);
	return (TRUE);
}

void	start_sleeping(t_philo *philo)
{
	ft_print_state(philo, SLEEP);
	ft_usleep(philo->data->time_sleep);
}

bool	star_eating(t_philo *philo)
{
	ft_print_state(philo, EAT);
	pthread_mutex_lock(&philo->data->meals);
	philo->last_meal = get_date_time();
	philo->meals++;
	pthread_mutex_unlock(&philo->data->meals);
	ft_usleep(philo->data->time_eat);
	pthread_mutex_unlock(&philo->left_fork->fork);
	pthread_mutex_unlock(&philo->right_fork->fork);
	return (TRUE);
}

void	*philo_rutine(void *philos)
{
	t_philo	*philo;

	philo = (t_philo*)philos;
	while (!get_safe_bool(&philo->data->syncro, &philo->data->all_ready));
	set_safe_long(&philo->data->time, &philo->last_meal, get_date_time());
	// while(!dead_loop(philo))
	// {
	// 	select_fork(philo);
	// 	star_eating(philo);
	// 	start_sleeping(philo);
	// 	ft_print_state(philo,THINK);
	// }
	//int i = 0;
	while (!dead_loop(philo))
	{
		select_fork(philo);
		star_eating(philo);
		start_sleeping(philo);
		ft_print_state(philo, THINK);
		//i++;
	}
	//printf("philo %d ha terminado\n",philo->philo_id);
	return (NULL);
}