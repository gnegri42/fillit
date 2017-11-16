/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_solver.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gnegri <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/16 15:46:15 by gnegri            #+#    #+#             */
/*   Updated: 2017/11/16 15:46:16 by gnegri           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


int		ft_sqrt(int nb)
{
	int i;

	i = 1;
	if (nb <= 0)
		return (0);
	while ((i * i) < nb)
		i++;
	if ((i * i) > nb)
		return (0);
	return (i);
}

int		ft_min_square(int num_tetris)
{
	int	min_square;

	min_square = ft_sqrt(num_tetris * 4);
	return (min_square);
}
