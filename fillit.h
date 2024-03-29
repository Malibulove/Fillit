/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekantane <ekantane@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/17 17:28:36 by ycucchi           #+#    #+#             */
/*   Updated: 2022/04/07 16:42:57 by ekantane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H

/*
**	Headers
*/

# include "libft/libft.h"
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

/*
**	grid.c
*/

int			start_size(t_tetris *stack);
char		*gen_line(int col);
char		**gen_grid(int size);

/*
**	grid.utils
*/

void		insert_piece(char **grid, int *tet, char c);
void		clear_piece(char **grid, int *tet);
void		print_grid(char **grid);
int			dup_coord(int *dst, int *src);

/*
**	free.c
*/

void		stack_free(t_tetris *stack);
void		stack_free_coord(t_tetris *stack);
void		free_grid(char **grid, int size);

/*
**	check_grid.c
*/

int			one_grid(const int fd, char *line);
t_tetris	*id_to_coord(t_tetris *stack);
int			*convert_char_to_int(const int fd, char *line, int *tet);

/*
**	stack.c
*/

t_tetris	*add_piece(void *tet_id, char c);
t_tetris	*append(void *tet_id, t_tetris *head, char c);
t_tetris	*store_tet(const int fd, char *line);

/*
**	coord_swap.c
*/

int			*trans_coord(int *tet);

/*
**	identification.c
*/

char		*check_tet(int *tet);
int			tetcmp(int *tet, int *libtet);
int			*char_to_int_id(char *id);

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

int			collision(char **grid, int *tet, int size);

/*
**	main.c
*/

int			error_line(char *line);
int			error_handling(void);
#endif