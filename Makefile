NAME = libftprintf.a
FILES = ft_printf.c ft_puthex.c ft_putnbr.c ft_putpt.c ft_decimaltobinary.c
OBJS = ${FILES:.c=.o}

.PHONY : all clean fclean re

all: $(NAME)

$(NAME): ${OBJS}
	make -C libft
	cp libft/libft.a .
	mv libft.a $(NAME)
	ar rs $(NAME) $(OBJS)

.c.o :
	gcc -Wall -Wextra -Werror -c $< -o ${<:.c=.o}

clean:
	make -C libft clean
	rm -f $(OBJS)

fclean: clean
	make -C libft fclean
	rm -f $(NAME)

re: fclean all
