/*
** peer_y.c for fpy in /home/damier_a/IA/labyrinthe_parfait
** 
** Made by ambroise damier
** Login   <damier_a@epitech.net>
** 
** Started on  Fri May 15 20:13:59 2015 ambroise damier
** Last update Sun May 17 17:13:48 2015 Clementine Legenty
*/

#include "include/perfect_maze.h"

void		fply_next(t_list *list)
{
  if (list->j == list->r_y && (list->y_max % 2 == 0))
    {
      while (list->i != list->x_max)
        {
          if ((list->laby[(list->y - 1)][list->i] == '*') && 
		(list->laby[(list->y)][list->i] == '*'))
            list->tmp_lab[list->j][list->i] = '*';
          else
            list->tmp_lab[list->j][list->i] = 'X';
          list->i++;
        }
    }
  else
    {
      while (list->i != list->x_max)
        {
          list->tmp_lab[list->j][list->i] = list->laby[list->y][list->x];
          list->x++;
          list->i++;
        }
      list->y++;
    }
}

int		fill_peer_maze_y(t_list *list)
{
  while (list->j != list->y_max)
    {
      if (!(list->tmp_lab[list->j] = malloc(sizeof(char) * (list->x_max + 1))))
        return (1);
      fply_next(list);
      if (list->j == list->y_max - 1)
	list->tmp_lab[list->j][list->i] = '\0';
      else
	list->tmp_lab[list->j][list->i] = '\n';
      list->i = 0;
      list->x = 0;
      list->j++;
    }
}

int		peer_maze_y(t_list *list)
{
  list->x = 0;
  list->y = 0;
  list->i = 0;
  list->j = 0;
  list->r_y = rand();
  list->r_y = (list->r_y % (list->y_max - 2)) + 1;
  if ((list->tmp_lab = malloc(sizeof(char *) * (list->y_max + 1))) == NULL)
    return (1);
  if ((fill_peer_maze_y(list)) == 1)
    return (1);
  my_free(list->laby, (list->y_max - 1));
  list->laby = list->tmp_lab;
  return (0);
}
