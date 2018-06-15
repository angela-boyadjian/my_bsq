/*
** EPITECH PROJECT, 2017
** bsq.h
** File description:
** header file for bsq
*/
#ifndef BSQ_H_
#define BSQ_H_

#include "my.h"
#include "error.h"

struct square {
	int	nb;
	int	x;
	int	y;
	int	size_x;
	int	size_y;
};

int	errors(int ac);
int	**algo(char **tab, struct square *tool);
void	display_map(char **tab, struct square *tool);

#endif /* !BSQ_H_ */