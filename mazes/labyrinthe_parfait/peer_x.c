#include "include/perfect_maze.h"

void		fplx_next(t_list *list)
{
  if ((list->i == list->r_x) && (list->x_max % 2 == 0))
    {
      if ((list->laby[(list->j)][list->x - 1] == '*') && 
	(list->laby[(list->j)][list->x] == '*'))
        list->tmp_lab[list->j][list->i] = '*';
      else
        list->tmp_lab[list->j][list->i] = 'X';
    }
  else
    {
      list->tmp_lab[list->j][list->i] = list->laby[list->y][list->x];
      list->x++;
    }
  list->i++;
}

int		fill_peer_maze_x(t_list *list)
{
  while (list->j != list->y_max)
    {
      if (!(list->tmp_lab[list->j] = malloc(sizeof(char) * (list->x_max + 1))))
        return (1);
      while (list->i != list->x_max)
        fplx_next(list);
      if (list->j == list->y_max - 1)
	list->tmp_lab[list->j][list->i] = '\0';
      else
	list->tmp_lab[list->j][list->i] = '\n';
      list->y++;
      list->i = 0;
      list->x = 0;
      list->j++;
    }
}

int		peer_maze_x(t_list *list)
{
  list->x = 0;
  list->y = 0;
  list->i = 0;
  list->j = 0;
  list->r_x = rand();
  list->r_x = (list->r_x % (list->x_max - 2)) + 1;
  if ((list->tmp_lab = malloc(sizeof(char *) * list->y_max)) == NULL)
    return (1);
  if ((fill_peer_maze_x(list)) == 1)
    return (1);
  my_free(list->laby, list->y_max);
  list->laby = list->tmp_lab;
  return (0);
}
