/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_solver.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gnegri <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/16 15:46:15 by gnegri            #+#    #+#             */
/*   Updated: 2017/11/20 20:12:26 by bmuselet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"
#include "libft/libft.h"

static char	**ft_backtrack(t_tetrim *begin_list, char **solved_grid)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (solved_grid[i] != NULL)
	{
		while (solved_grid[i][j] != '\0')
		{
			if (solved_grid[i][j] == begin_list->letter)
				solved_grid[i][j] = '.';
			j++;
		}
		j = 0;
		i++;
	}
	return (solved_grid);
}

static char	**ft_put_in_grid(t_tetrim *begin_list, char **solved_grid)
{
	int			i;
	int			j;

	i = 0;
	j = 0;
	while (i < 4)
	{
		while (j < 4)
		{
			if (begin_list->tetrim[i][j] == '#')
				solved_grid[begin_list->y + i]\
					[begin_list->x + j] = begin_list->letter;
			j++;
		}
		i++;
		j = 0;
	}
	return (solved_grid);
}

static int	ft_search(t_tetrim *begin_list, int size_grid, char **solved_grid)
{
	if (begin_list != NULL)
	{
		while ((begin_list->x * begin_list->y) < (size_grid * size_grid))
		{
			if (ft_test_pos(solved_grid, begin_list, size_grid) == 1)
			{
				solved_grid = ft_put_in_grid(begin_list, solved_grid);
				if (ft_search(begin_list->next, size_grid, solved_grid) == 1)
					return (1);
				solved_grid = ft_backtrack(begin_list, solved_grid);
			}
			if (begin_list->x < size_grid)
				begin_list->x++;
			else
			{
				begin_list->x = 0;
				begin_list->y++;
			}
		}
		begin_list->x = 0;
		begin_list->y = 0;
		return (0);
	}
	return (1);
}

char		**ft_solver(t_tetrim *begin_list, int num_tetris)
{
	char	**solved_grid;
	int		size_grid;
	int		i;

	i = 0;
	solved_grid = NULL;
	size_grid = ft_sqrt(num_tetris * 4);
	solved_grid = ft_create_grid(solved_grid, size_grid);
	while (ft_search(begin_list, size_grid, solved_grid) == 0)
	{
		size_grid++;
		ft_free_tab(solved_grid, size_grid);
		begin_list->x = 0;
		begin_list->y = 0;
		solved_grid = ft_create_grid(solved_grid, size_grid);
	}
	return (solved_grid);
}
