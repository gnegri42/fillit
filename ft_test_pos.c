/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_test_pos.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gnegri <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/17 16:39:49 by gnegri            #+#    #+#             */
/*   Updated: 2017/11/20 20:12:41 by bmuselet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"
#include "libft/libft.h"

int		ft_test_pos(char **solved_grid, t_tetrim *begin_list, int size_grid)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (i < 4)
	{
		while (j < 4)
		{
			if (begin_list->tetrim[i][j] == '#' \
					&& (begin_list->x + j >= size_grid \
					|| begin_list->y + i >= size_grid))
				return (0);
			if (begin_list->tetrim[i][j] == '#' && \
					ft_isalpha(solved_grid[begin_list->y + i]\
						[begin_list->x + j]) == 1)
				return (0);
			j++;
		}
		j = 0;
		i++;
	}
	return (1);
}
