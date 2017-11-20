/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_reader.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmuselet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/15 17:00:51 by bmuselet          #+#    #+#             */
/*   Updated: 2017/11/20 20:11:49 by bmuselet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"
#include "libft/libft.h"

static char	**ft_fill_tab(char **tab_tetris, int num_tetris, char *str)
{
	int			i;
	int			j;
	int			k;

	i = 0;
	j = 0;
	k = 0;
	while (j < num_tetris)
	{
		tab_tetris[j] = (char *)malloc(sizeof(char) * 21);
		if (tab_tetris[j] == NULL)
			return (0);
		while (k < 19)
		{
			tab_tetris[j][k] = str[i];
			k++;
			i++;
		}
		i++;
		tab_tetris[j][k] = '\0';
		i++;
		j++;
		k = 0;
	}
	tab_tetris[j] = NULL;
	return (tab_tetris);
}

static int	ft_count_tetris(char *str)
{
	int			i;
	int			num_tetris;

	i = 0;
	num_tetris = 0;
	while (str[i] != '\0')
	{
		if ((str[i] == '\n' && str[i + 1] == '\n') || (str[i + 1] == '\0'))
			num_tetris++;
		i++;
	}
	return (num_tetris);
}

static char	**ft_create_tab(char *str)
{
	int			num_tetris;
	char		**tab_tetris;

	num_tetris = ft_count_tetris(str);
	if (num_tetris == 0)
		return (0);
	tab_tetris = (char **)malloc(sizeof(char *) * (num_tetris + 1));
	if (tab_tetris == NULL)
		return (0);
	ft_fill_tab(tab_tetris, num_tetris, str);
	return (tab_tetris);
}

char		**ft_reader(char *av)
{
	char		*str;
	int			fd;
	int			len;
	char		buf[BUF_SIZE + 1];

	len = 0;
	fd = open(av, O_RDONLY);
	len = read(fd, buf, BUF_SIZE);
	buf[len] = '\0';
	str = (char *)malloc(sizeof(char) * len);
	if (str == NULL)
		return (0);
	memcpy(str, buf, len);
	close(fd);
	return (ft_create_tab(str));
}
