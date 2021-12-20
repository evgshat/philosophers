#include "philo.h"

void	init_philo(t_data *data, t_philo *philo)
{
	int	id;

	id = -1;
	while (++id < data->num_of_philos)
	{
		philo[id].fork_left_id = id;
		philo[id].fork_right_id = (id + (data->num_of_philos - 1)) % data->num_of_philos;
		philo[id].data = data;
		philo[id].count_eating = 0;
        philo[id].prev_time_eat_ml = 0;
		philo[id].last_eat = data->start_time;
	}
}