/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncasteln <ncasteln@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/09 13:48:02 by ncasteln          #+#    #+#             */
/*   Updated: 2023/05/14 17:01:04 by ncasteln         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H

# include <unistd.h> // read
# include <stdio.h> // print_f ---- REMOVE
# include <stdlib.h> // malloc

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 10
# endif

# ifndef MAX_FD
#  define MAX_FD 10240
# endif

char	*get_next_line(int fd);
char	*ft_strjoin_mod(char *s1, char *s2);
char	*ft_strchr_mod(char *str, int c);
char	*ft_substr_mod(char *s, unsigned int start, size_t n);
void	*ft_memcpy_mod(void *dest, void *src, size_t n);

#endif
