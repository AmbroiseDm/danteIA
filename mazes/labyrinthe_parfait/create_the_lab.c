#include "include/perfect_maze.h"

void		random_pos(t_list *list)
{
  int		n;
  int		r;

  n = 0;
  r = rand();
  r = (r % list->n_place) + 1;
  list->n_place = -1;
  while (n != r)
    {
      list->n_place++;
      if (list->place[list->n_place] == 1)
	n++;
    }
  if (list->n_place == 0)
    north(list);
  if (list->n_place == 1)
    south(list);
  if (list->n_place == 2)
    east(list);
  if (list->n_place == 3)
    west(list);
}

int		fill_the_maze(t_list *list)
{
  list->x = 0;
  list->y = 0;
  srand(time(NULL));
  if ((list->place = malloc(sizeof(int) * 5)) == NULL)
    return (1);
  if ((check_pos(list)) == 1)
    return (1);
  random_pos(list);
  while (list->x != 0 || list->y != 0)
    {
      if ((check_pos(list)) == 1)
	return (1);
      if (list->n_place == 0 || 
	  (list->y == (list->y_max - 1) && list->x == (list->x_max - 1)))
	{
	  list->laby[list->y][list->x] = '3';
	  check_last_pos(list);
	}
      else
	random_pos(list);
    }
  return (0);
}

int		create_the_maze(t_list *list)
{
  list->x = list->y = 0;
  if (list->x_max % 2 == 0)
    list->x_max--;
  if (list->y_max % 2 == 0)
    list->y_max--;
  if ((list->laby = malloc(sizeof(char *) * (list->y_max) + 1)) == NULL)
    return (1);
  while (list->y != list->y_max)
    {
      if ((list->laby[list->y] = malloc(sizeof(char) * (list->x_max + 1))) == NULL)
	return (1);
      while (list->x != list->x_max)
        {
          if (list->y % 2 == 0 && list->x % 2 == 0)
            list->laby[list->y][list->x] = '2';
          else
            list->laby[list->y][list->x] = '1';
          list->x++;
        }
      list->laby[list->y][list->x] = '\0';
      list->x = 0;
      list->y++;
    }
  list->laby[0][0] = '0';
  return (0);
}
