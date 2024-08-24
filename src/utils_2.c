#include "../inc/philo.h"

void ft_print_state(t_philo *philo,char *state, int forknb)
{
    ssize_t time;
    ssize_t start_time;

    start_time = get_safe_long(&philo->data->time,&philo->data->start_time);
    time = get_date_time() - start_time;
    pthread_mutex_lock(&philo->data->print);
    //printf("time :%ld start time%ld \n",time , start_time);
    printf("%ld %d %s forknb:%d \n",time,philo->philo_id, state , forknb);
    pthread_mutex_unlock(&philo->data->print);
}

bool get_safe_bool(pthread_mutex_t *mutex, bool *boolean)
{
    bool result;
    pthread_mutex_lock(mutex);
    result = *boolean;
    pthread_mutex_unlock(mutex);
    return (result);
}

void set_safe_bool(pthread_mutex_t *mutex, bool *var,bool value)
{
    pthread_mutex_lock(mutex);
    *var = value;
    pthread_mutex_unlock(mutex);
}

long get_safe_long(pthread_mutex_t *mutex, long *var)
{
    long result;
    pthread_mutex_lock(mutex);
    result = *var;
    pthread_mutex_unlock(mutex);
    return (result);
}

void set_safe_long(pthread_mutex_t *mutex, long *var, long value)
{
    pthread_mutex_lock(mutex);
    *var = value;
    pthread_mutex_unlock(mutex);
}