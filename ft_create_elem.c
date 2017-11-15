/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_create_elem.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmuselet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/15 15:20:50 by bmuselet          #+#    #+#             */
/*   Updated: 2017/11/15 15:27:34 by bmuselet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

t_tetris	*ft_create_elem(char *data)
{
	t_tetris	*new_elem;

	new_elem = NULL;
	new_elem = (t_tetris*)malloc(sizeof(t_tetris) * 1);
	if (new_elem)
	{
		new_elem->data = data;
		new_elem->next = NULL;
	}
	return (new_elem);
}
