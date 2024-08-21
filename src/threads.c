#include "../inc/philo.h"
static void pthreads_join(t_data * data)
{
    int i;

    i = 0;
    while(i < data->philo_nb)
    {
        pthread_join(data->philo[i].thread, NULL);
        i++;
    }
}

bool start_simulation(t_data *data)
{
	int i;

    i = 0;
    
    data->start_time = get_date_time();
    while (i < data->philo_nb)
    {
        if (pthread_create(&data->philo[i].thread_id,NULL,philo_rutine,(void*)&data->philo[i]) != 0)
            return (FALSE);
        data->philo[i].last_meal = get_date_time();
        i++;
    }
	printf("salida treads");
    return (TRUE);
}