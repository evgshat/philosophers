#include "philo.h"

void	get_start_time(t_philo *philo)
{
	int	res;

	res = gettimeofday(&philo->data.start_time, NULL); // 0 - при успехе, -1 - при неуспехе
	if (res != 0)
		error("Can`t get time of day\n");
	philo->data.start_time_ml = (philo->data.start_time.tv_sec * 1000) + (philo->data.start_time.tv_usec / 1000);
	printf("ok\n");
}