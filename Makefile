
SRCS	= main.c

LIBFT	= libft/libft.a

OBJS	= $(SRCS:.c=.o)

NAME	= minishell

LIBFT	= libft/libft.a

CLANG	= clang

FLAGS	= -Wall -Wextra -Werror

INCLUDE	= -L . -lft

INCLUDEH = -L .



all:	$(NAME)

.PHONY:	clean fclean re bonus bench bclean

$(NAME): $(OBJS)
	cd libft && $(MAKE)
	cp libft/libft.a libft.a
	$(CLANG) $(FLAGS) -o $(NAME) $(OBJS) $(INCLUDE)

clean:
	rm -f $(OBJS) $(B_OBJS)
	cd libft && $(MAKE) clean

fclean: clean
	rm -f $(NAME) $(BONUS)
	cd libft && $(MAKE) fclean

re: fclean all

%.o: %.c
	$(GCC) $(FLAGS) $(INCLUDEH) -c $<  -o $(<:.c=.o)

