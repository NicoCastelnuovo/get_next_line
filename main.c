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
	int fd1;
	int fd2;
	int fd3;

	fd1 = open("./readme1.txt" , O_RDONLY);
	fd2 = open("./readme2.txt" , O_RDONLY);
	fd3 = open("./readme3.txt" , O_RDONLY);

	// printf("\n• 1) [buff=%d]:  --> %s\n_______________", BUFFER_SIZE, get_next_line(fd));
	// printf("• 2) [buff=%d]:  --> %s\n_______________", BUFFER_SIZE, get_next_line(fd));
	// printf("• 3) [buff=%d]:  --> %s\n_______________", BUFFER_SIZE, get_next_line(fd));
	// printf("• 4) [buff=%d]:  --> %s\n_______________", BUFFER_SIZE, get_next_line(fd));
	// printf("• 5) [buff=%d]:  --> %s\n_______________", BUFFER_SIZE, get_next_line(fd));
	// printf("• 6) [buff=%d]:  --> %s\n_______________", BUFFER_SIZE, get_next_line(fd));
	// printf("• 7) [buff=%d]:  --> %s\n_______________", BUFFER_SIZE, get_next_line(fd));

	// printf("\n• 1) [buff=%d]:  --> %s", BUFFER_SIZE, get_next_line(fd));
	// printf("• 2) [buff=%d]:  --> %s", BUFFER_SIZE, get_next_line(fd));
	// printf("• 3) [buff=%d]:  --> %s", BUFFER_SIZE, get_next_line(fd));
	// printf("• 4) [buff=%d]:  --> %s", BUFFER_SIZE, get_next_line(fd));
	// printf("• 5) [buff=%d]:  --> %s", BUFFER_SIZE, get_next_line(fd));
	// printf("• 6) [buff=%d]:  --> %s", BUFFER_SIZE, get_next_line(fd));
	// printf("• 7) [buff=%d]:  --> %s", BUFFER_SIZE, get_next_line(fd));

	// BONUS
	printf("\n• 1) --> %s", get_next_line(fd1));
	// printf("• 2) --> %s", get_next_line(fd2));
	// printf("• 3) --> %s", get_next_line(fd3));
	// printf("• 4) --> %s", get_next_line(fd1));
	// printf("• 5) --> %s", get_next_line(fd2));
	// printf("• 6) --> %s", get_next_line(fd3));
	// printf("• 7) --> %s", get_next_line(fd1));

	system("leaks a.out");

	close(fd1);
	close(fd2);
	close(fd3);

	return (1);
}
