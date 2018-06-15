/*
** EPITECH PROJECT, 2017
** main.c
** File description:
** main function
*/
#include "bsq.h"

static char	*skip_line(char *str)
{
	char	*tmp;
	int	i;

	for (i = 0; str[i] != '\n'; ++i);
	tmp = malloc(sizeof(char) * my_strlen(str + i) + 1);
	my_strcpy(tmp, str + i);
	return (tmp);
}

static char	**read_file(char *filename)
{
	char		**tab = NULL;
	struct stat	s;
	int		handler = open(filename, O_RDONLY);
	int		size;
	char		*str;

	stat(filename, &s);
	size = s.st_size;
	str = malloc(sizeof(char *) * size + 1);
	if (read(handler, str, size) < 0)
		return (NULL);
	str = skip_line(str);
	tab  = my_str_to_wordtab_delim(str, '\n');
	close(handler);
	return (tab);
}

int main(int ac, char **av)
{
	char	**tab;
	int	**matrix;
	struct	square tool;

	tab = read_file(av[1]);
	if (errors(ac) == FAILURE || tab == NULL)
		return (FAILURE);
	matrix = algo(tab, &tool);
	if (matrix == NULL)
		return (FAILURE);
	display_map(tab, &tool);
	return (0);
}