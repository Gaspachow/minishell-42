
SRCS	= ft_memset.c ft_bzero.c ft_memcpy.c ft_memccpy.c ft_memchr.c ft_memcmp.c ft_strlcpy.c ft_strlcat.c ft_strchr.c

SRCS	+= ft_strrchr.c ft_strnstr.c ft_strncmp.c ft_atoi.c ft_isalpha.c ft_isdigit.c ft_isalnum.c ft_isprint.c ft_isascii.c ft_toupper.c ft_tolower.c

SRCS	+= ft_strtrim.c ft_split.c ft_itoa.c ft_strmapi.c

SRCS	+= ft_putchar_fd.c ft_putstr_fd.c ft_putendl_fd.c ft_putnbr_fd.c ft_calloc.c

SRCS	+= ft_lstadd_back.c ft_lstadd_front.c ft_lstclear.c ft_lstdelone.c ft_lstiter.c ft_lstlast.c ft_lstmap.c

SRCS	+= ft_lstnew.c ft_lstsize.c ft_putstr.c ft_strcat.c ft_strcmp.c ft_strcpy.c ft_strncat.c ft_strncpy.c ft_strstr.c

SRCS	+= ft_putnbr.c ft_putunbr.c ft_puthexnbr.c ft_putchar.c ft_putptrnbr.c

SRCS	+= get_next_line.c get_next_line_utils.c

OBJS	= $(SRCS:.c=.o)

NAME	= libft.a

GCC		= clang

FLAGS	= -Wall -Wextra -Werror




all:	$(NAME)

.PHONY:	clean fclean re bonus bench bclean

$(NAME):	$(OBJS)
	ar -rcs $(NAME) $(OBJS)

clean:
	rm -f $(OBJS) $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

%.o: %.c
	$(GCC) $(FLAGS) -c $<  -o $(<:.c=.o)

bench:
	@echo "Creating shared object 'libft.so' ..."
	@$(GCC) ${FLAGS} -shared -o libft.so -fPIC $(SRCS)
	@echo "libft.so created!"
