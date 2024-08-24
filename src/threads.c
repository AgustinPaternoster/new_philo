#include "../inc/philo.h"
static void pthreads_join(t_data * data)
{
    int i;

    i = 0;
    while(i < data->philo_nb)
    {
        pthread_join(data->philo[i].thread_id, NULL);
        i++;
    }
}

bool start_simulation(t_data *data)
{
	int i;

    i = 0;
    
    
    while (i < data->philo_nb)
    {
        if (pthread_create(&data->philo[i].thread_id,NULL,philo_rutine,(void*)&data->philo[i]) != 0)
            return (FALSE);
        data->philo[i].last_meal = get_date_time();
        i++;
    }
    set_safe_long(&data->time,&data->start_time,get_date_time());
    set_safe_bool(&data->syncro,&data->all_ready,TRUE);
    pthreads_join(data);
	printf("salida treads");
    return (TRUE);
}