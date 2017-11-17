/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmuselet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/15 12:11:56 by bmuselet          #+#    #+#             */
/*   Updated: 2017/11/17 18:50:32 by bmuselet         ###   ########.fr       */
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
	char				*tetris;
	char				letter;
	int					x;
	int					y;
	struct s_tetris 	*next;
}						t_tetris;

typedef struct			s_tetrim
{
	char				**tetrim;
	char				letter;
	int					x;
	int					y;
	struct s_tetrim 	*next;
}						t_tetrim;

char		**ft_reader(char *av);
int			ft_checker(char **tab_tetris);
t_tetris	*ft_create_list(char **tab_tetris);
void		ft_free_tab(char **tab_tetris);
void		ft_move_tetris(t_tetris *list_tetris);
char		**ft_solver_tools(int num_tetris);
void		ft_to_letter(t_tetris *first);
char		**ft_solver(t_tetrim *begin_list, int num_tetris);
t_tetrim	*ft_create_list2(t_tetris first, int nb_tetris);
int			ft_sqrt(int nb);
int			ft_test_pos(char **solved_grid, t_tetrim *begin_list, int size_grid);
void		ft_print_result(char **solved_grid);

#endif
