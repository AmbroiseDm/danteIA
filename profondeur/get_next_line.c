/*
** get_next_line.c for damier_a in /home/damier_a/progelem/CPE_2014_allum1/lib
** 
** Made by ambroise damier
** Login   <damier_a@epitech.net>
** 
** Started on  Sun Feb 22 21:40:54 2015 ambroise damier
** Last update Sun May 17 22:07:41 2015 ambroise damier
*/

#include "include/get_next_line.h"
#include "include/solver.h"

int	my_cat_line(char *line, char *buff)
{
  int	i;
  int	j;

  j = 0;
  i = my_strlen(line);
  while (buff[j])
    {
      if (buff[j] == '\n')
	{
	  line[i] = 0;
	  if (buff[j] == '\n')
	    j++;
	  return (1);
	}
      line[i++] = buff[j++];
    }
  line[i] = 0;
  return (0);
}

char	*get_next_line(const int fd)
{
  char	buff[BUFF_SIZE + 1];
  char	*line;
  int	len;
  int	n;

  n = 0;
  if (!(line = malloc(4096 * sizeof(char))))
    return (NULL);
  if (line == NULL)
    return (NULL);
  line[0] = 0;
  while ((len = read(fd, buff, BUFF_SIZE)) > 0)
    {
      n++;
      if (n >= 1000)
	return (NULL);
      buff[len] = 0;
      if (my_cat_line(line, buff) == 1)
	return (line);
    }
  if (line && line[0] != 0)
    return (line);
  return (NULL);
}
