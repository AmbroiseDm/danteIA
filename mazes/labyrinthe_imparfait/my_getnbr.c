#include "include/imperfect_maze.h"

int	my_getnbr(char *str)
{
  int	i;
  int	j;
  int	k;

  i = 0;
  j = 0;
  k = 1;
  while (str[i] != '\0' && (str[i] == '+' || str[i] == '-'))
    {
      if (str[i] == '-')
	k = k * (-1);
      i = i + 1;
    }
  str = str + i;
  i = 0;
  if (str[i] < '0' || str[i] > '9')
    {
      return (-2);
    }
  j = calcul(str, i, j);
  if (j < 0)
    return (-2);
  else
    return (j * k);
}

int	calcul(char *str, int i, int j)
{
  while (str[i] >= '0' && str[i] <= '9')
    {
      j = (j * 10) + str[i] - '0';
      i = i + 1;
    }
  return (j);
}
