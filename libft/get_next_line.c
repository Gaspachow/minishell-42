/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsmets <gsmets@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/14 12:20:07 by gsmets            #+#    #+#             */
/*   Updated: 2021/02/02 12:51:35 by gsmets           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
// #ifndef BUFFER_SIZE
// # define BUFFER_SIZE 1
// #endif


char *ft_strappend(char *str, char c)
{
	int		len;
	char	*new;
	int		i;
	int		buflen;

	len = ft_strlen(str);
	buflen = 0;
	i = 0;
	new = malloc((len + 2) * sizeof(char));
	if (!new)
		exit(EXIT_FAILURE);
	while(str[i])
	{
		new[i] = str[i];
		i++;
	}
	new[i++] = c;
	new[i] = '\0';
	return (new);
}

int	get_next_line(int fd, char **line)
{
	char	buf;
	char	*tmp;
	int		ret;

	buf = 0;
	*line = malloc(sizeof(char));
	if (!*line)
		exit(EXIT_FAILURE);
	**line = '\0';
	while (buf != '\n')
	{
		if ((ret = read(fd, &buf, 1)) && buf != '\n')
		{
			tmp = ft_strappend(*line, buf);
			free(*line);
			*line = tmp;
		}
		else if (!ret && !ft_strlen(*line))
			break;
	}
	if (buf == '\n')
		return (1);
	else
		return (0);
}


// int		get_next_line(int fd, char **line)
// {
// 	char			*buff;
// 	static char		*str[1000];
// 	int				ret;
// 	char			*tmp;

// 	if (line == NULL || fd < 0 || BUFFER_SIZE <= 0)
// 		return (-1);
// 	buff = malloc(sizeof(char) * (BUFFER_SIZE + 1));
// 	if (!buff)
// 		return (-1);
// 	while (!(check_nl(str[fd])) && ((ret = read(fd, buff, BUFFER_SIZE)) > 0))
// 	{
// 		buff[ret] = '\0';
// 		if (!(tmp = ft_strjoin(str[fd], buff)))
// 			return (mega_error(str[fd], buff));
// 		free(str[fd]);
// 		str[fd] = tmp;
// 	}
// 	free(buff);
// 	if (!str[fd])
// 		if ((*line = ft_strdup("")))
// 			return (0);
// 	return (create_line(&str[fd], line));
// }

// int		create_line(char **str, char **line)
// {
// 	size_t	len;
// 	char	*newline;
// 	// char	*tmp;

// 	if (!*str)
// 		return (-1);
// 	len = 0;
// 	while ((*str)[len] != '\n' && (*str)[len] != '\0')
// 		len++;
// 	if ((*str)[len] == '\0')
// 		return (last_line(str, line));
// 	newline = malloc((len + 1) * sizeof(char));
// 	if (!newline)
// 		return (mega_error(newline, *str));
// 	ft_memmove(newline, *str, len);
// 	newline[len] = '\0';
// 	// tmp = ft_substr(*str, len + 1, (ft_strlen(*str) - (len + 1)));
// 	// if (!tmp)
// 	// 	return (mega_error(newline, *str));
// 	free(*str);
// 	// *str = tmp;
// 	*line = newline;
// 	return (1);
// }

// int		last_line(char **str, char **line)
// {
// 	char	*newline;

// 	newline = ft_strdup(*str);
// 	free(*str);
// 	*str = NULL;
// 	if (!newline)
// 		return (-1);
// 	*line = newline;
// 	return (0);
// }

// int		check_nl(char *str)
// {
// 	if (!str)
// 		return (0);
// 	while (*str)
// 	{
// 		if (*str == '\n')
// 			return (1);
// 		else
// 			str++;
// 	}
// 	return (0);
// }

// int		mega_error(char *str1, char *str2)
// {
// 	free(str1);
// 	free(str2);
// 	return (-1);
// }
