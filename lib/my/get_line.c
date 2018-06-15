/*
** EPITECH PROJECT, 2017
** get_line.c
** File description:
** getting line
*/
#include "my.h"

static char	*my_rea_cat(char *str, char buf)
{
	int	i = 0;
	char	*res = malloc(sizeof(char) * (my_strlen(str)) + 2);

	while (str && str[i]) {
		res[i] = str[i];
		++i;
	}
	if (buf != '\n' && buf != '\0') {
		res[i] = buf;
		i++;
	}
	res[i] = 0;
	if (str != NULL)
		my_free(str);
	return (res);
}

char		*get_line(int fd)
{
	char		*str;
	char		buf;

	str = NULL;
	while (42)
	{
		if ((read(fd, &buf, 1)) <= 0)
			return (str);
		if (buf == '\0' || buf == '\n') {
			str = my_rea_cat(str, buf);
			return (str);
		}
		str = my_rea_cat(str, buf);
	}
}