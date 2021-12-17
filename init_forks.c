#include "philo.h"

void	init_forks(t_data *data)
{
	int	id;
	int	res;

	id = -1;
	while (++id < data->num_of_philos)
	{
		res = pthread_mutex_init(&data->mutex_forks[id], NULL);
		if (res != 0)
			error("Mutex was not created\n");
	}
}