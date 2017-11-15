/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmuselet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/15 12:06:06 by bmuselet          #+#    #+#             */
/*   Updated: 2017/11/15 14:54:21 by bmuselet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"
#include "libft/libft.h"

int	main(int ac, char **av)
{
	char *str;

	if (ac != 2)
	{
		ft_putstr("usage : fillit target_file\n");
		return (0);
	}
	str = reader(av[1]);
	checker(str);
	return (0);
}
