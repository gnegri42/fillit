/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_solver_tools.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmuselet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/17 11:28:01 by bmuselet          #+#    #+#             */
/*   Updated: 2017/11/17 16:13:58 by bmuselet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"
#include "libft/libft.h"

char	**ft_split_grid(char *grid)
{
	char **real_grid;

	real_grid = ft_strsplit(grid, '\n');
	return (real_grid);
}

char	*ft_create_grid(int size_square)
{
	int		i;
	char	*grid;

	i = 0;
	grid = ft_memalloc(sizeof(char) * ((size_square * size_square)
		+ size_square + 1));
	if (grid == NULL)
		return (NULL);
	while (i < (size_square * size_square + size_square))
	{
		if (i % (size_square + 1) == 0)
		{
			grid[i] = '\n';
			i++;
		}
		grid[i] = '.';
		i++;
	}
	grid[i] = '\0';
	return (grid);
}

int		ft_sqrt(int nb)
{
	int		i;

	i = 1;
	if (nb <= 0)
		return (0);
	while ((i * i) < nb)
		i++;
	return (i);
}

char	**ft_solver_tools(int num_tetris)
{
	int		min_square;
	char	**grid;

	min_square = ft_sqrt(num_tetris * 4);
	grid = ft_split_grid(ft_create_grid(min_square));
	return (grid);
}
