#include "get_next_line.h"
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <string.h>

// int	main(void)
// {
// 	int	fd = open("/Users/kkaczoro/Desktop/projects/getnextt/get_next_line/text.txt", O_RDONLY);

// 	void *buffer = malloc(sizeof(char) * 100 + 1);
// 	printf("read	: %zd\n", read(fd, buffer, BUFFER_SIZE));
// 	printf("buffer	: %s\n", (char *)buffer);
// 	//printf("slash n	: %s\n", (char *)buffer);
// 	free(buffer);
// }

int	main(void)
{
	int	fd = open("/Users/kkaczoro/Desktop/projects/getnextt/get_next_line/text.txt", O_RDONLY);
	char	*str = get_next_line(fd);

	printf("get_next_line: %s\n", str);
	//printf("len_GNL      : %lu\n", strlen(str));
	// printf("get_next_line: %s\n", get_next_line(fd));
	// printf("buffer	: %s\n", get_next_line(fd));
	// printf("buffer	: %s\n", get_next_line(fd));
}
