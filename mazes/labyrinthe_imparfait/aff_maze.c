#include "include/imperfect_maze.h"

void		aff_maze(t_list *list)
{
  int		fd;

  list->y = 0;
  fd = open("imperfect_maze.txt", O_RDWR | O_CREAT | O_TRUNC, 
	S_IRWXU | S_IRWXG | S_IRWXO);
  while ((list->y + 1) != list->y_max)
    {
      my_putstr(list->laby[list->y]);
      write(fd, list->laby[list->y], (list->x_max + 1));
      list->y++;
    }
  write(fd, list->laby[list->y], (list->x_max));
  my_putchar('\n');
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
