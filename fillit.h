/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekantane <ekantane@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/17 17:28:36 by ycucchi           #+#    #+#             */
/*   Updated: 2022/03/09 11:45:29 by ycucchi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef FILLIT_H
# define FILLIT_H
# include <string.h>
# include "libft/libft.h"
# include <stdlib.h>
# include <sys/stat.h>
# include <stdio.h> // need to be removed before submit
# include <fcntl.h>

typedef struct		s_tetris
{
	void			*tet_id;
	char			c;
	struct s_tetris	*next;
}					t_tetris;

# define I_PIECE (int [8]) {0,0,1,0,2,0,3,0}
# define IH_PIECE (int [8]) {0,0,0,1,0,2,0,3}
# define O_PIECE (int [8]) {0,0,0,1,1,0,1,1}
# define L_PIECE (int [8]) {0,0,1,0,2,0,2,1}
# define LR_PIECE (int [8]) {0,0,0,1,0,2,1,0}
# define LD_PIECE (int [8]) {0,0,0,1,1,1,2,1}
# define LL_PIECE (int [8]) {0,2,1,0,1,1,1,2}
# define J_PIECE (int [8]) {0,1,1,1,2,0,2,1}
# define JR_PIECE (int [8]) {0,0,1,0,1,1,1,2}
# define JD_PIECE (int [8]) {0,0,0,1,1,0,2,0}
# define JL_PIECE (int [8]) {0,0,0,1,0,2,1,2}
# define T_PIECE (int [8]) {0,0,0,1,0,2,1,1}
# define TR_PIECE (int [8]) {0,1,1,0,1,1,2,1}
# define TD_PIECE (int [8]) {0,1,1,0,1,1,1,2}
# define TL_PIECE (int [8]) {0,0,1,0,1,1,2,0}
# define S_PIECE (int [8]) {0,1,0,2,1,0,1,1}
# define SR_PIECE (int [8]) {0,0,1,0,1,1,2,1}
# define Z_PIECE (int [8]) {0,0,0,1,1,1,1,2}
# define ZR_PIECE (int [8]) {0,1,1,0,1,1,2,0}

int			check_grid(char **grid, int grid_count, int i);
int			*print_tet(int *tet, int grid_count);
int			error_check(char** grid, int count_hash, int i, int x, int y);
char		*get_tetid(int *tet);
int			*trans_coord(int *tet, int grid_count);
int			dup_coord(int *dst, int *src);
int			low_x(int *tet, int grid_count);
int			low_y(int *tet);
int			tetcmp(int *tet, int *arr, int n);
t_tetris	*store_tet(int *tet, int grid_count);
t_tetris	*append(void *tet_id, t_tetris *head, char c);
t_tetris	*add_piece(void *tet_id, char c);
int			*convert_id(char *id);
void		ft_exit(void);
int			top_x(int *tet);
int			top_y(int *tet);
int			box_collision(int *tet, int size);
int			piece_collision(char **grid, int *tet, int size);
int			collision(char **grid, int *tet, int size);
char		contain_grid(char **grid);
int			preread(char **argv);
int			solve_tet(char **grid, t_tetris *stack, int size);
int			stack_tet(t_tetris *stack);
int			*x_shift(int *tet, int x);
int			*y_shift(int *tet, int y);
int			*shift_tet(int *tet, int x, int y);
void		print_grid(char **grid, int *tet, int size);
void		insert_piece(char **grid, int *tet, char c);
t_tetris	*id_to_coord(t_tetris *stack);
void		clear_piece(char **grid, int *tet);
int		help_solve(char **grid, int *tet, t_tetris *stack, int size);
char	*gen_line(int col);
int		start_size(t_tetris *stack);
char	**gen_grid(int size);
int			count_tet(t_tetris *stack);

void	stck_free(t_tetris *stack);
void	stck_free_coord(t_tetris *stack);
void	free_grid(char **grid, int size);
t_tetris	*store_first(int *tet, int grid_count);

#endif
