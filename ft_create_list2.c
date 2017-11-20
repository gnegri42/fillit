/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_create_list2.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmuselet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/17 15:07:42 by bmuselet          #+#    #+#             */
/*   Updated: 2017/11/20 20:10:20 by bmuselet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"
#include "libft/libft.h"

static t_tetrim	*ft_new_list2(char **str, int num_tetris)
{
	t_tetrim	*new_elem;

	new_elem = NULL;
	new_elem = (t_tetrim*)malloc(sizeof(t_tetrim));
	if ((new_elem) == NULL)
		return (NULL);
	new_elem->tetrim = str;
	new_elem->letter = 'A' + num_tetris;
	new_elem->x = 0;
	new_elem->y = 0;
	new_elem->next = NULL;
	return (new_elem);
}

t_tetrim		*ft_create_list2(t_tetris first, int nb_tetris)
{
	int			i;
	t_tetrim	*begin_list;
	t_tetrim	*tmp;

	i = 1;
	begin_list = NULL;
	tmp = NULL;
	begin_list = ft_new_list2(ft_strsplit(first.tetris, '\n'), 0);
	tmp = begin_list;
	while (i < nb_tetris)
	{
		first = *first.next;
		tmp->next = (ft_new_list2(ft_strsplit(first.tetris, '\n'), i));
		tmp = tmp->next;
		i++;
	}
	tmp->next = NULL;
	return (begin_list);
}
