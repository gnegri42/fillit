/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_solver_tools.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmuselet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/17 11:28:01 by bmuselet          #+#    #+#             */
/*   Updated: 2017/11/20 20:12:34 by bmuselet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"
#include "libft/libft.h"

char	**ft_create_grid(char **grid, int size_grid)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	grid = ft_memalloc(sizeof(char *) * size_grid + 1);
	while (i < size_grid)
	{
		grid[i] = ft_memalloc(sizeof(char) * size_grid + 1);
		i++;
	}
	i = 0;
	while (j < size_grid)
	{
		while (i < size_grid)
		{
			grid[j][i++] = '.';
		}
		grid[j][i] = '\0';
		i = 0;
		j++;
	}
	grid[j] = NULL;
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
