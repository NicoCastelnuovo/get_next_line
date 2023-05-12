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

	fd = open("./readme.txt" , O_RDONLY);

	// printf("\n• 1) [buff=%d]:  --> %s\n_______________", BUFFER_SIZE, get_next_line(fd));
	// printf("• 2) [buff=%d]:  --> %s\n_______________", BUFFER_SIZE, get_next_line(fd));
	// printf("• 3) [buff=%d]:  --> %s\n_______________", BUFFER_SIZE, get_next_line(fd));
	// printf("• 4) [buff=%d]:  --> %s\n_______________", BUFFER_SIZE, get_next_line(fd));
	// printf("• 5) [buff=%d]:  --> %s\n_______________", BUFFER_SIZE, get_next_line(fd));
	// printf("• 6) [buff=%d]:  --> %s\n_______________", BUFFER_SIZE, get_next_line(fd));
	// printf("• 7) [buff=%d]:  --> %s\n_______________", BUFFER_SIZE, get_next_line(fd));
	printf("\n• 1) [buff=%d]:  --> %s", BUFFER_SIZE, get_next_line(fd));
	printf("• 2) [buff=%d]:  --> %s", BUFFER_SIZE, get_next_line(fd));
	printf("• 3) [buff=%d]:  --> %s", BUFFER_SIZE, get_next_line(fd));
	printf("• 4) [buff=%d]:  --> %s", BUFFER_SIZE, get_next_line(fd));
	printf("• 5) [buff=%d]:  --> %s", BUFFER_SIZE, get_next_line(fd));
	printf("• 6) [buff=%d]:  --> %s", BUFFER_SIZE, get_next_line(fd));
	printf("• 7) [buff=%d]:  --> %s", BUFFER_SIZE, get_next_line(fd));

	// system("leaks a.out");

	close(fd);

	return (1);
}
