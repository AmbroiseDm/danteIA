##
## Makefile for makefile in /home/damier_a/IA/laby_2
## 
## Made by ambroise damier
## Login   <damier_a@epitech.net>
## 
## Started on  Thu May  7 22:18:46 2015 ambroise damier
## Last update Sun May 17 16:59:56 2015 Clementine Legenty
##

CC	=	gcc

RM	=	rm -f

CFLAGS	=	-Wall -Wextra -Werror
CFLAGS	=	-ansi -pedantic
CFLAGS	=	-I./include

NAME	=	imperfect_maze

SRCS	=	imperfect_lab.c				\
		peer_x.c				\
		peer_y.c				\
		create_the_lab.c			\
		search_pos.c				\
		aff_maze.c				\
		final_maze.c				\
		basic_fct.c				\
		my_getnbr.c				\
		four_cardinal.c

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
