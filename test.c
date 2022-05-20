#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

int	main(void)
{
	void *buffer = malloc(sizeof(char) * 100 + 1);
	printf("read	: %zd\n", read(1, buffer, 10));
	printf("buffer	: %s\n", (char *)buffer);
}