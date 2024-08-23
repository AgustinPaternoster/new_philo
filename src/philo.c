#include "../inc/philo.h"

void *philo_rutine(void *philos)
{
	t_philo *philo;
	
	
	philo = (t_philo*)philos;
	while(!get_safe_bool(&philo->data->syncro,&philo->data->all_ready));
	if (philo->philo_id == 5)
		sleep(2);
	ft_print_state(philo,EAT);
	return (NULL);
}