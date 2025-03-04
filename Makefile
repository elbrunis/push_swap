# Nombre del ejecutable
NAME = program

# Directorios
LIBFT_DIR = libft
LIBFT = $(LIBFT_DIR)/libft.a

# Archivos fuente
SRCS = program.c list.c error.c algorithm.c utils.c\
        movements/swap.c \
        movements/push.c \
        movements/rotate.c \
        movements/r_rotate.c
OBJS = $(SRCS:.c=.o)

# Compilador y flags
CC = gcc
CFLAGS = -Wall -Wextra -Werror

# Reglas
all: $(LIBFT) $(NAME)

$(LIBFT):
	$(MAKE) -C $(LIBFT_DIR)

$(NAME): $(OBJS) $(LIBFT)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJS) $(LIBFT)

clean:
	$(MAKE) -C $(LIBFT_DIR) clean
	rm -f $(OBJS)

fclean: clean
	$(MAKE) -C $(LIBFT_DIR) fclean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re