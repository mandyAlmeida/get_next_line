/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amaferre <amaferre@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/10 18:05:32 by amaferre          #+#    #+#             */
/*   Updated: 2024/11/10 20:38:01 by amaferre         ###   ########.org.br   */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

size_t	ft_strlcpy(char *dst, const char *src, size_t size)
{
	size_t	x;

	x = 0;
	if (size == 0)
		return (ft_strlen(src));
	while (x < (size - 1) && src[x])
	{
		dst[x] = src[x];
		x++;
	}
	dst[x] = '\0';
	return (ft_strlen(src));
}

char	*ft_strdup(const char *s)
{
	int		x;
	int		y;
	char	*str;

	x = 0;
	y = ft_strlen(s);
	str = (char *)malloc(sizeof(char) * (ft_strlen(s) + 1));
	if (str == NULL)
		return (NULL);
	while (x < y)
	{
		str[x] = s[x];
		x++;
	}
	str[x] = '\0';
	return (str);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*str;
	size_t	sub1;
	size_t	sub2;

	sub1 = ft_strlen(s1);
	sub2 = ft_strlen(s2);
	str = malloc((sub1 + sub2 + 1) * sizeof(char));
	if (str == NULL)
		return (NULL);
	ft_strlcpy(str, s1, sub1 + 1);
	ft_strlcpy(&str[sub1], s2, sub2 + 1);
	return (str);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t	s_len;
	size_t	str_len;
	char	*str;

	s_len = ft_strlen(s);
	if (start >= s_len)
		return (ft_strdup(""));
	if (start + len > s_len)
		str_len = s_len - start;
	else
		str_len = len;
	str = (char *)malloc((str_len + 1) * sizeof(char));
	if (!str)
		return (NULL);
	ft_strlcpy(str, s + start, str_len + 1);
	return (str);
}
