/*
** EPITECH PROJECT, 2017
** display.c
** File description:
** displays map
*/
#include "bsq.h"

static void	fill_square(char **tab, struct square *tool)
{
	for (int i = 0; i < tool->nb; ++i) {
		for (int j = 0; j < tool->nb; ++j) {
			tab[tool->y - i][tool->x - j] = 'x';
		}
	}
}

static void my_show_tab(char **tab, int size)
{
	for (int i = 0; tab[i]; ++i) {
		write(1, tab[i], size);
		my_putchar('\n');
	}
}

void	display_map(char **tab, struct square *tool)
{
	fill_square(tab, tool);
	my_show_tab(tab, my_strlen(tab[0]));
}