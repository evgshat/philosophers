#include "philo.h"

void *func_for_th(void *temp)
{
	t_philo	*philo;

	philo = (t_philo *)temp;
	printf("Thread %d was created\n", philo->ph_id);
	return (NULL);
}

void	create_philo(t_data *data, t_philo *philo)
{
	int	res_of_create_th;
	int	count;

	philo->ph_id = 0;
	count = 0;

	while (count < data->num_of_philos)
	{
		philo->ph_id++;
		res_of_create_th = pthread_create(&philo->th, NULL, func_for_th, (void *)(&philo->th));
		usleep(200);
		if (res_of_create_th != 0)
			error("Thread was not created\n");
		count++;
	}
}
