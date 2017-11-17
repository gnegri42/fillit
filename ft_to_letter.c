/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_to_letter.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gnegri <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/17 12:39:52 by gnegri            #+#    #+#             */
/*   Updated: 2017/11/17 12:39:55 by gnegri           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void	ft_to_letter(t_tetris *first)
{
	int 	i;
	char	*str;

	i = 0;
	if (first->tetris != NULL)
	{	
		str = first->tetris;
		while(str[i] != '\0')
		{
			if (str[i] == '#')
				str[i] = first->letter;
			i++;
		}
		first->tetris = str;
	}
}
