#include "philo.h"

int parsing(char **argv, t_data *data)
{
	int	i;
	int	j;

	i = 0;
	j = 0;

	data->num_of_philos = ft_atoi(argv[1]);
	data->time_to_die = ft_atoi(argv[2]);
	data->time_to_eat = ft_atoi(argv[3]);
	data->time_to_sleep = ft_atoi(argv[4]);
	data->time_to_sleep = ft_atoi(argv[5]);

	return (0);
}