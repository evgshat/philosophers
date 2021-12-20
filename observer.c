#include "philo.h"

void observer(t_philo *philo, t_data *data, int flag)
{
    long till_time_ml;

    pthread_mutex_lock(&(data->mutex_for_eat));
    if (flag == 0)
        till_time_ml = data->start_time_ml + data->time_to_die;
    else
        till_time_ml = philo->prev_time_eat_ml + data->time_to_die;
    if (data->cur_time_ml > till_time_ml)
    {
        write_status(philo->data, philo->ph_id, DIED);
        exit (1);
    }
    pthread_mutex_unlock(&(data->mutex_for_eat));
}