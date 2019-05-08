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
		astar.c

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
