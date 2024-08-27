#include "../inc/philo.h"
bool dead_loop(t_philo *philo)
{
    return(get_safe_bool(&philo->data->dead, &philo->data->dead_flag));
}

void select_fork(t_philo *philo)
{
	if (philo->philo_id % 2 == 0)
		pthread_mutex_lock(&philo->right_fork->fork);
	else
		pthread_mutex_lock(&philo->left_fork->fork);
	ft_print_state(philo,FORK);
	if (philo->philo_id % 2 == 0)
		pthread_mutex_lock(&philo->left_fork->fork);
	else
		pthread_mutex_lock(&philo->right_fork->fork);
	ft_print_state(philo,FORK);
}

bool star_eating(t_philo *philo)
{
	select_fork(philo);
	ft_print_state(philo,EAT);
	pthread_mutex_lock(&philo->data->meals);
	philo->last_meal = get_date_time();
	philo->meals++;
	pthread_mutex_unlock(&philo->data->meals);
	ft_usleep(philo->data->time_eat);
	pthread_mutex_unlock(&philo->left_fork->fork);
	pthread_mutex_unlock(&philo->right_fork->fork);
	return (TRUE);
}

void *philo_rutine(void *philos)
{
	t_philo *philo;

	philo = (t_philo*)philos;
	while(!get_safe_bool(&philo->data->syncro,&philo->data->all_ready));
	while(!dead_loop(philo))
	{
		star_eating(philo);

	}

	
	return (NULL);
}