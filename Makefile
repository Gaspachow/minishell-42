
SRCS	= main.c

SRCS	+= parser/parser.c parser/input_split.c parser/parser_delegator.c parser/parser_variable.c parser/parser_redir.c

SRCS	+= builtins/echo.c builtins/pwd.c builtins/cd.c builtins/exec.c builtins/env.c builtins/export.c builtins/unset.c

SRCS	+= builtins/pipe.c

LIBFT	= libft/libft.a

OBJS	= $(SRCS:.c=.o)

NAME	= minishell

LIBFT	= libft/libft.a

CLANG	= clang

FLAGS	= -Wall -Wextra -Werror

INCLUDE	= -L libft -lft




all:	$(NAME)

.PHONY:	clean fclean re bonus bench bclean

$(NAME): $(OBJS)
	cd libft && $(MAKE)
	$(CLANG) $(FLAGS) -o $(NAME) $(OBJS) $(INCLUDE)

clean:
	rm -f $(OBJS) $(B_OBJS)
	cd libft && $(MAKE) clean

fclean: clean
	rm -f $(NAME) $(BONUS)
	cd libft && $(MAKE) fclean

re: fclean all

%.o: %.c
	$(CLANG) $(FLAGS) -c $<  -o $(<:.c=.o)

