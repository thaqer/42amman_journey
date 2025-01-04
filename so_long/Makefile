CC = cc
CFLAGS = -Wall -Werror -Wextra -g

# Ensure the library paths are correct
MLX_FLAGS = -Lminilibx -lmlx -lXext -lX11 -lbsd

NAME = so_long

SRCS = map.c get_next_line/get_next_line.c get_next_line/get_next_line_utils.c \
       main.c so_long.c map_utilities.c window.c free.c

LIBFT_DIR = ../so_long/libft

LIBFT = $(LIBFT_DIR)/libft.a

OBJS = $(SRCS:.c=.o)

# Default target
all: $(NAME)

# Link object files with libraries
$(NAME): $(OBJS) $(LIBFT)
	$(CC) $(CFLAGS) $(OBJS) $(LIBFT) $(MLX_FLAGS) -o $(NAME) -L $(LIBFT_DIR) -lft

$(LIBFT):
	make -C $(LIBFT_DIR)

# Clean up object files
clean:
	$(MAKE) -C $(LIBFT_DIR) clean
	rm -f $(OBJS)


fclean: clean
	$(MAKE) -C $(LIBFT_DIR) fclean
	rm -f $(NAME)

# Rebuild the project
re: fclean all

.PHONY: all clean fclean re
