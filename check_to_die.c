/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_to_die.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcharlet <lcharlet@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/21 00:37:03 by lcharlet          #+#    #+#             */
/*   Updated: 2022/01/02 19:01:06 by lcharlet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	check_to_die(t_philo *philo, t_data *data)
{
	int		id;
	long	cur_time;

	id = 0;
	usleep(200);
	// printf("%ld\n", data->cur_time_ml);
	// printf("%ld\n", data->start_time_ml);
	while (1)
	{
		get_start_time(data, 0);
		cur_time = data->cur_time_ml - data->start_time_ml;
		if (id > data->num_of_philos)
			id = 0;
		pthread_mutex_lock(&(data->mutex_for_eat));
		if (cur_time - philo[id].prev_time_eat_ml > data->time_to_die)
		{
			// printf("%ld\n", data->cur_time_ml);
			write_status(philo->data, philo->ph_id, DIED);
			pthread_mutex_lock(&(data->mutex_for_write));
			exit (1);
		}
		else
			pthread_mutex_unlock(&(data->mutex_for_eat));
		id++;
	}
}
