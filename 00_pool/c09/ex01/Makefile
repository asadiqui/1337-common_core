SRC		= ./srcs/ft_putchar.c ./srcs/ft_swap.c ./srcs/ft_putstr.c ./srcs/ft_strlen.c ./srcs/ft_strcmp.c
HEADER	= ./includes/
OBJ		= ${SRC:.c=.o}
CC		= gcc
CFLAGS	=  -Wall -Wextra -Werror
NAME	= libft.a
RM		= rm -f
AR		= ar rc
LIB		= ranlib
${NAME}: ${OBJ}
		${AR} ${NAME} ${OBJ}
		${LIB} ${NAME}

.c.o: 
	${CC} ${CFLAGS} -c $< -o ${<:.c=.o} -I ${HEADER}
all: ${NAME}
clean:
		${RM} ${OBJ}
fclean: clean
		${RM} ${NAME}
re: fclean all