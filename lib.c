#include "theorem.h"

int	**malloc_arr(int size)
{
	int	i = 0;
	int	**arr;

	arr = malloc(size * sizeof(int *));
	if (arr == NULL)
		return (NULL);
	while (i < size)
	{
		arr[i] = malloc(size * sizeof(int));
		if (arr[i] == NULL)
		{
			free_arr_int(arr, size);
			return (NULL);
		}
		i++;
	}
	return (arr);
}

int	my_strlen(char *str)
{
	int	i = 0;

	while (str[i])
		i++;
	return (i);
}

int	**fill_max_arr(int **arr, int size)
{
	int	i = 0;
	int	j;

	while (i < size)
	{
		j = 0;
		while (j < size)
		{
			arr[i][j] = size;
			j++;
		}
		i++;
	}
	return (arr);
}

void	free_arr_int(int **arr, int size)
{
	int	i = 0;

	while (i < size && arr[i] != NULL)
	{
		free(arr[i]);
		i++;
	}
	free(arr);
}

void	print_arr(int **arr, int size)
{
	int	i = 0;
	int	j;
	char	n;

	while (i < size)
	{
		j = 0;
		while (j < size)
		{
			n = arr[i][j] + 48;
			write(1, &n, 1);
			if (j != (size - 1))
				write(1, " ", 1);
			j++;
		}
		write(1, "\n", 1);
		i++;
	}
}

void	putstr(char *str)
{
	int	i = 0;

	while (str[i])
	{
		write(1, &str[i], 1);
		i++;
	}
}
