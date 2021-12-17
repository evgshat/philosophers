#include "philo.h"

void *func_for_th(void *temp)
{
	t_philo	*philo;

	philo = (t_philo *)temp;
	printf("Thread %d was created\n", philo->ph_id);
	return (NULL);
}

void	create_philo(t_philo *philo)
{
	int	res;
	int	id;

	id = 0;
	while (id < philo->data.num_of_philos)
	{
		philo[id].ph_id = id;
		res = pthread_create(&(philo[id].th), NULL, func_for_th, (void *)(&philo[id]));
		usleep(200);
		if (res != 0)
			error("Thread was not created\n");
		id++;
	}
}
