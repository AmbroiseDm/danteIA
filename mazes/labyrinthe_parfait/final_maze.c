#include "include/perfect_maze.h"

void		final_maze_next(t_list *list)
{
  if (list->laby[list->y_max - 2][list->x_max - 1] == 'X' &&
      list->laby[list->y_max - 1][list->x_max - 2] == 'X')
    {
      list->r_x = rand();
      if (list->r_x % 2 == 0)
        list->laby[list->y_max - 2][list->x_max - 1] = '*';
      else
        list->laby[list->y_max - 1][list->x_max - 2] = '*';
    }
}

void		final_maze(t_list *list)
{
  int		y;
  int		x;

  y = 0;
  x = 0;
  while (y != list->y_max)
    {
      while (x != list->x_max)
        {
          if (list->laby[y][x] == '1')
            list->laby[y][x] = 'X';
          else
            list->laby[y][x] = '*';
          x++;
        }
      if (y == list->y_max - 1)
        list->laby[y][x] = '\0';
      else
        list->laby[y][x] = '\n';
      x = 0;
      y++;
    }
  final_maze_next(list);
}

int		check_arg(char *str)
{
  int		n;

  n = 0;
  while (str[n] != '\0')
    {
      if (str[n] < '0' || str[n] > '9' || n > 9)
	{
	  my_putstr("Les arguments doivent être des entiers positifs\n");
	  return (1);
	}
      if (n >= 9)
	return (1);
      n++;
    }
  return (0);
}

int		my_error(int ac, char **av)
{
  if (ac != 3)
    {
      my_putstr("Veuillez insérer 2 arguments en paramètre.\n");
      return (1);
    }
  else
    {
      if ((check_arg(av[1])) == 1)
        return (1);
      if ((check_arg(av[2])) == 1)
        return (1);
    }
  return (0);
}
