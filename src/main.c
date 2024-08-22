#include "../inc/philo.h"

void clean_close(t_data *data)
{
    int i;
    while (i < data->philo_nb)
    {
        pthread_mutex_destroy(&data->forks[i].fork);
        i++;
    }
    pthread_mutex_destroy(&data->print);
    pthread_mutex_destroy(&data->dead);
    pthread_mutex_destroy(&data->meals);
	free(data->forks);
	free(data->philo);
}

static bool check_nb(int arc, char **argv)
{
	int i;
	int j;
	long nb;

	i = 1;
	while(i < arc)
	{
		j = 0;
		nb = atol(argv[i]);
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

static bool check_arguments(int arg, char **argv )
{
	if (arg < 5 || arg > 6)
		return (FALSE);
	if (!check_nb(arg,argv))
		return (FALSE);
	if (arg == 6 && atol(argv[5]) < 1)
		return (FALSE);
	return (TRUE);
}


int main(int arc , char **argv)
{
    t_data data;

    (void)data;
    if (!check_arguments(arc, argv))
		return (printf(RULES),1);
    if (!init_data(&data, argv,arc))
		return (printf("Error\n"),clean_close(&data),1);
	if (!start_simulation(&data))
		return (printf("Error\n"),clean_close(&data),1);
	clean_close(&data);
    return (0);
}