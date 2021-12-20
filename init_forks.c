/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_forks.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcharlet <lcharlet@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/21 00:36:35 by lcharlet          #+#    #+#             */
/*   Updated: 2021/12/21 00:41:06 by lcharlet         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static void	create_mutex(pthread_mutex_t *mutex)
{
	int	res;

	res = pthread_mutex_init(mutex, NULL);
	if (res != 0)
		error("Mutex was not created\n");
}

void	init_forks(t_data *data)
{
	int	id;

	id = -1;
	while (++id < data->num_of_philos)
		create_mutex(&data->mutex_forks[id]);
	create_mutex(&data->mutex_for_write);
	create_mutex(&data->mutex_for_eat);
}
