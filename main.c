/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcharlet <lcharlet@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/21 00:36:55 by lcharlet          #+#    #+#             */
/*   Updated: 2022/01/03 17:54:00 by lcharlet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	main(int argc, char **argv)
{
	t_philo	philo[200];
	t_data	data;

	if (parsing(argc, argv, &data) == -1 ||
	get_start_time(&data, 1) == -1 ||
	init_forks(&data) < 0 ||
	init_philo(&data, philo) == -1 ||
	create_philo(philo) == -1)
		return (-1);
	check_to_die(philo, &data);
}
