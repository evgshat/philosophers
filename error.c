#include "philo.h"

void	ft_putstr_fd(char *s, int fd)
{
	int	i;

	i = 0;
	while (s[i] != '\0')
	{
		write(fd, &s[i], 1);
		i++;
	}
}

void	error(char *mes)
{
	ft_putstr_fd("Error\n", 2);
	ft_putstr_fd(mes, 2);
	exit (1);
}