SRCS	= ./srcs/main.c ./srcs/atoi_putnbr.c ./srcs/ops.c
OBJS	= ${SRC:.c=.o}
NAME	= do-op

all:
	gcc  -Wall -Wextra -Werror $(SRCS) -o $(NAME)
clean:
	rm -f $(OBJS)
fclean: clean
	rm -f $(NAME)
re: fclean all