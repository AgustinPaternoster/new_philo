/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apaterno <apaterno@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/26 14:56:30 by apaterno          #+#    #+#             */
/*   Updated: 2024/11/26 14:56:30 by apaterno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/philo.h"

void	clean_close(t_data *data)
{
	int	i;

	i = 0;
	while (i < data->philo_nb)
	{
		pthread_mutex_destroy(&data->forks[i].fork);
		pthread_mutex_destroy(&data->philo[i].philo_mutex);
		i++;
	}
	pthread_mutex_destroy(&data->print);
	pthread_mutex_destroy(&data->read_table);
	free(data->forks);
	free(data->philo);
}

static t_bool	check_nb(int arc, char **argv)
{
	int		i;
	int		j;
	long	nb;

	i = 1;
	while (i < arc)
	{
		j = 0;
		nb = ft_atol(argv[i]);
		while (argv[i][j])
		{
			if (!ft_isnumber(argv[i][j]))
				return (FALSE);
			j++;
		}
		if (nb < 0)
			return (FALSE);
		if (nb < INT_MIN || nb > INT_MAX)
			return (FALSE);
		i++;
	}
	return (TRUE);
}

static t_bool	check_arguments(int arg, char **argv )
{
	if (arg < 5 || arg > 6)
		return (FALSE);
	if (!check_nb(arg, argv))
		return (FALSE);
	if (arg == 6 && ft_atol(argv[5]) < 1)
		return (FALSE);
	if ((ft_atol(argv[2]) < 60) || (ft_atol(argv[3]) < 60) || \
		(ft_atol(argv[4]) < 60))
		return (FALSE);
	return (TRUE);
}

int	main(int arc, char **argv)
{
	t_data	data;

	(void)data;
	if (!check_arguments(arc, argv))
		return (printf(RULES), 1);
	if (!init_data(&data, argv, arc))
		return (printf("Error\n"), clean_close(&data), 1);
	if (!start_simulation(&data))
		return (printf("Error\n"), clean_close(&data), 1);
	clean_close(&data);
	return (0);
}
