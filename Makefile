# cc -L libft -I. ft_printf.c -lft
NAME := push_swap
LIBFT := libft/libft.a

# Sources and objects
SRCS := push_swap.c stackops.c sortops.c ps_utils.c \
		parser.c benchmark.c \
		simple_sort.c small_sort.c ops.c \
		complex_sort.c medium_sort.c medium_utils.c

OBJ := $(SRCS:%.c=%.o)

# Compiler 
CC := cc
CFLAGS := -Wall -Werror -Wextra -g

all: $(NAME)

$(NAME): $(LIBFT) $(OBJ)
	$(CC) -I. -L libft/ $(OBJ) -lft -o $@

%.o: %.c push_swap.h
	$(CC) $(CFLAGS) -I. -c $< -o $@

clean:
	rm -f $(OBJ)
	$(MAKE) -C ./libft/ clean

fclean: clean
	rm -f $(NAME)
	$(MAKE) -C ./libft/ fclean

re: fclean all

$(LIBFT):
	$(MAKE) -C ./libft/

.PHONY: all clean fclean re
.SILENT:
