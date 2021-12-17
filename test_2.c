#include "philo.h"

typedef struct s_str
{
	pthread_t th;
}	t_str;

void *func_for_th(void *temp)
{
	(void) temp;

	printf("Thread was created\n");
	return (NULL);
}

int	main()
{
	int	res;
	// pthread_t th;
	t_str str;

	res = pthread_create(&str.th, NULL, func_for_th, (void *)(&str));
	usleep(200);
	if (res != 0)
			printf("Thread was not created\n");
	printf("%d", (id + 3) % 4);
	return (0); //
}
