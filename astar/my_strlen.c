#include "include/solver.h"

int		my_strlen(char *str)
{
  int		n;

  n = 0;
  while (str[n] != '\0')
    n++;
  return (n);
}
