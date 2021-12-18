#include "philo.h"

int main(int argc, char **argv)
{
	t_philo	philo[200];
	t_data	data;

	parsing(argc, argv, &data);
	printf("parsing is ok\n");
	get_start_time(&data, 1);
	init_forks(&data);
	init_philo(&data, philo);
	create_philo(philo);
	int i = -1;
	while (++i < data.num_of_philos)
		pthread_join(philo[i].ph_th, NULL);
}
