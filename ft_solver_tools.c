/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_solver_tools.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmuselet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/17 11:28:01 by bmuselet          #+#    #+#             */
/*   Updated: 2017/11/17 11:50:18 by bmuselet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"
#include "libft/libft.h"

char	*ft_create_grid(int size_square)
{
	int		i;
	char	*grid;

	i = 0;
	grid = ft_memalloc(sizeof(char) * (size_square + 1));
	if (grid == NULL)
		return (NULL);
	while (i < size_square)
	{
		grid[i] = '.';
		i++;
	}
	grid[i] = '\0';
	return (grid);
}

int		ft_sqrt(int nb)
{
	int i;

	i = 1;
	if (nb <= 0)
		return (0);
	while ((i * i) < nb)
		i++;
	if ((i * i) > nb)
		return (0);
	return (i);
}

int		ft_solver_tools(int num_tetris)
{
	int	min_square;

	min_square = ft_sqrt(num_tetris * 4);
	ft_putstr(ft_create_grid(min_square));
	return (0);
}


