#include "include/imperfect_maze.h"

void		north(t_list *list)
{
  list->laby[list->y - 1][list->x] = '0';
  list->laby[list->y - 2][list->x] = '0';
  list->y = list->y - 2;
}

void		south(t_list *list)
{
  list->laby[list->y + 1][list->x] = '0';
  list->laby[list->y + 2][list->x] = '0';
  list->y = list->y + 2;
}

void		east(t_list *list)
{
  list->laby[list->y][list->x + 1] = '0';
  list->laby[list->y][list->x + 2] = '0';
  list->x = list->x + 2;
}

void		west(t_list *list)
{
  list->laby[list->y][list->x - 1] = '0';
  list->laby[list->y][list->x - 2] = '0';
  list->x = list->x - 2;
}
