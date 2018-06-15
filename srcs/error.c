/*
** EPITECH PROJECT, 2017
** error.c
** File description:
** error handling
*/
#include "bsq.h"

static int	check_arg(int ac)
{
	if (ac < 2) {
		my_print_err(ERROR_MSG);
		return (FAILURE);
	}
	return (SUCCESS);
}

int	errors(int ac)
{
	if (check_arg(ac) == FAILURE)
		return (FAILURE);
	return (SUCCESS);
}