/*
** search_pos.c for search_pos in /home/damier_a/IA/laby_2
** 
** Made by ambroise damier
** Login   <damier_a@epitech.net>
** 
** Started on  Thu May  7 22:06:04 2015 ambroise damier
** Last update Sun May 17 16:40:10 2015 Clementine Legenty
*/

#include "include/imperfect_maze.h"

int		fill_place(t_list *list, int y, int x)
{
  if (y < 0 || y > list->y_max || x < 0 || x > list->x_max)
    return (0);
  if (list->laby[y][x] == '2')
    {
      list->n_place++;
      return (1);
    }
  return (0);
}

int		check_pos(t_list *list)
{
  list->n_place = 0;
  list->place[0] = fill_place(list, (list->y - 2), list->x);
  list->place[1] = fill_place(list, (list->y + 2), list->x);
  list->place[2] = fill_place(list, list->y, (list->x + 2));
  list->place[3] = fill_place(list, list->y, (list->x - 2));
  return (0);
}

void		fill_last_pos(t_list *list, int y, int x)
{
  if (y >= 0 && y < (list->y_max) && x >= 0 && x < (list->x_max))
    {
      if (list->laby[y][x] == '0')
        {
          list->laby[y][x] = '3';
          list->x = x + (x - list->x);
          list->y = y + (y - list->y);
        }
    }
}

void		check_last_pos(t_list *list)
{
  fill_last_pos(list, (list->y - 1), list->x);
  fill_last_pos(list, (list->y + 1), list->x);
  fill_last_pos(list, list->y, (list->x + 1));
  fill_last_pos(list, list->y, (list->x - 1));
}
