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

bool	check_life(t_data *data)
{
	int		i;
	long	result;
	 //long last_meal;

	i = 0;
	while (i < data->philo_nb)
	{
        //last_meal = get_safe_long(&data->meals,&data->philo[i].last_meal);
		result = get_date_time() - get_safe_long(&data->meals,
				&data->philo[i].last_meal);
		if (result > data->time_die)
		{
			set_safe_bool(&data->dead, &data->dead_flag, TRUE);
			printf("%ld,\n", result);
			ft_print_state(&data->philo[i], DIED);
			exit(0);
			return (FALSE);
		}
		i++;
	}
	return (TRUE);
}

void	*monitor_rutine(void *thread_data)
{
	t_data	*data;

	data = (t_data *)thread_data;
	(void)data;
	while (1)
	{
		if (!check_life(data))
		{
			//printf("philo muerto\n");
			return (NULL);
		}
	}
	return (NULL);
}
