/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_start_time.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcharlet <lcharlet@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/21 00:36:27 by lcharlet          #+#    #+#             */
/*   Updated: 2022/01/03 17:22:02 by lcharlet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static int	ft_gettimeofday(struct timeval *time, unsigned long *ml_time)
{
	int	res;

	res = gettimeofday(time, NULL);
	if (res != 0)
		return (error("Can`t get time of day\n"));
	*ml_time = (time->tv_sec * 1000) + (time->tv_usec / 1000);
	return (0);
}

int	get_start_time(t_data *data, int flag)
{
	if (flag == 1)
		return (ft_gettimeofday(&data->start_time, &data->start_time_ml));
	else
		return (ft_gettimeofday(&data->current_time, &data->cur_time_ml));
}
