/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_usleep.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcharlet <lcharlet@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/21 00:36:19 by lcharlet          #+#    #+#             */
/*   Updated: 2022/01/03 16:44:56 by lcharlet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	ft_usleep(t_data *data, int time)
{
	long	till_time;

	get_start_time(data, 0);
	till_time = data->cur_time_ml + time;
	while (data->cur_time_ml < till_time)
	{
		usleep(150);
		get_start_time(data, 0);
	}
}
