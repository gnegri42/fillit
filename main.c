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
int	main(int ac, char **av)
{
	char 		**tab_tetris;
	int 		i;
	t_tetris	*first;

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
	while (first != NULL)
	{
		printf("%s\n", first->tetris);
		printf("\n");
		first = first->next;
	}
	ft_solver_tools(5);
//	while (i < 5)
//		printf("%s\n", tab_tetris[i++]);
	return (0);
}
