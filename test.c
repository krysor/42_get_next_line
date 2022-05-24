#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>

int	main(void)
{
	int	fd = open("/Users/kkaczoro/Desktop/projects/getnextt/get_next_line/text.txt", O_RDONLY);

	void *buffer = malloc(sizeof(char) * 100 + 1);
	printf("read	: %zd\n", read(fd, buffer, BUFFER_SIZE));
	printf("buffer	: %s\n", (char *)buffer);
	//printf("slash n	: %s\n", (char *)buffer);
	free(buffer);
}
