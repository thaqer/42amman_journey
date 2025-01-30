CC = cc

CFLAGS = -Wall -Werror -Wextra

NAME = push_swap

SRCS = src/main.c src/utils.c src/operations.c 

LIBFT = libft/libft.a
PRINTF = printf/libftprintf.a

OBJS = $(addprefix objs/, $(SRCS:.c=.o))

all = $(NAME)

$(NAME): $(OBJS) $(LIBFT) $(PRINTF)
	$(CC) $(CFLAGS) $(OBJS) $(LIBFT) $(PRINTF) -o $(NAME)

$(LIBFT):
	make -C libft

$(PRINTF):
	make -C printf

objs/%.o: %.c
	@mkdir -p $(dir $@)
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -rf objs
	make -C libft clean
	make -C printf clean

fclean: clean
	rm -f $(NAME)
	make -C libft fclean
	make -C printf fclean

re: fclean all

.PHONY: all clean fclean re