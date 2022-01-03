/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_to_die.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcharlet <lcharlet@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/21 00:37:03 by lcharlet          #+#    #+#             */
/*   Updated: 2022/01/03 17:54:57 by lcharlet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	check_to_die(t_philo *philo, t_data *data)
{
	int				id;
	unsigned long	cur_time;

	id = 0;
	usleep(200);
	// printf("%ld\n", data->cur_time_ml);
	// printf("%ld\n", data->start_time_ml);
	// printf("%d\n", data->philos_fed_up);
	while (1)
	{
		if (id == data->num_of_philos)
			id = 0;
		pthread_mutex_lock(&(data->mutex_for_eat));
		get_start_time(data, 0);
		cur_time = data->cur_time_ml - data->start_time_ml;
		if (philo[id].is_fed_up == 0 &&
			(cur_time - philo[id].prev_time_eat_ml > (unsigned long)data->time_to_die))
		{
			write_status(philo->data, philo->ph_id, DIED);
			pthread_mutex_lock(&(data->mutex_for_write));
			return ;
		}
		pthread_mutex_unlock(&(data->mutex_for_eat));
		if (philo[id].is_fed_up == 1)
		{
			// printf("%d\n", data->philos_fed_up);
			(data->philos_fed_up)++;
			// printf("%d\n", data->philos_fed_up);
		}
		if (data->philos_fed_up == data->num_of_philos)
		{
			return ;
		}
		id++;
	}
}
