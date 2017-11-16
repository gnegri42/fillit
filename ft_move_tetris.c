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

char	*ft_move_left(char	*str)
{

}

char	*ft_move_up(char *str)
{
	int i;
	int line;
	int col;

	i = 0;
	line = 0;
	while (str[i] != '\0')
	{
		while (line < 4)
		{
			col = 0;
			while (col < 4)
			{
				if (str[i] != '#' && str[i] != '\0')
				{
					col++;
					i++;
				}
				if (str[i] == '#')
				{
					
				}
			}
		}
	}
}

void		ft_move_tetris(t_tetris *first)
{
	t_tetris	*ptr;
	
	ptr = first;
	while (ptr)
	{
		ptr->tetris = ft_upleft(ptr->tetris);
		ptr = ptr->next;
	}
	//return (first);
}
