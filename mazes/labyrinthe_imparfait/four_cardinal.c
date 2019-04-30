/*
** four_cardinal.c for cardinal in /home/damier_a/IA/laby_2
** 
** Made by ambroise damier
** Login   <damier_a@epitech.net>
** 
** Started on  Thu May  7 05:36:03 2015 ambroise damier
** Last update Sun May 17 16:11:59 2015 Clementine Legenty
*/

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
