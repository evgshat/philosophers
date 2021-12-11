#include "philo.h"

void	func_a(void *idx)
{
	printf("%d", idx);
}

int	*create_thread(int num, t_data *data)
{
	t_philo	philo[data->num_of_philos];
	int		idx;
	int		res_of_create_pth;

	idx = 0;
	while (idx != 2)
	{
		philo[idx]->ph_id = idx;
		res_of_create_pth = pthread_create(&philo.th[idx], NULL, func_a, (void *)(&philo));
		if (res_of_create_pth != 0)
			error("Not create thread\n"); //могу ли я тут номер потока передать?
		idx++;
	}
}

void	create_philo(t_data *data)
{
	int		num;
	t_data	data;

	num = data->num_of_philos;
	while (num > 0)
	{
		create_philo(num, &data);
		num--;
	}
}
