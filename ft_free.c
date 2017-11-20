/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gnegri <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/16 15:32:22 by gnegri            #+#    #+#             */
/*   Updated: 2017/11/20 20:10:40 by bmuselet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"
#include "libft/libft.h"

void	ft_free_tab(char **tab_tetris, int size_grid)
{
	int i;

	i = 0;
	while (i < size_grid)
	{
		ft_strdel(&tab_tetris[i]);
		i++;
	}
	ft_strdel(tab_tetris);
}
