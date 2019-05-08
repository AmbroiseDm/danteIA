#ifndef			SOLVER_H_
# define		SOLVER_H_

# define BLACK		"\033[1;30m"
# define RED		"\033[1;31m"
# define GREEN		"\033[1;32m"
# define YELLOW		"\033[1;33m"
# define BLUE		"\033[1;34m"
# define PURPLE		"\033[1;35m"
# define CYAN		"\033[1;36m"
# define GREY		"\033[1;37m"
# define DEFAULT_COLOR	"\033[0;m"

#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

typedef struct	s_data
{
  int		flag;
  int		x_max;
  int		y_max;
  int		x;
  int		y;
  int		fd;
  char		**maze;
}		t_data;


void		affichage(t_data *);
t_data		*search_stars2(t_data *);
int		search_stars(t_data *);
t_data		*go_prev2(t_data *);
int		go_prev(t_data *);
int		check_room(t_data *);
int		my_error(int, char **);
int		check_err2(t_data *);
int		check_err(t_data *);
int		my_strlen(char *);
int		size_xmax(t_data *);
int		init(t_data *, char **);
void		clean(t_data *);
int		search_path(t_data *);

#endif /* !SOLVER_H_ */
