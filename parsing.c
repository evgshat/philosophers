#include "philo.h"

int	parsing(int argc, char **argv, t_data *data)
{
	if (argc < 5)
		error("Args is not correct\n");
	data->num_of_philos = ft_atoi(argv[1]);
	data->time_to_die = ft_atoi(argv[2]);
	data->time_to_eat = ft_atoi(argv[3]);
	data->time_to_sleep = ft_atoi(argv[4]);
	// data->time_must_eat = ft_atoi(argv[5]);

	return (0);
}