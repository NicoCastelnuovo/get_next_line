/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncasteln <ncasteln@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/09 13:48:51 by ncasteln          #+#    #+#             */
/*   Updated: 2023/05/12 11:38:18 by ncasteln         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

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

char	*ft_strchr(const char *str, int c) // ---------- not original libft -----------
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

void	*ft_memcpy(void *dest, const void *src, size_t n)
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

char	*ft_strdup(char *str)
{
	char	*p;
	size_t	len;

	len = ft_strlen(str);
	if (len == 0) // added to return in case an empty string is passed
		return (NULL);
	p = malloc (len + 1);
	if (!p)
		return (NULL);
	ft_memcpy(p, str, len);
	p[len] = '\0';
	return (p);
}
char	*ft_substr(char *s, unsigned int start, size_t n)
{
	char	*p;
	size_t	i;

	if (!s)
		return (NULL); // ?????
	if (start >= ft_strlen(s))
		return (ft_strdup("")); // change this to something else --- NULL ? --- but never happens
	if (ft_strlen(s + start) < n)
		n = ft_strlen(s + start);
	p = malloc ((n + 1) * sizeof(char));
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
	return (p); // ---- free(s) ???
}

char	*ft_strjoin(char *line, char *buff)
{
	int		line_len;
	int		buff_len;
	char	*new_line;

	line_len = ft_strlen(line);
	buff_len = ft_strlen(buff);
	new_line = malloc ((line_len + buff_len + 1) * sizeof(char));
	if (!new_line)
		return (NULL);
	ft_memcpy(new_line, line, line_len);
	ft_memcpy(new_line + line_len, buff, buff_len);
	new_line[line_len + buff_len] = '\0';

	// free(*line); // --- REMEMBER free()
	// *line = NULL;
	// free(new_line); // --- REMEMBER free()

	return (new_line);
}