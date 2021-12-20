/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_eat.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcharlet <lcharlet@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/21 00:37:10 by lcharlet          #+#    #+#             */
/*   Updated: 2021/12/21 00:42:31 by lcharlet         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	philo_eat(t_philo *philo, t_data *data)
{
	pthread_mutex_lock(&(data->mutex_forks[philo->fork_left_id]));
	write_status(data, philo->ph_id, FORK);
	pthread_mutex_lock(&(data->mutex_forks[philo->fork_right_id]));
	write_status(data, philo->ph_id, FORK);
	if (philo->count_eating == 0)
		observer(philo, data, 0);
	if (philo->count_eating > 0)
		observer(philo, data, 1);
	write_status(data, philo->ph_id, EAT);
	ft_usleep(data, data->time_to_eat);
	get_time_eat(philo);
	pthread_mutex_unlock(&(data->mutex_forks[philo->fork_left_id]));
	pthread_mutex_unlock(&(data->mutex_forks[philo->fork_right_id]));
}
