/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_reader.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmuselet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/15 17:00:51 by bmuselet          #+#    #+#             */
/*   Updated: 2017/11/15 17:00:59 by bmuselet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"
#include "libft/libft.h"

char	*ft_reader(char *av)
{
	char		*str;
	int			fd;
	int 		len;
	char		buf[BUF_SIZE + 1];

	len = 0;
	fd = open(av, O_RDONLY);
	len = read(fd, buf, BUF_SIZE);
	buf[len] = '\0';
	str = (char *)malloc(sizeof(char) * len);
	memcpy(str, buf, len);
	close(fd);
	return (str);
}
