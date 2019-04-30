/*
** my_strlen.c for my_strlen in /home/damier_a/IA/profondeur
** 
** Made by ambroise damier
** Login   <damier_a@epitech.net>
** 
** Started on  Sun May 17 13:15:28 2015 ambroise damier
** Last update Sun May 17 17:37:58 2015 Clementine Legenty
*/

#include "include/solver.h"

int		my_strlen(char *str)
{
  int		n;

  n = 0;
  while (str[n] != '\0')
    n++;
  return (n);
}
