# cc -L libft -I. ft_printf.c -lft
NAME := push_swap

# Sources and objects
SRCS := push_swap.c stackops.c sortops.c ps_utils.c

OBJ := $(SRCS:%.c=%.o)

# Compiler 
CC := cc
CFLAGS := -Wall -Werror -Wextra

all: $(NAME)

$(NAME): libft $(OBJ) 
	$(CC) -I. -L libft/ $(OBJ) -lft -o $@

%.o: %.c
	$(CC) -c $(CFLAGS) $^ $(LIBS) -o $@

clean:
	rm -f $(OBJ)

fclean: clean
	rm $(NAME)

re: fclean all

libft:
	$(MAKE) libonly -C ./libft/

.PHONY: $(NAME) all clean fclean re libft
.SILENT:
