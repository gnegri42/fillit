/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_create_list.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gnegri <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/16 15:46:44 by gnegri            #+#    #+#             */
/*   Updated: 2017/11/16 15:46:53 by gnegri           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

t_tetris	*ft_new_list(char *str, int num_tetris)
{
	t_tetris	*new_elem;

	new_elem = NULL;
	new_elem = (t_tetris*)malloc(sizeof(t_tetris));
	if ((new_elem) == NULL)
		return (NULL);
	if (new_elem)
	{
		new_elem->tetris = str;
		new_elem->letter = 'A' + num_tetris;
		new_elem->x = 0;
		new_elem->y = 0;
		new_elem->next = NULL;
	}
	return (new_elem);
}

t_tetris	*ft_create_list(char **tab_tetris)
{
	int			i;
	int			num_tetris;
	t_tetris	*first;
	t_tetris	*ptr;

	i = 0;
	ptr = NULL;
	first = NULL;
	num_tetris = 0;
	while(tab_tetris[i++] != NULL)
		num_tetris++;
	i = 0;
	first = ft_new_list(tab_tetris[0], i);
	ptr = first;
	while (num_tetris > i)
	{
		i++;
		ptr->next = ft_new_list(tab_tetris[i], i);
		ptr = ptr->next;
	}
	ptr->next = NULL;
	return (first);
}
