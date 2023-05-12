#include "get_next_line.h"
#include <fcntl.h> // ----- OPEN()
#include <stdio.h>

// static void	ft_putstr_fd(char *s, int fd)
// {
// 	while (*s)
// 	{
// 		write(1, &*s, fd);
// 		s++;
// 	}
// }

int main ()
{
	int fd;
	// int fd2;
	// int fd3;

	fd = open("./binary" , O_RDONLY);
	// fd = open("./readme1.txt" , O_RDONLY);
	// fd2 = open("./readme2.txt" , O_RDONLY);
	// fd3 = open("./readme3.txt" , O_RDONLY);

	// printf("\n• 1) :  --> %s\n_______________",  get_next_line(fd));
	// printf("• 2) :  --> %s\n_______________",  get_next_line(fd));
	// printf("• 3) :  --> %s\n_______________",  get_next_line(fd));
	// printf("• 4) :  --> %s\n_______________",  get_next_line(fd));
	// printf("• 5) :  --> %s\n_______________",  get_next_line(fd));
	// printf("• 6) :  --> %s\n_______________",  get_next_line(fd));
	// printf("• 7) :  --> %s\n_______________",  get_next_line(fd));

	printf("\n• 1) :  --> %s",  get_next_line(fd));
	printf("• 2) :  --> %s",  get_next_line(fd));
	printf("• 3) :  --> %s",  get_next_line(fd));
	printf("• 4) :  --> %s",  get_next_line(fd));
	printf("• 5) :  --> %s",  get_next_line(fd));
	printf("• 6) :  --> %s",  get_next_line(fd));
	printf("• 7) :  --> %s",  get_next_line(fd));

	// BONUS
	// printf("\n• 1) --> %s", get_next_line(fd1));
	// printf("• 2) --> %s", get_next_line(fd2));
	// printf("• 3) --> %s", get_next_line(fd3));
	// printf("• 4) --> %s", get_next_line(fd1));
	// printf("• 5) --> %s", get_next_line(fd2));
	// printf("• 6) --> %s", get_next_line(fd3));
	// printf("• 7) --> %s", get_next_line(fd1));

	// NO LEAKS
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

	// char *p = get_next_line(fd1);
	// free(p);

	// system("leaks a.out");

	close(fd);
	// close(fd2);
	// close(fd3);

	return (1);
}
