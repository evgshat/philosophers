#include <pthread.h>
#include <stdio.h>
#include <unistd.h>
#include <sys/time.h>


typedef struct s_str
{
	pthread_t a;
	pthread_t b;
	char *mes_a;
	char *mes_b;
	pthread_mutex_t mutex;
	int is_a;
	struct timeval start;
}	t_str;

void *func_a(void *c)
{
	t_str *s;

	s = (t_str*)c;

	printf("func\n");
	pthread_mutex_lock(&(s->mutex));
	printf("%s", s->mes_a);
	s->mes_b = "Hello\n";
	printf("unlock for B\n");
	pthread_mutex_unlock(&(s->mutex));
	return (NULL);
}

void *func_b(void *c)
{
	t_str	*s;
	long	ms;
	long	cur;
	long	res;
	struct timeval	current;

	s = (t_str*)c;
	usleep(2000);
	gettimeofday(&current, NULL);
	ms = (s->start.tv_sec * 1000) + (s->start.tv_usec / 1000);
	cur = (current.tv_sec * 1000) + (current.tv_usec / 1000);
	res = cur - ms;
	printf("%ld\n", res);
	printf("func\n");
	pthread_mutex_lock(&(s->mutex));
	printf("%s", s->mes_b);
	return (NULL);
}

int main()
{
	t_str	s;

	s.mes_a = "HelloA\n";
	s.mes_b = "HelloB\n";
	s.is_a = 1;

	gettimeofday(&s.start, NULL);

	if (pthread_mutex_init(&(s.mutex), NULL) != 0)
	{
		printf("Error\n");
		return (1);
	}
	s.is_a = 0;
	if (pthread_create(&s.a, NULL, func_a, (void *)(&s)) != 0)
	{
		printf("Error\n");
		return (1);
	}
	usleep(200);
	if (pthread_create(&s.b, NULL, func_b, (void *)(&s)) != 0)
	{
		printf("Error\n");
		return (1);
	}
	pthread_join(s.a, NULL);
	pthread_join(s.b, NULL);
	pthread_mutex_destroy(&s.mutex);
	return (0);

}