/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   threads.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apaterno <apaterno@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/27 11:49:18 by apaterno          #+#    #+#             */
/*   Updated: 2024/11/30 13:21:43 by apaterno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/philo.h"

static void	pthreads_join(t_data *data)
{
	int	i;

	i = 0;
	while (i < data->philo_nb)
	{
		pthread_join(data->philo[i].thread_id, NULL);
		i++;
	}
	set_safe_bool(&data->read_table, &data->dead_flag, TRUE);
	pthread_join(data->monitor, NULL);
}

t_bool	start_simulation(t_data *data)
{
	int	i;

	i = 0;
	while (i < data->philo_nb)
	{
		if (pthread_create(&data->philo[i].thread_id, NULL,
				philo_rutine, (void*)&data->philo[i]) != 0)
			error_exit(THREAD, 3);
		i++;
	}
	data->start_time = get_date_time();
	set_safe_bool(&data->read_table, &data->all_ready, TRUE);
	if (pthread_create(&data->monitor, NULL, monitor_rutine, (void *)data) != 0)
		error_exit(THREAD, 3);
	pthreads_join(data);
	printf("End of simulation\n");
	return (TRUE);
}
