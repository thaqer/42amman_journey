CC = cc

CFLAGS = -Wall -Wextra -Werror

NAME = philo

SRC = main.c \
	philo.c \

LIBFT = libft/libft.a
PRINTF = printf/libftprintf.a

OBJ = $(addprefix objs/, $(SRCS:.c=.o))

all: $(NAME)

$(NAME): $(OBJ) $(LIBFT) $(PRINTF)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJ) $(LIBFT) $(PRINTF)

objs/%.o: %.c
	@mkdir -p objs
	$(CC) $(CFLAGS) -c $< -o $@

$(LIBFT):
	make -C libft

$(PRINTF):
	make -C printf

clean:
	@make -C libft clean
	@make -C printf clean
	@rm -rf objs

fclean: clean
	@make -C libft fclean
	@make -C printf fclean
	@rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re