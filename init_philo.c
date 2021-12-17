#include "philo.h"

void	init_philo(t_data *data, t_philo *philo)
{
	int	id;

	id = -1;
	while (++id < data->num_of_philos)
	{
		philo[id].fork_left_id = id;
		philo[id].fork_right_id = (id + (data->num_of_philos - 1)) % data->num_of_philos;
		printf("left = %d right = %d\n", philo[id].fork_left_id, philo[id].fork_right_id);
	}
}