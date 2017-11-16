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
	int	j;

	i = 0;
	j = 0;
	while (tab_tetris[j++] != NULL)
	while (i < j)
		ft_strdel(&tab_tetris[i++]);
	ft_strdel(&tab_tetris[i]);
}
