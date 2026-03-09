NAME	= libftprintf.a
SRCS	= ft_printf.c	ft_putchar.c	ft_puthexa.c \
			ft_putnbr.c	ft_putstr.c	ft_putunsigned.c
OBJS	= $(SRCS:.c=.o)
BSRCS	= ft_printf_bonus.c	ft_putchar_bonus.c	ft_puthexa_bonus.c \
			ft_putnbr_bonus.c	ft_putstr_bonus.c	ft_putunsigned_bonus.c
BOBJS	= $(BSRCS:.c=.o)
CC		= cc
CFLAGS	= -Wall -Wextra -Werror

$(NAME): $(OBJS)

all: $(NAME)

clean:
	rm -f $(OBJS) $(BOBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.c.o:
	$(CC) $(CFLAGS) -c $<
	ar -rcs $(NAME) $@

bonus: $(BOBJS)
