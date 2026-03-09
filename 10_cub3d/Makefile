NAME = cub3D

CC = cc
CFLAGS = -Wall -Wextra -Werror #-fsanitize=address -g
MLX_FLAGS = -lmlx -lXext -lX11 -lm

SRCS_RC = src/raycasting/cub3d.c src/raycasting/hooks.c src/raycasting/hooks_helper.c\
		src/raycasting/raycasting.c src/raycasting/render_3d.c src/raycasting/textures.c
OBJS = $(SRCS_RC:.c=.o)

SRCS_PARS =  src/parsing/utils1.c src/parsing/utils2.c src/parsing/utils3.c\
		src/parsing/utils4.c src/parsing/utils5.c src/parsing/utils6.c src/parsing/parser.c
SRCS_PARS += src/gnl/gc.c src/gnl/gnl.c src/gnl/gnl_utils.c
SRCS_PARS += src/libft/ft_isdigit.c src/libft/ft_putstr_fd.c src/libft/ft_putchar_fd.c\
src/libft/ft_substr.c src/libft/ft_strlen.c src/libft/ft_atoi.c \
									src/libft/ft_strjoin.c src/libft/ft_strdup.c\
									src/libft/ft_strchr.c src/libft/ft_calloc.c src/libft/ft_bzero.c src/libft/ft_strncmp.c \
									src/libft/ft_isalpha.c src/libft/ft_strtrim.c\
									src/libft/ft_split_multi.c src/libft/ft_strlcpy.c
OBJS += $(SRCS_PARS:.c=.o)

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $(NAME) $(MLX_FLAGS)

%.o:%.c
	${CC} ${CFLAGS} -c $< -o $@

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.SECONDARY: ${OBJS}