/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmuselet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/15 12:06:06 by bmuselet          #+#    #+#             */
/*   Updated: 2017/11/20 20:08:32 by bmuselet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"
#include "libft/libft.h"
#include <stdio.h>

int		ft_tetris_nb(t_tetris *first)
{
	int	i;

	i = 0;
	while (first != NULL)
	{
		first = first->next;
		i++;
	}
	return (i - 1);
}

int		main(int ac, char **av)
{
	char		**tab_tetris;
	t_tetris	*first;
	t_tetris	*tmp;
	char		**solved_grid;
	t_tetrim	*begin_list;

	if (ac != 2)
	{
		ft_putstr("usage : fillit target_file\n");
		return (0);
	}
	tab_tetris = ft_reader(av[1]);
	if ((ft_checker(tab_tetris)) == 0)
	{
		ft_putstr("error");
		return (0);
	}
	first = ft_create_list(tab_tetris);
	ft_move_tetris(first);
	tmp = first;
	begin_list = ft_create_list2(*first, ft_tetris_nb(first));
	solved_grid = ft_solver(begin_list, ft_tetris_nb(first));
	ft_print_result(solved_grid);
	return (0);
}
