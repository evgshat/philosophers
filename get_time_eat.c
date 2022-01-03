/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_time_eat.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcharlet <lcharlet@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/21 00:36:31 by lcharlet          #+#    #+#             */
/*   Updated: 2022/01/03 17:10:46 by lcharlet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	get_time_eat(t_philo *philo)
{
	get_start_time(philo->data, 0);
	philo->prev_time_eat_ml = philo->data->cur_time_ml - philo->data->start_time_ml;

}
