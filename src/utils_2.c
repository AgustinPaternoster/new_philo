#include "../inc/philo.h"

void ft_print_state(t_philo *philo,char *state)
{
    ssize_t time;
    pthread_mutex_lock(&philo->data->print);
    time = get_date_time() - philo->data->start_time;
    printf("%ld %d %s\n",time,philo->philo_id, state);
    pthread_mutex_unlock(&philo->data->print);
}

