/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncasteln <ncasteln@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/09 13:48:51 by ncasteln          #+#    #+#             */
/*   Updated: 2023/05/12 15:13:29 by ncasteln         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

size_t	ft_strlen(char *str) // ---------- not original libft -----------
{
	size_t	i;

	if (!str)
		return (0);
	i = 0;
	while (str[i])
		i++;
	return (i);
}

char	*ft_strchr(char *str, int c) // ---------- not original libft -----------
{
	char	*p;
	int		i;

	if (!str)
		return (NULL);
	p = (char *) str;
	i = 0;
	while (p[i])
	{
		if (p[i] == (char) c)
			return (p + i);
		i++;
	}
	return (NULL);
}

void	*ft_memset(void *str, int c, size_t n)
{
	size_t	i;

	i = 0;
	while (i < n)
	{
		*((unsigned char *) str + i) = (unsigned char)c;
		i++;
	}
	return (str);
}

void	*ft_memcpy(void *dest, void *src, size_t n)
{
	size_t	i;

	i = 0;
	if ((!dest) && (!src))
		return (NULL);
	while (i < n)
	{
		ft_memset(dest + i, *((char *) src + i), 1);
		i++;
	}
	return (dest);
}
void	*ft_calloc(size_t len, size_t n_bits)
{
	char	*p;
	size_t	total_size;

	total_size = len * n_bits;
	if (len && (total_size / len) != n_bits)
		return (NULL);
	p = malloc (total_size);
	if (!p)
		return (NULL);
	ft_memset(p, 0, total_size);
	return (p);
}

char	*ft_substr(char *s, unsigned int start, size_t n) // ---------- not original libft -----------
{
	char	*p;
	size_t	i;

	// printf("s substr (1) [%p]\n", s);
	if (!s) // ---------- not original libft -----------
		return (NULL);
	if (ft_strlen(s + start) < n)
		n = ft_strlen(s + start);
	p = malloc ((n + 1) * sizeof(char));
	// printf("p substr (2) [%p]\n", p);
	if (!p)
		return (NULL);
	i = 0;
	while ((i < n) && s[start])
	{
		p[i] = s[start];
		start++;
		i++;
	}
	p[i] = '\0';
	return (p);
}

char	*ft_strjoin(char **line, char *buff) // ------ change to ** to assign to NULL
{
	int		line_len;
	int		buff_len;
	char	*new_line;

	// printf("*line join (1) [%p]\n", *line);
	line_len = ft_strlen(*line);
	buff_len = ft_strlen(buff);
	new_line = malloc ((line_len + buff_len + 1) * sizeof(char));
	// printf("new_line join (1) [%p]\n", *line);
	if (!new_line)
		return (NULL);
	ft_memcpy(new_line, *line, line_len);
	ft_memcpy(new_line + line_len, buff, buff_len);
	new_line[line_len + buff_len] = '\0';
	free(*line);
	*line = NULL;
	// line = NULL; ---------- ????? or *line
	return (new_line);
}
