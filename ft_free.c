/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gnegri <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/16 15:32:22 by gnegri            #+#    #+#             */
/*   Updated: 2017/11/16 15:32:23 by gnegri           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"
#include "libft/libft.h"

void	ft_free_tab(char **tab_tetris)
{
	int i;
	//int	j;

	i = 2;
	//j = 0;
	//while (tab_tetris[j++] != NULL)
	while (tab_tetris[i] != '\0')
		ft_strdel(&tab_tetris[i++]);
	ft_strdel(&tab_tetris[i]);
}
