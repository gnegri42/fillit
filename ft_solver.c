/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_solver.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gnegri <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/16 15:46:15 by gnegri            #+#    #+#             */
/*   Updated: 2017/11/17 16:25:50 by bmuselet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"
#include "libft/libft.h"
#include <stdio.h>


char	**ft_put_in_grid(t_tetrim *begin_list, char **solved_grid)
{
	int			i;
	int			j;

	i = 0;
	j = 0;
	while (i < 4)
	{
		while (j < 4)
		{
			if (ft_isalpha(begin_list->tetrim[i][j]) != 0)
				solved_grid[i][j] = begin_list->letter;
			j++;
		}
		i++;
		j = 0;
	}
	return (solved_grid);
}

char	**ft_solver(t_tetrim *begin_list, int num_tetris)
{
	char	**solved_grid;
	int		i;
	
	i = 0;
	solved_grid = ft_solver_tools(num_tetris);
	solved_grid = ft_put_in_grid(begin_list, solved_grid);
	while (i < 6)
	{
		printf("%s\n", solved_grid[i]);
		i++;
	}
	return (solved_grid);
	/*placement
	si ca marche pas avec valeur erreur reset
	solved_grid renvoie si ok
	free grid*/
}
