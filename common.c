/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   common.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcharlet <lcharlet@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/21 00:35:47 by lcharlet          #+#    #+#             */
/*   Updated: 2022/01/02 18:46:32 by lcharlet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	write_status(t_data *data, int id, char *status)
{
	long	cur_time;

	get_start_time(data, 0);
	cur_time = data->cur_time_ml - data->start_time_ml;
	pthread_mutex_lock(&data->mutex_for_write);
	printf("%ld %d %s\n", cur_time, id + 1, status);
	pthread_mutex_unlock(&data->mutex_for_write);
}
