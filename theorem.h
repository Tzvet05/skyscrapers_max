#ifndef THEOREM_H
# define THEOREM_H

# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>

void	putstr(char *str);
int		**malloc_arr(int size);
int		**fill_max_arr(int **arr, int size);
void	free_arr_int(int **arr, int size);
void	print_arr(int **arr, int size);
int		my_strlen(char *str);

int		param_verif(char *params);
int		*char_arr_to_int_arr(char *str, int size);
int		**apply_theorem(int **arr, int size, int *params);
int		theorem(int param, int nth_box, int v_max);
int		find_aligned_param(int column, int line, int side, int size, int *params);
int		nth_box_from_param(int column, int line, int side, int size);

#endif
