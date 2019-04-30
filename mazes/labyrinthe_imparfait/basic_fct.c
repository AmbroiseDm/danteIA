/*
** basic_fct.c for  in /home/legent_c/rendu/dante/lab1/dante/mazes/labyrinthe_imparfait
** 
** Made by Clementine Legenty
** Login   <legent_c@epitech.net>
** 
** Started on  Sun May 17 16:45:19 2015 Clementine Legenty
** Last update Sun May 17 18:08:34 2015 Clementine Legenty
*/

#include "imperfect_maze.h"

void	my_putchar(char c)
{
  write(1, &c, 1);
}

void	my_putstr(char *str)
{
  int	i;

  i = 0;
  while (str[i])
    {
      my_putchar(str[i]);
      ++i;
    }
}
