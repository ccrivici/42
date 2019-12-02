/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccrivici <ccrivici@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/18 18:35:12 by ccrivici          #+#    #+#             */
/*   Updated: 2019/11/30 14:32:52 by ccrivici         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>

static int	ft_newline(char **s, char **line, int len)
{
	char	*temp;

	while ((*s)[len] != '\0' && (*s)[len] != '\n')
		len++;
	if ((*s)[len] == '\n')
	{
		*line = ft_strndup(*s, len);
		temp = ft_strndup((&(*s)[len + 1]), ft_strlen((&(*s)[len + 1])));
		free(*s);
		*s = temp;
	}
	else
	{
		*line = *s;
		*s = NULL;
		return (0);
	}
	return (1);
}

static int	ft_check(char **s, char **line, int size)
{
	int		len;

	len = 0;
	if (size < 0)
		return (-1);
	else if (size == 0 && *s == NULL)
	{
		*line = ft_strndup("", 1);
		return (0);
	}
	else
		return (ft_newline(s, line, len));
}

int			get_next_line(int fd, char **line)
{
	int			size;
	char		*temp;
	static char *s[4096];
	char		buff[BUFFER_SIZE + 1];

	if (fd < 0 || line == NULL || BUFFER_SIZE <= 0)
		return (-1);
	while ((size = read(fd, buff, BUFFER_SIZE)) > 0)
	{
		buff[size] = '\0';
		if (*s == NULL)
			*s = ft_strndup(buff, BUFFER_SIZE);
		else
		{
			temp = ft_strjoin(*s, buff);
			free(*s);
			*s = temp;
		}
		if (ft_strchr(*s, '\n'))
			break ;
	}
	return (ft_check(s, line, size));
}
