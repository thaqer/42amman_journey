CC = cc
CFLAGS = -Wall -Wextra -Werror -g3

NAME = pipex

SRCS = pipex.c end_process.c child_process.c

LIBFT = ../pipex/ft_libft/libft.a

OBJS = $(SRCS:.c=.o)

all: $(NAME)


$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) $(LIBFT) -o $(NAME)

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
