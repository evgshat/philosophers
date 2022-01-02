/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_start_time.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcharlet <lcharlet@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/21 00:36:27 by lcharlet          #+#    #+#             */
/*   Updated: 2022/01/02 18:57:24 by lcharlet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static void	ft_gettimeofday(struct timeval *time, long *ml_time)
{
	int	res;

	res = gettimeofday(time, NULL);
	if (res != 0)
		error("Can`t get time of day\n");
	*ml_time = (time->tv_sec * 1000) + (time->tv_usec / 1000);
}

void	get_start_time(t_data *data, int flag)
{
	if (flag == 1)
		ft_gettimeofday(&data->start_time, &data->start_time_ml);
	else
	{
		ft_gettimeofday(&data->current_time, &data->cur_time_ml);
	}
}
