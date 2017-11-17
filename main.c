/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmuselet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/15 12:06:06 by bmuselet          #+#    #+#             */
/*   Updated: 2017/11/17 11:32:24 by bmuselet         ###   ########.fr       */
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
	char 		**tab_tetris;
	int 		i;
	t_tetris	*first;
	t_tetris	*tmp;
	char		*grid_solved;

	i = 0;
	if (ac != 2)
	{
		ft_putstr("usage : fillit target_file\n");
		return (0);
	}
	tab_tetris = ft_reader(av[1]);
	if ((ft_checker(tab_tetris)) == 0)
		ft_putstr("error");
	first = ft_create_list(tab_tetris);
//	ft_free_tab(tab_tetris);
	ft_move_tetris(first);
	tmp = first;
	while (first != NULL)
	{
		ft_to_letter(first);
		//printf("%s\n", first->tetris);
		//printf("\n");
		first = first->next;
	}
	first = tmp;
	i = ft_tetris_nb(first);
	//printf("%d", i);
	grid_solved = ft_solver(first, ft_tetris_nb(first));
	return (0);
}
