#include "philo.h"

void philo_sleep(t_philo *philo, t_data *data)
{
	write_status(data, philo->ph_id, SLEEP);
	ft_usleep(data, data->time_to_sleep);
}