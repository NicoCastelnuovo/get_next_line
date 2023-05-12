/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncasteln <ncasteln@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/09 13:47:26 by ncasteln          #+#    #+#             */
/*   Updated: 2023/05/12 11:38:59 by ncasteln         ###   ########.fr       */
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
	{
		// printf("{  I added a place for the new line  }\n");
		i++;
	}
	return (i);
}

static char	*split(char **line)
{
	char	*left;
	int		left_len;
	int		right_len;
	char	*temp;

	left_len = get_left_len(*line);
	left = ft_substr(*line, 0, left_len);
	// printf("LEFT %p\n", left);

	right_len = get_right_len(*line, left_len);
	temp = *line;
	// printf("TEMP %p\n", temp);
	*line = ft_substr(*line, left_len, right_len);
	// printf("*LINE %p\n", *line);
	free(temp);

	return (left);
}

char	*get_next_line(int fd)
{
	static char	*line;
	char		*buff;
	int			n_read;

	if (BUFFER_SIZE)
	{
		buff = malloc ((BUFFER_SIZE + 1) * sizeof(char));
		// printf("BUFF %p\n", buff);
		if (!buff)
			return (NULL);
	}

	n_read = 1;
	while (n_read > 0 && !(ft_strchr(line, '\n')))
	{
		n_read = read(fd, buff, BUFFER_SIZE);
		buff[n_read] = '\0';
		if (n_read > 0) // && n_read == BUFFER_SIZE ???
		{
			// if (!line)
			// {
			// 	line = ft_strdup(buff);
			// 	// printf("LINE %p\n", line);
			// 	if (!line)
			// 		return (free(buff), buff = NULL, NULL);
			// }
			// else
			// {
				line = ft_strjoin(line, buff);
				// printf("LINE JOIN %p\n", line);
				if (!line)
					return (free(buff), buff = NULL, free(line), line = NULL, NULL);
			// }
		}
		else // n_read == 0 || n_read == -1
		{
			if (line)
			{
				// consume the line, free, and return
				return (free(buff), buff = NULL, split(&line));
			}
			else
			{
				// free everything
				return (free(buff), buff = NULL, free(line), line = NULL, NULL); //free(buff), buff = NULL, remove ????
			}
		}
	}
	return (free(buff), buff = NULL, split(&line));
}

//cc -Wall -Wextra -Werror get_next_line.c get_next_line_utils.c -D BUFFER_SIZE=10
