CC = cc

CFLAGS = -Wall -Werror -Wextra

NAME = push_swap

SRCS = push_swap.c main.c

LIBFT = libft/libft.a
PRINTF = ft_printf/libftprintf.a

OBJS = $(addprefix objs/, $(SRCS:.c=.o))

all = $(NAME)

$(NAME): $(OBJS) $(LIBFT) $(PRINTF)
	$(CC) $(CFLAGS) $(OBJS) $(LIBFT) $(PRINTF) -o $(NAME)

$(LIBFT):
	make -C libft

$(PRINTF):
	make -C ft_printf

objs/%.o: %.c
	@mkdir -p objs
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -rf objs
	make -C libft clean
	make -C ft_printf clean

fclean: clean
	rm -f $(NAME)
	make -C libft fclean
	make -C ft_printf fclean

re: fclean all

.PHONY: all clean fclean re