/*
** perfect_lab.c for perfect_lab in /home/damier_a/IA/laby_parfait
** 
** Made by ambroise damier
** Login   <damier_a@epitech.net>
** 
** Started on  Wed May  6 11:56:32 2015 ambroise damier
** Last update Sun May 17 17:20:01 2015 Clementine Legenty
*/

#include "include/perfect_maze.h"

int	first(t_list *list, char **av)
{
  if (list->y_max % 2 == 0)
    if ((peer_maze_y(list)) == 1)
      return (1);
  list->x_max = my_getnbr(av[1]);
  if (list->x_max % 2 == 0)
    if ((peer_maze_x(list)) == 1)
      return (1);
  clean_maze(list);
  aff_maze(list);
  free(list->place);
  my_free(list->laby, list->y_max);
  free(list);
}

int		main(int ac, char **av)
{
  t_list	*list;

  if ((my_error(ac, av)) == 1)
    return (1);
  if ((list = malloc(sizeof(t_list))) == NULL)
    return (1);
  list->x_max = my_getnbr(av[1]);
  list->y_max = my_getnbr(av[2]);
  if (list->x_max <= 4 || list->y_max <= 4)
    {
      my_putstr("Veuillez insérer une taille significative (> à 4)\n");
      return (1);
    }
  if ((create_the_maze(list)) == 1)
    return (1);
  fill_the_maze(list);
  final_maze(list);
  list->y_max = my_getnbr(av[2]);
  first(list, av);
  return (0);
}
