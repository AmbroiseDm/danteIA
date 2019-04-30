/*
** aff_maze.c for  in /home/legent_c/rendu/dante/lab1/dante/labyrinthe_imparfait
** 
** Made by Clementine Legenty
** Login   <legent_c@epitech.net>
** 
** Started on  Sun May 17 16:20:30 2015 Clementine Legenty
** Last update Sun May 17 17:21:33 2015 Clementine Legenty
*/

#include "include/imperfect_maze.h"

void		aff_maze(t_list *list)
{
  int		fd;

  list->y = 0;
  fd = open("imperfect_maze.txt", O_RDWR | O_CREAT | O_TRUNC, 
	S_IRWXU | S_IRWXG | S_IRWXO);
  while ((list->y + 1) != list->y_max)
    {
      write(fd, list->laby[list->y], (list->x_max + 1));
      list->y++;
    }
  write(fd, list->laby[list->y], (list->x_max));
}

void		my_free(char **lab, int y_max)
{
  int		y;

  y = 0;
  while (y != y_max)
    {
      free(lab[y]);
      y++;
    }
  free(lab);
}

void		check_for_clean(t_list *list)
{
  if (list->y + 1 != list->y_max && list->x + 1 != list->x_max &&
      list->y != 0 && list->x != 0)
    {
      if (list->laby[list->y][list->x + 1] == 'X' &&
          list->laby[list->y - 1][list->x + 1] == 'X' &&
          list->laby[list->y + 1][list->x + 1] == 'X' &&
          list->laby[list->y - 1][list->x] == 'X' &&
          list->laby[list->y + 1][list->x] == 'X' &&
          (list->laby[list->y - 1][list->x] == '*' ||
           list->laby[list->y + 1][list->x] == '*' ||
           list->laby[list->y][list->x + 1] == '*' ||
           list->laby[list->y][list->x - 1] == '*'))
        list->laby[list->y][list->x] = '*';
      if (list->laby[list->y + 1][list->x + 1] == 'X' &&
          list->laby[list->y + 1][list->x - 1] == 'X' &&
          list->laby[list->y + 1][list->x] == 'X' &&
          list->laby[list->y][list->x + 1] == 'X' &&
          list->laby[list->y][list->x - 1] == 'X' &&
          (list->laby[list->y - 1][list->x] == '*' ||
           list->laby[list->y + 1][list->x] == '*' ||
           list->laby[list->y][list->x + 1] == '*' ||
           list->laby[list->y][list->x - 1] == '*'))
        list->laby[list->y][list->x] = '*';
    }
}

void		clean_maze(t_list *list)
{
  list->y = 0;
  list->x = 0;
  while (list->y != list->y_max)
    {
      while (list->x != list->x_max)
        {
          if (list->laby[list->y][list->x] == 'X')
            check_for_clean(list);
          list->x++;
        }
      list->x = 0;
      list->y++;
    }
}
