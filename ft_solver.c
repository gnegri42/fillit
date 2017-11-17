/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_solver.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gnegri <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/16 15:46:15 by gnegri            #+#    #+#             */
/*   Updated: 2017/11/16 15:46:16 by gnegri           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"
#include "libft/libft.h"

char	*ft_put_in_grid(t_tetris *tetris, char *solved_grid)
{
	int			i;
	int			c;
	t_tetris	*piece;
	char		*str;

	i = 0;
	c = 0;
	piece = tetris;
	str = piece->tetris;
	while (solved_grid[c] != '\n')
		c++;
/*	if (ft_check_tetris() == 0)
	{
		*/
		while (str[i] != '\0')
		{
			if (str[i] != '.' && str[i] != '\n' && str[i] != '\0')
			{
				if (i == 0 && str[i] != '.' && str[i] != '\n' && str[i] != '\0')
				{
					solved_grid[i] = str[i];
					str[i] = piece->letter;
					i++;
				}
				else
				{
					str[i] = solved_grid[i + (c - 4)];
					str[i] = piece->letter;
				}
			}
			ft_putchar(str[i]);
			i++;
		}
//	}
	return (solved_grid);
}

char	*ft_solver(t_tetris *tetris, int num_tetris)
{
	char	*solved_grid;

	if (!tetris)
		return (0);
	solved_grid = ft_solver_tools(num_tetris);
	solved_grid = ft_put_in_grid(tetris, solved_grid);
	ft_putchar('\n');
	ft_putchar('\n');
	ft_putstr(solved_grid);

	return (solved_grid);
	/*premiere piece en haut a gquche
	placement
	si ca marche pas avec valeur erreur reset
	solved_grid renvoie si ok
	free grid*/
}