/*
** EPITECH PROJECT, 2017
** my_strlen.c
** File description:
** returns the length of string
*/
#include "my.h"

int my_strlen(char const *str)
{
	int	i = 0;

	while (str && str[i])
		++i;
	return (i);
}