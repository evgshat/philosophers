#ifndef PHILO_H
# define PHILO_H

# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <pthread.h>

# define FORK	"has taken a fork"
# define SLEEP	"is sleeping"
# define EAT	"is eating"
# define THINK	"is thinking"



typedef struct s_data
{
	int				num_of_philos;
	int				time_to_die;
	int				time_to_eat;
	int				time_to_sleep;
	int				time_must_eat;
	struct timeval	start_time;
	struct timeval	current_time;
	pthread_mutex_t	mutex_forks[200];
}	t_data;

typedef struct s_philo
{
	pthread_t		th; //
	int				ph_id;
	int				fork_left_id;
	int				fork_right_id;
	int				count_eating;
	struct timeval	last_eat;
}	t_philo;

int		ft_atoi(const char *string);
int		parsing(char **argv, t_data *data);
void	create_philo(t_data *data);


#endif
