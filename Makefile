SRCS =  init_philo.c \
		main.c \
		parsing.c \
		error.c \
		utils.c \
		init_forks.c \
		create_philo.c \
		get_start_time.c \
		philo_eat.c \
		common.c \
		philo_sleep.c \
		philo_think.c \
		ft_usleep.c \
		observer.c \
		get_time_eat.c \


#OBJS = $(SRCS:.c=.o)
OBJS = $(patsubst %.c, %.o, $(SRCS))

NAME = philo
CFLAGS = -Werror -Wall -Wextra -g
CC = gcc
RM = rm -rf

HEADER = so_long.h

%.o: %.c $(HEADER) Makefile
	$(CC) $(CFLAGS) -c $< -o $@

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $^ -o $@

all: $(NAME)

clean:
		$(RM) $(OBJS)

fclean:	clean
		$(RM) $(NAME)

re:	fclean all

.PHONY: all clean fclean re
