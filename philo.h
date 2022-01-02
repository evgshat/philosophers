/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcharlet <lcharlet@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/21 00:48:06 by lcharlet          #+#    #+#             */
/*   Updated: 2022/01/02 18:21:07 by lcharlet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <pthread.h>
# include <sys/time.h>

# define FORK	"has taken a fork"
# define SLEEP	"is sleeping"
# define EAT		"is eating"
# define THINK	"is thinking"
# define DIED	"is died"

typedef struct s_data
{
	int				num_of_philos;
	int				time_to_die;
	int				time_to_eat;
	int				time_to_sleep;
	unsigned int				time_must_eat;
	struct timeval	start_time;
	struct timeval	current_time;
	long			start_time_ml;
	long			cur_time_ml;
	pthread_mutex_t	mutex_forks[200];
	pthread_mutex_t	mutex_for_write;
	pthread_mutex_t	mutex_for_eat;
}	t_data;

typedef struct s_philo
{
	pthread_t		ph_th;
	int				ph_id;
	int				fork_left_id;
	int				fork_right_id;
	unsigned int	count_eating;
	long			prev_time_eat_ml;
	struct timeval	last_eat;
	t_data			*data;
}	t_philo;

int		ft_atoi(const char *string);
void	parsing(int argc, char **argv, t_data *data);
void	error(char *mes);
void	create_philo(t_philo philo[200]);
void	get_start_time(t_data *data, int flag);
void	init_forks(t_data *data);
void	init_philo(t_data *data, t_philo *philo);
void	write_status(t_data *data, int id, char *status);
void	philo_eat(t_philo *philo, t_data *data);
void	philo_sleep(t_philo *philo, t_data *data);
void	philo_think(t_philo *philo, t_data *data);
void	ft_usleep(t_data *data, int time);
void	get_time_eat(t_philo *philo);
void	check_to_die(t_philo *philo, t_data *data);

#endif
