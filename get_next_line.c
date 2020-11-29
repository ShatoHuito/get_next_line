#include "get_next_line.h"

static char *search_and_write(const char *remains)
{
	int i;
	char *str;

	i = 0;
	while(remains != NULL && remains[i] != '\n' && remains[i])
		i++;
	if(!(str = malloc(sizeof(char) * (i + 1))))
		return (NULL);
	i = 0;
	while(remains != NULL && remains[i] != '\n' && remains[i])
	{
		str[i] = remains[i];
		i++;
	}
	str[i] = '\0';
	return (str);
}

static char *cut_remains(char *remains)
{
	size_t i;
	int j;
	char *str;

	i = 0;
	j = 0;
	if(remains == NULL)
		return (NULL);
	while(remains [i] != '\n' && remains[i])
		i++;
	if(remains[i] == '\n')
		i++;
	if (ft_strlen(remains) > i)
		str = malloc(sizeof(char) * (ft_strlen(remains) - i + 1));
	else
		str = malloc(sizeof(char) * (i + 1));
	if(str == NULL)
		return (NULL);
	while(remains[i] != '\0')
		str[j++] = remains[i++];
	str[j] = '\0';
	free(remains);
	return (str);
}

int get_next_line(int fd, char **line)
{
	char *buf;
	static char *remains;
	int read_b = 1;
	if ((BUFFER_SIZE < 1) || !(buf = malloc(sizeof(char) * (BUFFER_SIZE + 1))))
		return (-1);
	while (!(ft_strchr(remains, '\n')) && (read_b = read(fd, buf, BUFFER_SIZE)))
	{
		buf[read_b] = '\0';
		remains = ft_strjoin(remains, buf);
	}
	free(buf);
	*line = search_and_write(remains);
	remains = cut_remains(remains);
	if(read_b || ft_strlen(remains))
		return (1);
	return (0);
}