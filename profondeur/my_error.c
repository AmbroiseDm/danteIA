/*
** my_error.c for  in /home/legent_c/rendu/dante/lab1/dante/profondeur
** 
** Made by Clementine Legenty
** Login   <legent_c@epitech.net>
** 
** Started on  Sun May 17 17:55:02 2015 Clementine Legenty
** Last update Sun May 17 22:58:10 2015 ambroise damier
*/

#include "include/get_next_line.h"
#include "include/solver.h"

int		check_room(t_data *data)
{
  if (search_stars(data) == 0)
    return (0);
  if (go_prev(data) == 0)
    return (0);
  return (1);
}

int		my_error(int ac, char **av)
{
  if (ac != 2)
    {
      my_putstr("Veuillez insérer 1 arguments en paramètre.\n");
      return (1);
    }
  /* if (ac == 3) */
  /*   if (av[2][0] != '-' && av[2][1] != 's') */
  /*     { */
  /* 	my_putstr("pour afficher l'algo au ralenti, insérez -s\n"); */
  /*     } */
  return (0);
}

int		check_err2(t_data *data)
{
  if (data->x - 1 != -1)
    if (data->maze[data->y][data->x + 1] != 'X' &&
	data->maze[data->y][data->x + 1] != '0')
      {
	data->maze[data->y][data->x + 1] = '4';
	return (0);
      }
  if (data->y - 1 != -1)
    if (data->maze[data->y - 1][data->x] != 'X' &&
	data->maze[data->y - 1][data->x] != '0')
      {
	data->maze[data->y - 1][data->x] = '4';
	return (0);
      }
  if (data->y + 1 != data->y_max)
    if (data->maze[data->y + 1][data->x] != 'X' &&
	data->maze[data->y + 1][data->x] != '0')
      {
	data->maze[data->y + 1][data->x] = '4';
	return (0);
      }
}

int		check_err(t_data *data)
{
  int		n;

  n = 0;
  if (data->x - 1 != -1)
    if (data->maze[data->y][data->x - 1] == '0')
      n++;
  if (data->x + 1 != data->x_max)
    if (data->maze[data->y][data->x + 1] == '0')
      n++;
  if (data->y - 1 != -1)
    if (data->maze[data->y - 1][data->x] == '0')
      n++;
  if (data->y + 1 != data->y_max)
    if (data->maze[data->y + 1][data->x] == '0')
      n++;
  if (n != 2)
    {
      if (data->x + 1 != data->x_max)
        if (data->maze[data->y][data->x - 1] != 'X' &&
            data->maze[data->y][data->x - 1] != '0')
          {
            data->maze[data->y][data->x - 1] = '4';
            return (0);
	  }
      check_err2(data);
    }
}
