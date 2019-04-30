/*
** my.h for my_h in /home/damier_a/IA/laby_parfait
** 
** Made by ambroise damier
** Login   <damier_a@epitech.net>
** 
** Started on  Wed May  6 11:53:58 2015 ambroise damier
** Last update Sun May 17 18:00:50 2015 Clementine Legenty
*/

#ifndef PERFECT_MAZE_H_
#define PERFECT_MAZE_H_

#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>

typedef struct	s_list
{
  int		x;
  int		y;
  int		x_max;
  int		y_max;
  char		**laby;
  char		**tmp_lab;
  int		*place;
  int		n_place;
  int		r_x;
  int		r_y;
  int		i;
  int		j;
  int		prop;
}		t_list;


int		clacul(char *, int, int);
int		my_getnbr(char *);
int		first(t_list *, char **);
int		create_the_maze(t_list *list);
int		fill_the_maze(t_list *list);
int		check_pos(t_list *list);
int		fill_place(t_list *list, int y, int x);
void		check_last_pos(t_list *list);
void		fill_last_pos(t_list *list, int y, int x);
void		random_pos(t_list *list);
void		north(t_list *list);
void		south(t_list *list);
void		east(t_list *list);
void		west(t_list *list);
void		fplx_next(t_list *list);
void		aff_maze(t_list *);
void		my_free(char **, int);
void		check_for_clean(t_list *);
void		clean_maze(t_list *);
void		final_maze_next(t_list *);
void		final_maze(t_list *);
int		check_arg(char *);
int		my_error(int, char **);
void		is_breakable(t_list *);
void		choose_prop(t_list *);
void		break_the_wall(t_list *);
int		fill_peer_maze_x(t_list *list);
int		peer_maze_x(t_list *list);
void		fply_next(t_list *list);
int		fill_peer_maze_y(t_list *list);
int		peer_maze_y(t_list *list);
void		my_putchar(char);
void		my_putstr(char *);

#endif /* !PERFECT_MAZE_H_ */
