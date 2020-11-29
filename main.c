#include "get_next_line.h"
#include <stdio.h>

int main(void)
{
	int     fd;
	int     ret;
	char    *line;

	fd = open("text.txt", O_RDONLY);
	if (fd == -1)
		return 0;
	ret = 1;
	while (ret > 0)
	{
		ret = get_next_line(fd, &line);
		printf("%d - %s\n",ret, line);
		free(line);
	}
	get_next_line(fd, &line);
	printf("%d - %s\n",ret, line);
	free(line);
	close(fd);
	return 0;
}