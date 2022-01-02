/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcharlet <lcharlet@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/21 00:36:55 by lcharlet          #+#    #+#             */
/*   Updated: 2022/01/02 18:20:49 by lcharlet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	main(int argc, char **argv)
{
	t_philo	philo[200];
	t_data	data;
	int		i;

	i = -1;
	parsing(argc, argv, &data);
	get_start_time(&data, 1);
	init_forks(&data);
	init_philo(&data, philo);
	create_philo(philo);
	check_to_die(philo, &data);
	// while (++i < data.num_of_philos)
	// 	pthread_join(philo[i].ph_th, NULL);
}
