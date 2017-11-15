/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmuselet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/15 12:11:56 by bmuselet          #+#    #+#             */
/*   Updated: 2017/11/15 15:26:57 by bmuselet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H

#include "libft/libft.h"
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

#define BUF_SIZE 21

typedef struct	s_tetris
{
	char *data;
	struct s_tetris *next;
}				t_tetris;

char		*ft_reader(char *av);
int			checker(char *str);
t_tetris	*ft_create_elem(char *data);

#endif
