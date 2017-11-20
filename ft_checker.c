/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_checker.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmuselet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/15 17:17:07 by bmuselet          #+#    #+#             */
/*   Updated: 2017/11/20 20:09:31 by bmuselet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"
#include "libft/libft.h"

static int	ft_check_shape(char *str)
{
	int i;
	int j;
	int c;

	i = 0;
	j = 0;
	c = 0;
	while (str[i] != '\0')
	{
		if (str[i] == '#')
		{
			c++;
			if (c == 2)
			{
				j = i + 1;
				while (str[j] != '#' && str[j] != '\0')
				{
					if (j > (i + 5))
						return (0);
					j++;
				}
			}
			if (str[i + 1] != '#' && str[i - 1] != '#'
				&& str[i + 5] != '#' && str[i - 5] != '#')
				return (0);
		}
		i++;
	}
	return (1);
}

static int	ft_check_line(char *str)
{
	int i;
	int a;
	int val;

	i = 0;
	a = 0;
	val = 4;
	while (str[i] != '\0')
	{
		if (str[i] == '.' || str[i] == '#')
			a++;
		if (a > 4)
			return (0);
		if (i == val && str[i] == '\n')
		{
			a = 0;
			val = (val + 5);
		}
		i++;
	}
	return (1);
}

static int	ft_check_char(char *str)
{
	int	i;
	int	hashtag;
	int back_n;
	int	point;

	i = 0;
	hashtag = 0;
	back_n = 0;
	point = 0;
	while (str[i] != '\0')
	{
		if (str[i] == '.')
			point++;
		if (str[i] == '\n')
			back_n++;
		if (str[i] == '#')
			hashtag++;
		if (str[i] != '#' && str[i] != '.' && str[i] != '\n')
			return (0);
		i++;
	}
	if (i != 20 && point != 12 && hashtag != 4 && back_n != 4)
		return (0);
	return (1);
}

int			ft_checker(char **tab_tetris)
{
	int	i;
	int j;
	int num_tetris;

	i = 0;
	j = 0;
	num_tetris = 0;
	if (tab_tetris[0] == NULL)
		return (0);
	while (tab_tetris[j++] != NULL)
		num_tetris++;
	num_tetris = num_tetris - 1;
	while (i <= num_tetris)
	{
		if (ft_check_char(tab_tetris[i]) != 1)
			return (0);
		if (ft_check_line(tab_tetris[i]) != 1)
			return (0);
		if (ft_check_shape(tab_tetris[i]) != 1)
			return (0);
		i++;
	}
	return (1);
}
