/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsmets <gsmets@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/07 11:25:57 by gsmets            #+#    #+#             */
/*   Updated: 2019/11/15 14:57:10 by gsmets           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <string.h>
# include <stdlib.h>

typedef struct	s_list
{
	void			*content;
	struct s_list	*next;
}				t_list;

size_t			ft_strlen(const char *str);
void			ft_putstr(char *str);
char			*ft_strcpy(char *dest, const char *src);
int				ft_strcmp(const char *str1, const char *str2);
int				ft_strncmp(const char *str1, const char *str2, size_t n);
int				ft_toupper(int c);
int				ft_tolower(int c);
char			*ft_strncpy(char *dest, const char *src, size_t n);
char			*ft_strdup(const char *src);
char			*ft_strcat(char *dest, const char *src);
char			*ft_strncat(char *dest, const char *src, size_t n);
size_t			ft_strlcat(char *dest, const char *src, size_t size);
size_t			ft_strlcpy(char *dest, const char *src, size_t size);
char			*ft_strchr(const char *str, int c);
char			*ft_strrchr(const char *str, int c);
int				ft_isascii(int c);
char			*ft_strstr(const char *haystack, const char *needle);
char			*ft_strnstr(const char *hay, const char *needle, size_t size);
void			*ft_memset(void *ptr, int c, size_t len);
void			ft_bzero(void *str, size_t n);
int				ft_isprint(int c);
int				ft_isdigit(int c);
int				ft_isalpha(int c);
int				ft_isalnum(int c);
void			*ft_memcpy(void *dest, const void *src, size_t n);
void			*ft_memccpy(void *dest, const void *src, int c, size_t n);
void			*ft_memmove(void *dest, const void *src, size_t n);
void			*ft_memchr(const void *str, int c, size_t n);
int				ft_memcmp(const void *str1, const void *str2, size_t n);
int				ft_atoi(const char *str);
void			*ft_calloc(size_t n, size_t size);
char			*ft_substr(char const *str, unsigned int index, size_t len);
char			*ft_strjoin(char const *s1, char const *s2);
char			*ft_strtrim(char const *s1, char const *set);
char			**ft_split(char const *str, char c);
char			*ft_itoa(int n);
char			*ft_strmapi(char const *str, char (*f)(unsigned int, char));
void			ft_putchar(char c);
void			ft_putchar_fd(char c, int fd);
void			ft_putstr_fd(char *str, int fd);
void			ft_putendl_fd(char *str, int fd);
void			ft_putnbr_fd(int n, int fd);
t_list			*ft_lstnew(void *content);
void			ft_lstadd_front(t_list **alst, t_list *new);
int				ft_lstsize(t_list *lst);
t_list			*ft_lstlast(t_list *lst);
void			ft_lstadd_back(t_list **alst, t_list *new);
void			ft_lstdelone(t_list *lst, void (*del)(void *));
void			ft_lstclear(t_list **lst, void (*del)(void *));
void			ft_lstiter(t_list *lst, void (*f)(void *));
t_list			*ft_lstmap(t_list *l, void *(*f)(void *), void (*d)(void *));
void			ft_putnbr(int n);
void			ft_putunbr(unsigned int n);
void			ft_puthexnbr(unsigned int n, int allcaps);
void			ft_putptrnbr(unsigned long long n, int allcaps);

#endif
