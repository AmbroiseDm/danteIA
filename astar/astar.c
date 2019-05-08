#include "include/solver.h"
#include "include/get_next_line.h"

void		new_affichage(t_data *data)
{
  int		y;
  int		x;

  y = 0;
  usleep(50000);
  while (y != data->y_max)
    {
      x = 0;
      while (x != data->x_max)
	{
	  if (data->maze[y][x] == '3')
	    my_putstr(BLUE);
	  if (data->maze[y][x] == '0' || data->maze[y][x] == 'o')
	    my_putstr(RED);
	  my_putchar(data->maze[y][x]);
	  my_putstr(DEFAULT_COLOR);
	  x++;
	}
      my_putstr("\n");
      y++;
    }
  my_putstr("\n");
}

int		search_path(t_data *data)
{
  int		n;
  int		n_max;

  data->x = 0;
  data->y = 0;
  n = 0;
  n_max = (data->x_max * data->y_max * 2);
  if (data->x_max <= 0 || data->y_max <= 0)
    return (1);
  if (data->maze[0][0] == '*')
    data->maze[0][0] = '0';
  else
    return (1);
  if (check_room(data) == 1)
    return (1);
  // this loop defines each iteration of the path search 
  while ((data->x != data->x_max - 1) || (data->y != data->y_max - 1))
    {
      if (n >= n_max)
	return (1);
      // check room will find what will be the next cell
      if (check_room(data) == 1)
	return (1);
      if (data->x == 0 && data->y == 0)
	return (1);
      new_affichage(data);
      n++;
    }
  return (0);
}

int		size_xmax(t_data *data)
{
  int		tmp_x;

  tmp_x = -1;
  data->y = 0;
  while (data->y != data->y_max)
    {
      data->x_max = 0;
      while (data->maze[data->y][data->x_max] != '\n' &&
	     data->maze[data->y][data->x_max] != '\0')
	data->x_max++;
      if (tmp_x != -1)
	if (tmp_x != data->x_max)
	  return (1);
      tmp_x = data->x_max;
      data->y++;
    }
  return (0);
}

int		init(t_data *data, char **av)
{
  char		*str;
  int		n;

  n = 0;
  data->y_max = 0;
  data->y = 0;
  if ((data->fd = open(av[1], O_RDONLY)) == -1)
    return (1);
  while ((str = get_next_line(data->fd)) != NULL)
    {
      n++;
      if (n >= 1000)
	return (1);
      data->y_max++;
    }
  if (close(data->fd) == -1)
    return (1);
  // open the file in parameter
  if ((data->fd = open(av[1], O_RDONLY)) == -1)
    return (1);
  if ((data->maze = malloc(sizeof(char *) * data->y_max)) == NULL)
    return (1);
  // get_next_line fonction allow to read a line in a file
  while ((str = get_next_line(data->fd)) != NULL)
    {
      data->maze[data->y] = str;
      data->y++;
    }
  if (size_xmax(data) == 1)
    return (1);
}

void		clean(t_data *data)
{
  data->y = 1;
  while (data->y != data->y_max - 1)
    {
      data->x = 0;
      while (data->x != data->x_max)
	{
	  if (data->maze[data->y][data->x] == '0' ||
	      data->maze[data->y][data->x] == '4')
	    check_err(data);
	  data->x++;
	}
      data->y++;
    }
}  

int		main(int ac, char **av)
{
  t_data	*data;

  if ((my_error(ac, av)) == 1)
    return (1);
  /* if (ac == 3) */
  /*   data->flag = 1; */
  /* else */
  /*   data->flag = 0; */
  if ((data = malloc(sizeof(t_data))) == NULL)
    return (1);
  if ((init(data, av)) == 1)
    return (1);
  if (search_path(data) == 1)
    return (1);
  clean(data);
  affichage(data);
  aff_maze(data);
  return (0);
}
