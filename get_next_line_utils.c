#include "get_next_line.h"

size_t  ft_strlen(const char *str)
{
	size_t a;

	a = 0;
	while (*str++)
		a++;
	return (a);
}

char    *ft_strjoin(char const *s1, char const *s2)
{
	char    *str;
	int     i;
	int     f;

	if (s1 == NULL || s2 == NULL)
		return (NULL);
	i = 0;
	f = 0;
	str = (char *)malloc(ft_strlen(s1) + ft_strlen(s2) + 1);
	if (str != NULL)
	{
		while (s1[i] != '\0')
			str[f++] = s1[i++];
		i = 0;
		while (s2[i] != '\0')
			str[f++] = s2[i++];
		str[f++] = '\0';
		return (str);
	}
	else
		return (NULL);
}

char    *ft_strchr(const char *s, int c)
{
	while (*s != '\0' && *s != (char)c)
		s++;
	if (*s == c)
		return ((char*)s);
	return (NULL);
}

char    *ft_strdup(const char *s1)
{
	char *p;

	p = (char *)malloc(ft_strlen(s1) + 1);
	if (p != NULL)
	{
		ft_strcpy(p, s1);
		return (p);
	}
	else
		return (NULL);
}

char    *ft_strcpy(char *dst, const char *src)
{
	int i;

	i = 0;
	while (src[i] != '\0')
	{
		dst[i] = src[i];
		i++;
	}
	dst[i] = '\0';
	return (dst);
}


