#include "get_next_line.h"

static char *write_remains(char *remains, char **line)
{
	char *stop_point;
	if (remains)
	{
		if ((stop_point = ft_strchr(remains, '\n')))
		{
			*stop_point = '\0';
			*line = ft_strdup(remains);
			ft_strcpy(remains, ++stop_point);
		}
		else
		{
			*line = ft_strdup(remains);
		}
	}
	else
	{
		*line = ft_strnew
	}
}

int get_next_line(int fd, char **line)
{
	size_t buf_size = 10;
	char buf[buf_size + 1];
	int bytes_read;
	char *stop_point;
	int flag;
	static char *remains;
	flag = 1;
	while ((bytes_read = read(fd, buf, buf_size) && flag))
	{
		if ((stop_point = ft_strchr(buf, '\n')))
		{
			flag = 0;
			*stop_point = '\0';
			remains = ft_strdup(++stop_point);
		}
		*line = ft_strjoin(*line, buf);
	}
	return (0);
}
