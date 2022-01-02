/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcharlet <lcharlet@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/21 00:37:06 by lcharlet          #+#    #+#             */
/*   Updated: 2022/01/02 18:07:46 by lcharlet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	check_args(t_data *data)
{
	if (data->num_of_philos <= 0 || data->time_to_die <= 0
		|| data->time_to_eat <= 0 || data->time_to_sleep <= 0)
		error("Args is not correct\n");
	if (data->num_of_philos > 200)
		error("Too many philos\n");
	return (0);
}

void parsing(int argc, char **argv, t_data *data)
{
	if (argc < 5 || argc > 6)
		error("Args is not correct\n");
	data->num_of_philos = ft_atoi(argv[1]);
	data->time_to_die = ft_atoi(argv[2]);
	data->time_to_eat = ft_atoi(argv[3]);
	data->time_to_sleep = ft_atoi(argv[4]);
	if (argv[5])
		data->time_must_eat = ft_atoi(argv[5]);
	else
		data->time_must_eat = -1;
	check_args(data);
}
