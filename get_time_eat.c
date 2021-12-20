#include "philo.h"

void get_time_eat(t_philo *philo)
{
    struct timeval	prev_time_eat;

    gettimeofday(&prev_time_eat, NULL);
    philo->prev_time_eat_ml = (prev_time_eat.tv_sec * 1000)
            + (prev_time_eat.tv_usec / 1000);
}