/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmuselet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/15 12:06:06 by bmuselet          #+#    #+#             */
/*   Updated: 2017/11/22 11:40:44 by bmuselet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"
#include "libft/libft.h"

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
	char		**solved_grid;
	t_tetrim	*begin_list;
	char		*str;

	if (ac != 2)
	{
		ft_putstr("usage: fillit source_file\n");
		return (0);
	}
	str = ft_reader(av[1]);
	tab_tetris = ft_create_tab(str);
	if (tab_tetris == NULL || (ft_checker(tab_tetris)) == 0)
	{
		ft_putstr("error\n");
		return (0);
	}
	first = ft_create_list(tab_tetris);
	ft_move_tetris(first);
	begin_list = ft_create_list2(*first, ft_tetris_nb(first));
	solved_grid = ft_solver(begin_list, ft_tetris_nb(first));
	ft_print_result(solved_grid);
	return (0);
}
