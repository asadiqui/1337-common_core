NAME	= philo
#BNAME	= philo_bonus
SRCS	= main.c init.c threads.c monitor.c utils.c
OBJS	= $(SRCS:.c=.o)
#BSRCS	= 
#BOBJS	= $(BSRCS:.c=.o)
CC		= cc
CFLAGS	= -Wall -Wextra -Werror #-fsanitize=thread -g3

all: $(NAME)

#bonus: $(BNAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $^ -o $@

#$(BNAME): $(BOBJS)
#	$(CC) $(CFLAGS) $^ -o $@

.c.o:
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJS) $(BOBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.SECONDARY: