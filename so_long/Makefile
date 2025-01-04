CC = cc
CFLAGS = -Wall -Werror -Wextra -g

MLX_FLAGS = -Lminilibx -lmlx -lXext -lX11 -lbsd

NAME = so_long

SRCS = map.c get_next_line/get_next_line.c get_next_line/get_next_line_utils.c \
       main.c so_long.c map_utilities.c window.c free.c flood_fill.c 

LIBFT_DIR = ../so_long/libft
LIBFT = $(LIBFT_DIR)/libft.a

OBJ_DIR = obj
OBJS = $(addprefix $(OBJ_DIR)/, $(SRCS:.c=.o))

all: $(NAME)

# Link object files with libraries
$(NAME): $(OBJS) $(LIBFT)
	$(CC) $(CFLAGS) $(OBJS) $(LIBFT) $(MLX_FLAGS) -o $(NAME)

$(LIBFT):
	make -C $(LIBFT_DIR)

# Create object directory and compile source files
$(OBJ_DIR)/%.o: %.c
	@mkdir -p $(OBJ_DIR)/get_next_line
	$(CC) $(CFLAGS) -c $< -o $@

# Clean up object files
clean:
	$(MAKE) -C $(LIBFT_DIR) clean
	rm -rf $(OBJ_DIR)

fclean: clean
	$(MAKE) -C $(LIBFT_DIR) fclean
	rm -f $(NAME)

# Rebuild the project
re: fclean all

.PHONY: all clean fclean re
