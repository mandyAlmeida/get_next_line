/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amaferre <amaferre@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/09 20:24:58 by amaferre          #+#    #+#             */
/*   Updated: 2024/11/13 00:58:02 by amaferre         ###   ########.org.br   */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"	

static char	*ft_strchr(const char *s, int c)
{
	while (*s && *s != (char)c)
		s++;
	if (*s == (char)c)
		return ((char *)s);
	return (NULL);
}

static char	*ft_read_line(int fd, char *buf, char *save)
{
	int		read_line;
	char	*temp;

	read_line = 1;
	while (read_line)
	{
		read_line = read(fd, buf, BUFFER_SIZE);
		if (read_line == -1)
			return (NULL);
		else if (read_line == 0)
			break ;
		buf[read_line] = '\0';
		if (!save)
			save = ft_strdup("");
		temp = save;
		save = ft_strjoin(temp, buf);
		free(temp);
		temp = NULL;
		if (ft_strchr (buf, '\n'))
			break ;
	}
	return (save);
}

static char	*ft_extract_line(char *line)
{
	size_t	count;
	char	*save;

	count = 0;
	while (line[count] != '\n' && line[count] != '\0')
		count++;
	if (line[count] == '\0' || line[1] == '\0')
		return (NULL);
	save = ft_substr(line, count + 1, ft_strlen(line) - count);
	if (*save == '\0')
	{
		free(save);
		save = NULL;
	}
	line[count + 1] = '\0';
	return (save);
}

char	*get_next_line(int fd)
{
	char		*line;
	char		*buf;
	static char	*save;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	buf = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!buf)
		return (NULL);
	line = ft_read_line(fd, buf, save);
	free(buf);
	buf = NULL;
	if (!line)
		return (NULL);
	save = ft_extract_line(line);
	return (line);
}
