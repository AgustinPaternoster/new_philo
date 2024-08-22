#include "../inc/philo.h"

void *philo_rutine(void *philos)
{
	t_philo *philo;
	
	philo = (t_philo*)philos;
	if (philo->philo_id == 5)
		sleep(2);
	printf("philo %d\n", philo->philo_id);
	return (NULL);
}