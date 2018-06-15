##
## EPITECH PROJECT, 2017
## Makefile
## File description:
## A Makefile for projetcs
##

CC	=	gcc -O3

RM	=	rm -rf

CFLAGS	+=	-Wall -Wextra -O3

CFLAGS	+=	-I./include

NAME	=	bsq

SRCS	=	srcs/main.c \
		srcs/error.c \
		srcs/algo.c \
		srcs/display.c

OBJS	=	$(SRCS:.c=.o)

LIB =		-L./lib -lmy

all: $(NAME)

$(NAME): $(OBJS)
	make -C ./lib/my
	$(CC) $(OBJS) -o $(NAME) $(LIB)

clean:
	$(RM) $(OBJS)
	make -C ./lib/my clean

fclean: clean
	$(RM) $(NAME)
	$(RM) lib/*.a
	make -C ./lib/my fclean


re: fclean all

.PHONY: all clean fclean re