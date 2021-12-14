#include "philo.h"

int main(int argc, char **argv)
{
	t_data	data;
	t_philo	philo;

	parsing(argc, argv, &data);
	printf("parsing is ok\n");
	create_philo(&data, &philo);
}
