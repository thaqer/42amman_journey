CC = cc

CFLAGS = -Wall -Werror -Wextra

NAME = push_swap

SRCS = src/main.c\
	src/utils.c\
	src/operations.c\
	src/init.c\
	src/radix_sort.c\
	src/sort.c\
	src/end_program.c\
	src/check.c\

LIBFT = libft/libft.a
PRINTF = printf/libftprintf.a

OBJS = $(SRCS:src/%.c=objs/%.o)

all: $(NAME)

$(LIBFT):
	make -C libft

$(PRINTF):
	make -C printf

$(NAME): $(OBJS) $(LIBFT) $(PRINTF)
	$(CC) $(CFLAGS) $(OBJS) $(LIBFT) $(PRINTF) -o $(NAME)


objs/%.o: src/%.c
	@mkdir -p $(dir $@)
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	make -C libft clean
	make -C printf clean
	rm -rf objs

fclean: clean
	make -C libft fclean
	make -C printf fclean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re