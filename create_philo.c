/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_philo.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcharlet <lcharlet@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/21 00:36:09 by lcharlet          #+#    #+#             */
/*   Updated: 2022/01/03 17:50:25 by lcharlet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	*func_for_th(void *temp)
{
	t_philo	*philo;

	philo = (t_philo *)temp;
	if (philo->ph_id % 2 == 0)
		usleep(200);
	while (1)
	{
		philo_eat(philo, philo->data);
		philo->count_eating++;
		if (philo->count_eating == philo->data->time_must_eat)
		{
			philo->is_fed_up = 1;
			return NULL;
		}
		philo_sleep(philo, philo->data);
		philo_think(philo, philo->data);
	}
	return (NULL);
}

int	create_philo(t_philo *philo)
{
	int	res;
	int	id;

	id = 0;
	while (id < philo->data->num_of_philos)
	{
		philo[id].ph_id = id;
		res = pthread_create(&(philo[id].ph_th),
				NULL, func_for_th, (void *)(&philo[id]));
		if (res != 0)
			return (error("Thread was not created\n"));
		id++;
	}
	return (0);
}

void	close_philo(t_philo *philo)
{
	int	res;
	int	id;

	id = 0;
	while (id < philo->data->num_of_philos)
	{
		philo[id].ph_id = id;
		res = pthread_detach(philo[id].ph_th);
		if (res != 0)
			error("Thread detach failed!\n");
		id++;
	}
}
