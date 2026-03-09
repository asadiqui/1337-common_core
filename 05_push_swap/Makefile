NAME	=	push_swap
BNAME	=	checker
SRCS	=	main.c parsing_input.c instructions.c auxiliary.c \
			sorting_algo.c push_to_b.c pushback_to_a.c
OBJS	=	$(SRCS:.c=.o)
BSRCS	=	checker_bonus.c parsing_input_bonus.c instructions_bonus.c \
			call_instruction_bonus.c gnl_bonus.c gnl_utils_bonus.c
BOBJS	=	$(BSRCS:.c=.o)
CC	=	cc
CFLAGS	=	-Wall -Wextra -Werror

all: $(NAME)

bonus: $(BNAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $(NAME)

$(BNAME): $(BOBJS)
	$(CC) $(CFLAGS) $(BOBJS) -o $(BNAME)

clean:
	rm -f $(OBJS) $(BOBJS)

fclean: clean
	rm -f $(NAME) $(BNAME)

re: fclean all

.c.o:
	$(CC) $(CFLAGS) -c $< -o $@
