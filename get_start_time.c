#include "philo.h"

static void ft_gettimeofday(struct timeval *time, long *ml_time)
{
	int	res;

	res = gettimeofday(time, NULL);
	if (res != 0)
		error("Can`t get time of day\n");
	*ml_time = (time->tv_sec * 1000) + (time->tv_usec / 1000);
}

void	get_start_time(t_data *data, int flag)
{
	if (flag == 1)
		ft_gettimeofday(&data->start_time, &data->start_time_ml);
	else
		ft_gettimeofday(&data->current_time, &data->cur_time_ml);
}