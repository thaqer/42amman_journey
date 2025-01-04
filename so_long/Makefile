CC = cc
CFLAGS = -Wall -Werror -Wextra -g

# Ensure the library paths are correct
MLX_FLAGS = -Lminilibx -lmlx -lXext -lX11 -lbsd

NAME = so_long

SRCS = map.c get_next_line/get_next_line.c get_next_line/get_next_line_utils.c \
       main.c so_long.c map_utilities.c window.c free.c

LIBFT = ../so_long/libft/libft.a
PRINTF = ../so_long/printf/libftprintf.a

OBJS = $(SRCS:.c=.o)

# Default target
all: $(NAME)

# Link object files with libraries
$(NAME): $(OBJS) $(LIBFT) $(PRINTF)
	$(CC) $(CFLAGS) $(OBJS) $(LIBFT) $(PRINTF) $(MLX_FLAGS) -o $(NAME)

# Clean up object files
clean:
	rm -f $(OBJS)

# Full clean
fclean: clean
	rm -f $(NAME)

# Rebuild the project
re: fclean all

.PHONY: all clean fclean re
