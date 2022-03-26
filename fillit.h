/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekantane <ekantane@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/17 17:28:36 by ycucchi           #+#    #+#             */
/*   Updated: 2022/03/24 11:36:37 by ycucchi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H

/*
**	Headers
*/

# include "libft/libft.h"
# include <string.h>
# include <stdlib.h>
# include <sys/stat.h>
# include <time.h> // need to be removed before submit
# include <stdio.h> // need to be removed before submit
# include <fcntl.h>

/*
**	Structs
*/

typedef struct s_tetris
{
	void			*tet_id;
	char			c;
	struct s_tetris	*next;
}				t_tetris;

typedef struct s_piece
{
	char		name[20];
	int			coord[8];
}				t_piece;

/*
**	Pieces
*/

t_piece		i_piece(void);
t_piece		ih_piece(void);
t_piece		o_piece(void);
t_piece		l_piece(void);
t_piece		lr_piece(void);
t_piece		ld_piece(void);
t_piece		ll_piece(void);
t_piece		j_piece(void);
t_piece		jr_piece(void);
t_piece		jd_piece(void);
t_piece		jl_piece(void);
t_piece		tt_piece(void);
t_piece		tr_piece(void);
t_piece		td_piece(void);
t_piece		tl_piece(void);
t_piece		ss_piece(void);
t_piece		sr_piece(void);
t_piece		z_piece(void);
t_piece		zr_piece(void);

/*
**	solver.c
*/

int			solve_tet(char **grid, t_tetris *stack, int size);
int			*x_shift(int *tet, int x);
int			*y_shift(int *tet, int y);
int			*shift_tet(int *tet, int x, int y);

/*
**	grid.c
*/

int			count_tet(t_tetris *stack);
int			start_size(t_tetris *stack);
char		*gen_line(int col);
char		**gen_grid(int size);

/*
**	grid.utils
*/

void		insert_piece(char **grid, int *tet, char c);
void		clear_piece(char **grid, int *tet);
void		print_grid(char **grid, int size);

/*
**	free.c
*/

void		stck_free(t_tetris *stack);
void		stck_free_coord(t_tetris *stack);
void		free_grid(char **grid, int size);

/*
**	check_grid.c
*/

int			read_one(const int fd, char *line);
int			h_count(char *line);
int			chk_char(char *line);
t_tetris	*id_to_coord(t_tetris *stack);
int			dup_coord(int *dst, int *src);

/*
**	stack.c
*/

t_tetris	*add_piece(void *tet_id, char c);
t_tetris	*append(void *tet_id, t_tetris *head, char c);
t_tetris	*store_tet(const int fd, char *line);
int			*one_tetris(const int fd, char *line);

/*
**	coord_swap.c
*/

int			*trans_coord(int *tet);
int			smallest_x(int *tet);
int			smallest_y(int *tet);

/*
**	identification.c
*/

char		*check_tet(int *tet);
int			tetcmp(int *tet, int *libtet);
int			*convert_id(char *id);

/*
**	initialization.c
*/

char		*get_tetid_io(int *tet, char *name);
char		*get_tetid_l(int *tet, char *name);
char		*get_tetid_j(int *tet, char *name);
char		*get_tetid_tt(int *tet, char *name);
char		*get_tetid_sz(int *tet, char *name);

/*
**	collision.c
*/

int			biggest_x(int *tet);
int			biggest_y(int *tet);
int			box_collision(int *tet, int size);
int			piece_collision(char **grid, int *tet);
int			collision(char **grid, int *tet, int size);

/*
**	main.c
*/

int			solve_driver(int fd);
int			help_solve(char **grid, int *tet, t_tetris *stack, int size);
int			preread(const int fd);
void		ft_exit(void);

#endif