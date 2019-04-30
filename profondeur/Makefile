##
## Makefile for makefile in /home/damier_a/IA/laby_2
## 
## Made by ambroise damier
## Login   <damier_a@epitech.net>
## 
## Started on  Thu May  7 22:18:46 2015 ambroise damier
## Last update Sun May 17 23:23:54 2015 ambroise damier
##

CC	=	gcc

RM	=	rm -f

CFLAGS	=	-Wall -Wextra -Werror
CFLAGS	=	-ansi -pedantic
CFLAGS	=	-I./include

NAME	=	solver

SRCS	=	get_next_line.c				\
		my_strlen.c				\
		affichage.c				\
		my_error.c				\
		basic_fct.c				\
		profondeur.c

OBJS	=	$(SRCS:.c=.o)

all	:	$(NAME)

$(NAME)	:	$(OBJS)
		$(CC) $(OBJS) -o $(NAME) $(CFLAGS)

clean	:
		$(RM) $(OBJS)

fclean	:	clean
		$(RM) $(NAME)

re	:	fclean all

.PHONY	:	all clean fclean re
