/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_move_tetris.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gnegri <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/16 16:49:43 by gnegri            #+#    #+#             */
/*   Updated: 2017/11/16 16:49:45 by gnegri           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"
#include "libft/libft.h"
#include <stdio.h>
char	*ft_move_up(char *str)
{
	int i;
	int decal;

	i = 0;
	decal = 0;
	if (str == NULL)
		return (0);
	while (str[i] != '\0')
	{
		if (str[i] == '#')
		{
			decal = i / 5;
			//printf("%d\n", decal);
			i = 20;
		}
		i++;
	}
	i = 0;
	while (str[i] != '\0' && decal > 0)
	{
		if (str[i] == '#')
		{
			str[i - 5] = str[i];
			str[i] = '.';
		}
		i++;
	}
	return (str);
}

char	*ft_move_left(char *str)
{
	int i;
	int decal;

	i = 0;
	decal = 0;
	if (str == NULL)
		return (0);
	while (i < 3)
	{
		if (str[i] == '#' || str[i + 5] == '#' || str[i + (5 * 2)] == '#' 
			|| str[i + (5 * 3)] == '#')
			i = 3;
		else
			decal++;
		i++;
	}
	i = 0;
	while (str[i] != '\0' && decal > 0)
	{
		printf("%d\n", decal);
		if (str[i] == '#')
		{
			str[i - decal] = str[i];
			str[i] = '.';
		}
		i++;
	}
	return (str);
}

void		ft_move_tetris(t_tetris *first)
{
	t_tetris	*ptr;
	
	ptr = first;
	while (ptr)
	{
		ptr->tetris = ft_move_left(ptr->tetris);
		ptr->tetris = ft_move_up(ptr->tetris);
		ptr = ptr->next;
	}
	//return (first);
}
