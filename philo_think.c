#include "philo.h"

void philo_think(t_philo *philo, t_data *data)
{
	write_status(data, philo->ph_id, THINK);
}