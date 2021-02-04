
SRCS	= main.c

SRCS	+= parser/parser.c parser/input_split.c parser/input_split2.c parser/parser_delegator.c parser/parser_variable.c parser/parser_redir.c

SRCS	+= parser/parser2.c parser/parser_redir2.c parser/handle_basic.c parser/parser_error.c parser/parser_redir3.c

SRCS	+= builtins/echo.c builtins/pwd.c builtins/cd_utils.c builtins/cd.c builtins/exec.c builtins/exec_utils.c builtins/env.c

SRCS	+= builtins/export.c builtins/export_utils.c builtins/unset.c builtins/pipe.c builtins/signal.c builtins/exit.c

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


# valgrind --leak-check=full --show-leak-kinds=all --track-origins=yes --log-file=valgrind-out.txt ./minishell