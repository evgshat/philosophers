/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_forks.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcharlet <lcharlet@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/21 00:36:35 by lcharlet          #+#    #+#             */
/*   Updated: 2022/01/03 17:27:11 by lcharlet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static int	create_mutex(pthread_mutex_t *mutex)
{
	int	res;

	res = pthread_mutex_init(mutex, NULL);
	if (res != 0)
		return (error("Mutex was not created\n"));
	return (0);
}

int	init_forks(t_data *data)
{
	int	id;

	id = -1;
	while (++id < data->num_of_philos)
		if (create_mutex(&data->mutex_forks[id]) == -1)
			return (-1);
	return (create_mutex(&data->mutex_for_write) + create_mutex(&data->mutex_for_eat));
}
