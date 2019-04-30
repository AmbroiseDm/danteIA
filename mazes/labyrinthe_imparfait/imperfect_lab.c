/*
** perfect_lab.c for perfect_lab in /home/damier_a/IA/laby_parfait
** 
** Made by ambroise damier
** Login   <damier_a@epitech.net>
** 
** Started on  Wed May  6 11:56:32 2015 ambroise damier
** Last update Sun May 17 16:58:37 2015 Clementine Legenty
*/

#include "include/imperfect_maze.h"

void		is_breakable(t_list *list)
{
  int		rd;

  rd = rand();
  if (((list->laby[list->y - 1][list->x] == '*') &&
       (list->laby[list->y + 1][list->x] == '*') &&
       (list->laby[list->y][list->x - 1] == 'X') &&
       (list->laby[list->y][list->x + 1] == 'X')) ||
      ((list->laby[list->y - 1][list->x] == 'X') &&
       (list->laby[list->y + 1][list->x] == 'X') &&
       (list->laby[list->y][list->x - 1] == '*') &&
       (list->laby[list->y][list->x + 1] == '*')))
    {
      if ((rd % list->prop) == 0 || list->i == 0)
	list->laby[list->y][list->x] = '*';
      list->i++;
    }
}

void		choose_prop(t_list *list)
{
  int		n;

  if (list->y_max <= list->x_max)
    n = list->y_max;
  else
    n = list->x_max;
  if (n > 4 && n <= 6)
    list->prop = 3;
  if (n > 6  && n <= 10)
    list->prop = 5;
  if (n > 10 && n <= 18)
    list->prop = 7;
  if (n > 18 && n <= 34)
    list->prop = 9;
  if (n > 34)
    list->prop = 11;
}

void		break_the_wall(t_list *list)
{
  list->x = 1;
  list->y = 1;
  list->i = 0;
  choose_prop(list);
  while (list->y != list->y_max - 1)
    {
      while (list->x != list->x_max - 1)
	{
	  is_breakable(list);
	  list->x++;
	}
      list->x = 1;
      list->y++;
    }
}

int	first(t_list *list, char **av)
{
  if (list->y_max % 2 == 0)
    if ((peer_maze_y(list)) == 1)
      return (1);
  list->x_max = my_getnbr(av[1]);
  if (list->x_max % 2 == 0)
    if ((peer_maze_x(list)) == 1)
      return (1);
  clean_maze(list);
  break_the_wall(list);
  aff_maze(list);
  free(list->place);
  my_free(list->laby, list->y_max);
  free(list);
}

int		main(int ac, char **av)
{
  t_list	*list;

  if ((my_error(ac, av)) == 1)
    return (1);
  if ((list = malloc(sizeof(t_list))) == NULL)
    return (1);
  list->x_max = my_getnbr(av[1]);
  list->y_max = my_getnbr(av[2]);
  if (list->x_max <= 4 || list->y_max <= 4)
    {
      my_putstr("Veuillez insérer une taille significative (> à 4)\n");
      return (1);
    }
  if ((create_the_maze(list)) == 1)
    return (1);
  fill_the_maze(list);
  final_maze(list);
  list->y_max = my_getnbr(av[2]);
  first(list, av);
  return (0);
}
