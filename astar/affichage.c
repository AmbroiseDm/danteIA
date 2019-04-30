/*
** affichage.c for  in /home/legent_c/rendu/dante/lab1/dante/profondeur
** 
** Made by Clementine Legenty
** Login   <legent_c@epitech.net>
** 
** Started on  Sun May 17 17:49:27 2015 Clementine Legenty
** Last update Sun May 17 23:15:42 2015 ambroise damier
*/

#include "include/get_next_line.h"
#include "include/solver.h"

void		aff_maze(t_data *data)
{
  int		fd;

  data->y = 0;
  fd = open("solver.txt", O_RDWR | O_CREAT | O_TRUNC,
	    S_IRWXU | S_IRWXG | S_IRWXO);
  while ((data->y + 1) != data->y_max)
    {
      write(fd, data->maze[data->y], (data->x_max + 1));
      data->y++;
    }
  write(fd, data->maze[data->y], (data->x_max));
}

void		affichage(t_data *data)
{
  int		y;
  int		x;

  y = 0;
  while (y != data->y_max)
    {
      x = 0;
      while (x != data->x_max)
        {
          if (data->maze[y][x] == '0' || data->maze[y][x] == '4')
            {
	      data->maze[y][x] = 'o';
            }
          else if (data->maze[y][x] == '3')
	    {
	      data->maze[y][x] = '*';
	    }
          x++;
        }
      if (y == data->y_max - 1)
	data->maze[y][x] = '\0';
      else
	data->maze[y][x] = '\n';
      y++;
    }
}

int		search_stars(t_data *data)
{
  if (data->x + 1 != data->x_max)
    if (data->maze[data->y][data->x + 1] == '*')
      {
        data->x++;
        data->maze[data->y][data->x] = '0';
        return (0);
      }
  if (data->y + 1 != data->y_max)
    if (data->maze[data->y + 1][data->x] == '*')
      {
        data->y++;
        data->maze[data->y][data->x] = '0';
        return (0);
      }
  if (data->y - 1 != -1)
    if (data->maze[data->y - 1][data->x] == '*')
      {
        data->y--;
        data->maze[data->y][data->x] = '0';
        return (0);
      }
  if (data->x - 1 != -1)
    if (data->maze[data->y][data->x - 1] == '*')
      {
	data->x--;
	data->maze[data->y][data->x] = '0';
	return (0);
      }
  return (1);
}

int		go_prev(t_data *data)
{
  if (data->y + 1 != data->y_max)
    if (data->maze[data->y + 1][data->x] == '0')
      {
        data->maze[data->y][data->x] = '3';
        data->y++;
        return (0);
      }
  if (data->x + 1 != data->x_max)
    if (data->maze[data->y][data->x + 1] == '0')
      {
        data->maze[data->y][data->x] = '3';
        data->x++;
        return (0);
      }
  if (data->x - 1 != -1)
    if (data->maze[data->y][data->x - 1] == '0')
      {
	data->maze[data->y][data->x] = '3';
	data->x--;
	return (0);
      }
  if (data->y - 1 != -1)
    if (data->maze[data->y - 1][data->x] == '0')
      {
        data->maze[data->y][data->x] = '3';
        data->y--;
        return (0);
      }
  
  data->maze[data->y][data->x] = '0';
  if (data->y + 1 != data->y_max && data->maze[data->y + 1][data->x] != 'X')  
    data->maze[data->y + 1][data->x] = '0';
  if (data->y - 1 != -1 && data->maze[data->y - 1][data->x] != 'X')
    data->maze[data->y - 1][data->x] = '0';
  if (data->x - 1 != -1 && data->maze[data->y][data->x - 1] != 'X')
    data->maze[data->y][data->x - 1] = '0';
  if (data->x + 1 != data->x_max && data->maze[data->y][data->x + 1] != 'X')
    data->maze[data->y][data->x + 1] = '0';
  return (0);
}
