#include "../inc/philo.h"

bool check_life(t_data *data)
{
    int i;
    long last_meal;

    i = 0;
    while (i < data->philo_nb)
    {
        last_meal = get_safe_long(&data->meals,&data->philo[i].last_meal);
    
        if (get_date_time() - last_meal > data->time_die)
        {
            printf("el %d tiempo %ld\n", data->philo[i].philo_id, get_date_time() - last_meal);
            return (FALSE);
        }
        i++;
    }
    return (TRUE);
}


void *monitor_rutine(void *thread_data)
{
    t_data *data;
    data = (t_data *)thread_data;
    (void)data;
    while(1)
    {
        if(!check_life(data))
        {
            //printf("philo muerto\n");
           return(NULL);
        }
    }
    
    return (NULL);
}