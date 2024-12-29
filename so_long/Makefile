CC = cc
CFLAGS = -Wall -Werror -Wextra -g

MLX_FLAGS = -lmlx -lX11 -lXext -lm

NAME = so_long.a

SRCS = map.c get_next_line/get_next_line.c get_next_line/get_next_line_utils.c

LIBFT = ../so_long/libft/libft.a
PRINTF = ../so_long/printf/libftprintf.a

OBJS = $(SRCS:.c=.o)

all: $(NAME)

$(NAME): $(OBJS) $(LIBFT) $(PRINTF)
	$(CC) $(CFLAGS) $(MLX_FLAGS) $(OBJS) $(LIBFT) $(PRINTF) -o $(NAME)


clean:
	rm -f $(OBJS)

fclean:
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re