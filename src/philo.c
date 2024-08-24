#include "../inc/philo.h"
bool dead_loop(t_philo *philo)
{
    return(get_safe_bool(&philo->data->dead, &philo->data->dead_flag));
}

void select_fork(t_philo *philo)
{
	if (philo->philo_id % 2 == 0)
	{
		pthread_mutex_lock(&philo->right_fork->fork);
		ft_print_state(philo,FORK,philo->right_fork->fork_nb);
		pthread_mutex_lock(&philo->left_fork->fork);
		ft_print_state(philo,FORK,philo->left_fork->fork_nb);
	}
	else
	{
		pthread_mutex_lock(&philo->left_fork->fork);
		ft_print_state(philo,FORK,philo->left_fork->fork_nb);
		pthread_mutex_lock(&philo->right_fork->fork);
		ft_print_state(philo,FORK,philo->right_fork->fork_nb);
	}

}
void *philo_rutine(void *philos)
{
	t_philo *philo;
	
	
	philo = (t_philo*)philos;
	while(!get_safe_bool(&philo->data->syncro,&philo->data->all_ready));
	// while(!dead_loop(philo)
	// {

	// }
	select_fork(philo);
	ft_usleep(200);
	pthread_mutex_unlock(&philo->left_fork->fork);
	pthread_mutex_unlock(&philo->right_fork->fork);
	return (NULL);
}