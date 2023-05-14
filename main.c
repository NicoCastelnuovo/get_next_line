/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncasteln <ncasteln@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/14 13:21:01 by ncasteln          #+#    #+#             */
/*   Updated: 2023/05/14 17:36:49 by ncasteln         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <fcntl.h> // ----- OPEN()
#include <stdio.h>

int main ()
{
	int fd1;
	// int fd2;
	// int fd3;

	fd1 = open("./readme1.txt" , O_RDONLY);
	// fd2 = open("./readme2.txt" , O_RDONLY);
	// fd3 = open("./readme3.txt" , O_RDONLY);
	// fd1 = open("./binary" , O_RDONLY);

	// ________ MANDATORY
	// printf("• 1) :  --> %s",  get_next_line(fd1));
	// printf("• 2) :  --> %s",  get_next_line(fd1));
	// printf("• 3) :  --> %s",  get_next_line(fd1));
	// printf("• 4) :  --> %s",  get_next_line(fd1));
	// printf("• 5) :  --> %s",  get_next_line(fd1));
	// printf("• 6) :  --> %s",  get_next_line(fd1));
	// printf("• 7) :  --> %s",  get_next_line(fd1));
	// close(fd1);

	// ________ MANDATORY ___ NO PRINTF
	get_next_line(fd1);
	get_next_line(fd1);
	get_next_line(fd1);
	get_next_line(fd1);
	get_next_line(fd1);
	get_next_line(fd1);
	get_next_line(fd1);
	close(fd1);

	// ________ BONUS
	// printf("\n• 1) --> %s", get_next_line(fd1));
	// printf("• 2) --> %s", get_next_line(fd2));
	// printf("• 3) --> %s", get_next_line(fd3));
	// printf("• 4) --> %s", get_next_line(fd1));
	// printf("• 5) --> %s", get_next_line(fd2));
	// printf("• 6) --> %s", get_next_line(fd3));
	// printf("• 7) --> %s", get_next_line(fd1));
	// close(fd1);
	// close(fd2);
	// close(fd3);

	// ________ NO LEAKS
	// char *p = get_next_line(fd1);
	// printf("%s", p);
	// NO LEAKS
	// char *p = get_next_line(fd1);
	// ft_putstr_fd(p, 1);
	// NO LEAKS
	// get_next_line(fd1); // ------ this should be found by cmd leaks ----- ???
	// LEAKS
	// printf("%s", get_next_line(fd1));
	// LEAKS
	// ft_putstr_fd(get_next_line(fd1), 1);

	// ________ STDIN
	// get_next_line(0);
	// get_next_line(0);
	// printf("3) %s", get_next_line(0));
	// printf("4) %s", get_next_line(0));
	// get_next_line(0);
	// printf("6) %s", get_next_line(0));

	// system("leaks a.out");

	close(fd1);

	return (0);
}
