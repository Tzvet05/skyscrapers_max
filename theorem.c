// Theorem : the value found in a box is always lesser or equal to the maximum value (the size) minus the difference between a POV value aligned with the box and the number of boxes separating the box from the POV value (1 minimum)

#include "theorem.h"

int	param_verif(char *params)
{
	int	i = 0;
	int	count = 0;

	while (params[i])
	{
		if (params[i] != ' ' && !(params[i] >= '0' && params[i] <= '9'))
			return (1);
		else if ((params[i] >= '0' && params[i] <= '9')
			&& (params[i + 1] == ' ' || params[i + 1] == '\0'))
			count++;
		i++;
	}
	if ((count % 4) != 0 || count == 0)
		return (1);
	return (0);
}

int	*char_arr_to_int_arr(char *str, int size)
{
	int	*int_arr;
	int	i = 0;
	int	nb = 0;
	int	i_nb = 0;

	int_arr = malloc((size * 4) * sizeof(int));
	if (int_arr == NULL)
		return (NULL);
	while (str[i])
	{
		if (str[i] >= '0' && str[i] <= '9')
			nb = (nb * 10) + (str[i] - 48);
		if (nb != 0 && str[i] == ' ')
		{
			int_arr[i_nb] = nb;
			i_nb++;
			nb = 0;
		}
		i++;
	}
	int_arr[i_nb] = nb;
	return (int_arr);
}

int	**apply_theorem(int **arr, int size, int *params)
{
	int	param;
	int	nth_box;
	int	i = 0;
	int	j;
	int	side;

	while (i < size)
	{
		j = 0;
		while (j < size)
		{
			side = 0;
			while (side < 4)
			{
				param = find_aligned_param(i, j, side, size, params);
				nth_box = nth_box_from_param(i, j, side, size);
				side++;
				if (nth_box >= param)
					continue;
				if (theorem(param, nth_box, size) < arr[i][j])
					arr[i][j] = theorem(param, nth_box, size);
			}
			j++;
		}
		i++;
	}
	return (arr);
}

int	theorem(int param, int nth_box, int v_max)
{
	return(v_max - (param - nth_box));
}

int	find_aligned_param(int line, int column, int side, int size, int *params)
{
	if (side == 0)
		return(params[column]);
	if (side == 1)
		return(params[size + line]);
	if (side == 2)
		return(params[2 * size + (size - column - 1)]);
	return(params[3 * size + (size - line - 1)]);
}

int	nth_box_from_param(int line, int column, int side, int size)
{
	if (side == 0)
		return (line + 1);
	if (side == 1)
		return (size - column);
	if (side == 2)
		return (size - line);
	return (column + 1);
}

int	main(int argc, char **argv) // Input values in clockwise order, starting from the top
{
	int	**arr;
	int	*params;
	int	size;

	if (argc != 2 || param_verif(argv[1]))
	{
		printf("Error : arguments\n");
		return (1);
	}
	size = (my_strlen(argv[1]) + 1) / 8;
	params = char_arr_to_int_arr(argv[1], size);
	if (params == NULL)
	{
		putstr("Error : memory allocation\n");
		return (1);
	}
	arr = malloc_arr(size);
	if (arr == NULL)
	{
		putstr("Error : memory allocation\n");
		free(params);
		return (1);
	}
	arr = fill_max_arr(arr, size);
	arr = apply_theorem(arr, size, params);
	print_arr(arr, size);
	free(params);
	free_arr_int(arr, size);
	return (0);
}
