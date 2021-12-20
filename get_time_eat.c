/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_time_eat.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcharlet <lcharlet@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/21 00:36:31 by lcharlet          #+#    #+#             */
/*   Updated: 2021/12/21 00:46:44 by lcharlet         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	get_time_eat(t_philo *philo)
{
	struct timeval	prev_time_eat;

	gettimeofday(&prev_time_eat, NULL);
	philo->prev_time_eat_ml = (prev_time_eat.tv_sec * 1000)
		+ (prev_time_eat.tv_usec / 1000);
}
