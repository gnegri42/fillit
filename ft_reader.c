/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_reader.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmuselet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/15 17:00:51 by bmuselet          #+#    #+#             */
/*   Updated: 2017/11/16 10:49:23 by bmuselet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"
#include "libft/libft.h"

static int	ft_total_size_list(t_tetris *begin_list)
{
	int			size;
	int			i;

	size = 0;
	while (begin_list != NULL)
	{
		i = 0;
		while (begin_list->data[i] != '\0')
			i++;
		size = size + i;
		begin_list = begin_list->next;
	}
	return (size);
}

static char		*ft_concat_list(t_tetris *begin_list)
{
	int			i;
	int			j;
	char		*str;

	if ((str = (char *)malloc(sizeof(char) * (ft_total_size_list(begin_list) + 1))) == NULL)
		return (NULL);
	i = 0;
	while (begin_list != NULL)
	{
		j = 0;
		while (begin_list->data[j] != '\0')
		{
			str[i] = begin_list->data[j];
			j++;
			i++;
		}
		begin_list = begin_list->next;
	}
	str[i] = '\0';
	return (str);
}

static void	ft_list_push_back(t_tetris **begin_list, char *data)
{
	t_tetris	*new_elem;
	t_tetris	*tmp;

	if ((new_elem = ft_create_elem(data)) == NULL)
	{
		*begin_list = NULL;
		return ;
	}
	if (*begin_list)
	{
		tmp = *begin_list;
		while (tmp->next)
			tmp = tmp->next;
		tmp->next = new_elem;
	}
	else
		*begin_list = new_elem;
}

static t_tetris	*input_to_list(int fd)
{
	int			ret;
	char		buf[BUF_SIZE + 1];
	t_tetris	*begin_list;
	char		*dup;

	begin_list = NULL;
	while ((ret = read(fd, buf, BUF_SIZE)) > 0)
	{
		buf[ret] = '\0';
		if ((dup = ft_strdup(buf)) == NULL)
			return (NULL);
		ft_list_push_back(&begin_list, dup);
		if (begin_list == NULL)
			return (NULL);
	}
	return (begin_list);
}

char	*ft_reader(char *av)
{
	t_tetris	*begin_list;
	t_tetris	*tmp;
	char		*str;
	int			fd;

	fd = open(av, O_RDONLY);
	if ((begin_list = input_to_list(fd)) == NULL || BUF_SIZE < 1 ||
			(str = ft_concat_list(begin_list)) == NULL)
		return (0);
	tmp = begin_list;
	while (tmp != NULL)
	{
		begin_list = begin_list->next;
		free(tmp);
		tmp = begin_list;
	}
	return (str);
}
