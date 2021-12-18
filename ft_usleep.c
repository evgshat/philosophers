#include "philo.h"

void ft_usleep(t_data *data, int time)
{
	long till_time;

	get_start_time(data, 0);
	till_time = data->cur_time_ml + time;
	while(data->cur_time_ml <= till_time)
	{
		usleep(150);
		get_start_time(data, 0);
	}
}