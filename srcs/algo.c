/*
** EPITECH PROJECT, 2017
** algo.c
** File description:
** algorithm for the bsq project
*/
#include "bsq.h"

static int	check_pos(char **tab, int **matrix, int i, int j)
{
	int	min = 0;

	if (tab[i][j] == 'o')
		return (0);
	if (i == 0 || j == 0)
		return (1);
	min = matrix[i - 1][j];
	if (min > matrix[i][j- 1])
		min = matrix[i][j - 1];
	if (min > matrix[i - 1][j - 1])
		min = matrix[i - 1][j - 1];
	min += 1;
	return (min);
}

static void	init(struct square *tool, char **tab)
{
	tool->nb = 0;
	tool->x = 0;
	tool->y = 0;
	tool->size_x = my_strlen(tab[0]);
	tool->size_y = my_strarraylen(tab);
}

static void	check_nb(int **matrix, struct square *tool, int i, int j)
{
	if (tool->nb < matrix[i][j]) {
		tool->nb = matrix[i][j];
		tool->x = j;
		tool->y = i;
	}
}

int	**algo(char **tab, struct square *tool)
{
	int	**matrix;
	int	i = 0;
	int	j = 0;

	init(tool, tab);
	matrix = malloc(sizeof(int *) * tool->size_y);
	if (matrix == NULL)
		return (NULL);
	while (tab[i]) {
		matrix[i] = malloc(sizeof(int) * tool->size_x);
		j = 0;
		while (tab[i][j]) {
			matrix[i][j] = check_pos(tab, matrix, i, j);
			check_nb(matrix, tool, i, j);
			++j;
		}
		++i;
	}
	return (matrix);
}