NAME1	=	server
NAME2	=	client
SRCS1	=	server.c libft.c
SRCS2	=	client.c libft.c
OBJS1	=	$(SRCS1:.c=.o)
OBJS2	=	$(SRCS2:.c=.o)

CC		=	cc
CFLAGS	=	-Wall -Wextra -Werror

all: $(NAME1) $(NAME2)

$(NAME1): $(OBJS1)
	$(CC) $(CFLAGS) $(OBJS1) -o $(NAME1)

$(NAME2): $(OBJS2)
	$(CC) $(CFLAGS) $(OBJS2) -o $(NAME2)

clean:
	rm -f $(OBJS1) $(OBJS2)

fclean: clean
	rm -f $(NAME1) $(NAME2)

re: fclean all

bonus: all

.c.o:
	$(CC) $(CFLAGS) -c $< -o $@
