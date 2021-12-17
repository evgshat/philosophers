#include "philo.h"

int main(int argc, char **argv)
{
	t_philo	philo[200];
	t_data	data;

	parsing(argc, argv, philo);
	printf("parsing is ok\n");
	get_start_time(philo); //
	printf("%ld", philo->data.start_time_ml);
	create_philo(philo);
	init_philo()
}
