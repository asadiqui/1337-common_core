NAME = fractol
SRC = main.c fractals.c hooks.c utils.c
OBJ = $(SRC:%.c=%.o)
CC = cc
CCFLAGS = -Wextra -Wall -Werror

all: $(NAME)

$(NAME): $(OBJ)
	$(CC) $(CCFLAGS) $^ -lmlx -lXext -lX11 -lm -o $(NAME)

%.o: %.c
	$(CC) $(CCFLAGS) -c $< -o $@

clean:
	rm -rf $(OBJ)

fclean: clean
	rm -rf $(NAME)

re : fclean all