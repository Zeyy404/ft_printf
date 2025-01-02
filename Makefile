CC:= cc
CFLAGS:= -Wall -Wextra -Werror
SRCS:= ft_printf.c ft_putint.c ft_putuint.c ft_putchr.c \
		ft_putstr.c ft_puthex.c ft_putuphex.c ft_putptr.c
OBJS:= $(SRCS:.c=.o)

NAME:= libftprintf.a

$(NAME): $(OBJS)
	ar rcs $@ $^

all: $(NAME)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

bonus: all

clean:
	rm -rf $(OBJS)

fclean: clean
	rm -rf $(NAME)

re: fclean all

.PHONY: re fclean clean all
