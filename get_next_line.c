/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncasteln <ncasteln@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/09 13:47:26 by ncasteln          #+#    #+#             */
/*   Updated: 2023/05/12 14:22:49 by ncasteln         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static int	get_right_len(char *line, int left_len)
{
	int	i;

	i = 0;
	while (line[left_len])
	{
		left_len++;
		i++;
	}
	return (i);
}

static int	get_left_len(char *line)
{
	int	i;

	i = 0;
	while (line[i] && line[i] != '\n')
		i++;
	if (line[i] == '\n')
		i++;
	return (i);
}

static char	*split(char **line)
{
	char	*left;
	char	*temp;
	int		left_len;
	int		right_len;

	// printf("line(3) [%p]\n", *line);
	left_len = get_left_len(*line);
	left = ft_substr(*line, 0, left_len);
	// printf("left [%p]\n", left);
	right_len = get_right_len(*line, left_len);
	if (right_len == 0)
	{
		// // printf("RIGHT_LEN == 0 - *line [%s] - left [%s]\n", *line, left);
		temp = NULL;
		free(*line);
		*line = NULL;
		// printf("line(4) [%p]\n", left);
	}
	else
	{
		temp = *line;
		// printf("temp(5) [%p]\n", left);
		*line = ft_substr(*line, left_len, right_len);
		free(temp);
		// printf("line(5) [%p]\n", left);
	}
	return (left);
}
// - 6 = OK

char	*init_buffer(char	**buff)
{
	// if (fd || fd >= 0)
	// {
	// 	// check fd
	// }
	if (BUFFER_SIZE > 0)
	{
		*buff = malloc ((BUFFER_SIZE + 1) * sizeof(char));
		if (!*buff)
			return (NULL);
		return (*buff);
	}
	return (NULL);
}

char	*get_next_line(int fd)
{
	static char	*line;
	char		*buff;
	int			n_read;

	buff = init_buffer(&buff);
	if (!buff)
		return (NULL);
	n_read = 1;
	while (n_read > 0 && !(ft_strchr(line, '\n')))
	{
		n_read = read(fd, buff, BUFFER_SIZE);
		if (n_read == -1)
		{
			if (line)
				return (free(buff), buff = NULL, free(line), line = NULL, NULL);
			return (free(buff), buff = NULL);
		}
		buff[n_read] = '\0';
		if (n_read > 0) // && n_read == BUFFER_SIZE ???
		{
			line = ft_strjoin(line, buff);
			// printf("line(1) [%p]\n", line);
			if (!line)
				return (free(buff), buff = NULL, NULL);
		}
		else // n_read == 0 || n_read == -1
		{
			if (line)
			{
				// printf("line(2) [%p]\n", line);
				return (free(buff), buff = NULL, split(&line));
			}
			else
				return (free(buff), buff = NULL, NULL); // --------- free(line), line = NULL ???? ---- it should already be NULL
		}
	}
	return (free(buff), buff = NULL, split(&line));
}
// - 4
