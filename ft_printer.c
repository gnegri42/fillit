/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printer.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gnegri <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/17 17:48:34 by gnegri            #+#    #+#             */
/*   Updated: 2017/11/17 17:48:41 by gnegri           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"
#include "libft/libft.h"

void	ft_print_result(char **solved_grid)
{
	int i;

	while (solved_grid[i] != NULL)
	{
		ft_putstr(solved_grid[i]);
		i++;
	}
}
