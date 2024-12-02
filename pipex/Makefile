CC = cc
CFLAGS = -Wall -Wextra -Werror

NAME = pipex

SRCS = main.c

LIBFT = /home/thaer/Desktop/core/pipex/ft_libft/libft.a

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
