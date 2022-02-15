/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekantane <ekantane@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/03 10:18:37 by ekantane          #+#    #+#             */
/*   Updated: 2022/02/15 17:55:21 by ycucchi          ###   ########.fr       */
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

# define I_PIECE (int [8]) {0,0,0,1,0,2,0,3}
# define IH_PIECE (int [8]) {0,0,1,0,2,0,3,0}
# define O_PIECE (int [8]) {0,0,1,0,0,1,1,1}
# define L_PIECE (int [8]) {0,0,0,1,0,2,1,2}
# define LR_PIECE (int [8]) {0,0,1,0,2,0,0,1}
# define LD_PIECE (int [8]) {0,0,1,0,1,1,1,2}
# define LL_PIECE (int [8]) {2,0,0,1,1,1,2,1}
# define J_PIECE (int [8]) {1,0,1,1,0,2,1,2}
# define JR_PIECE (int [8]) {0,0,0,1,1,1,2,1}
# define JD_PIECE (int [8]) {0,0,1,0,0,1,0,2}
# define JL_PIECE  (int [8]) {0,0,1,0,2,0,2,1}
# define T_PIECE (int [8]) {1,0,0,1,1,1,2,1}
# define TR_PIECE (int [8]) {0,0,0,1,1,1,0,2}
# define TD_PIECE (int [8]) {0,0,1,0,2,0,1,1}
# define TL_PIECE (int [8]) {1,0,0,1,1,1,1,2}
# define S_PIECE (int [8]) {1,0,2,0,0,1,1,1}
# define SR_PIECE (int [8]) {0,0,0,1,1,1,1,2}
# define Z_PIECE (int [8]) {0,0,1,0,1,1,2,1}
# define ZR_PIECE (int [8]) {1,0,0,1,1,1,0,2}

int			check_grid(char **grid, int grid_count, int i);
int			*print_tet(int *tet, int grid_count);
int			error_check(char** grid, int count_hash, int i, int x, int y);
char		*get_tetid(int *tet);
int			*trans_coord(int *tet);
int			dup_coord(int *dst, int *src);
int			low_x(int *tet);
int			low_y(int *tet);
int			tetcmp(int *tet, int *arr, int n);
t_tetris	*store_tet(int *tet, int grid_count);
t_tetris	*append(void *tet_id, t_tetris *head, char c);
t_tetris	*add_piece(void *tet_id, char c);
int			*convert_id(char *id);

int			top_x(int *tet);
int			top_y(int *tet);
int			box_collision(int *tet, int size);
int			piece_collision(int *tet2, int *tet);
int			collision(int *tet2, int *tet, int size);
int			preread(char **argv);

#endif
