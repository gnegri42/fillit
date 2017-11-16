/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmuselet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/15 12:11:56 by bmuselet          #+#    #+#             */
/*   Updated: 2017/11/16 11:01:05 by bmuselet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H

#include "libft/libft.h"
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

#define BUF_SIZE 4096

typedef struct			s_tetris
{
	char				*tetrimino;
	char				letter;
	int					x;
	int					y;
	struct s_tetrimino	*next;
}						t_tetris;

char		**ft_reader(char *av);
int			ft_checker(char **tab_tetris);
//t_tetris	*ft_create_elem(char *data);

#endif
