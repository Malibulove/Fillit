/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tetrimino_lists.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekantane <ekantane@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/03 10:18:37 by ekantane          #+#    #+#             */
/*   Updated: 2022/02/01 11:41:56 by ekantane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H
# include <string.h>
# include "libft/libft.h"

typedef struct		s_tetris
{
	void			*tet_id;
	char			c;
	struct s_tetris	*next;
}					t_tetris;

# define I_PIECE_0 (int [8]) {0,0,1,0,2,0,3,0}
# define O_PIECE_0 (int [8]) {0,0,0,1,1,0,1,1}
# define USAGE "usage:\t./fillit source_file\n"

int			check_grid(char **grid, int grid_count);
char				*get_tetid(int *tet);
int					*trans_coord(int *tet);
int					dup_coord(int *dst, int *src);
int		low_x(int *tet);
int		low_y(int *tet);
int	tetcmp(int *tet, int *arr, int n);
t_tetris	*store_tet(int *tet, char **grid, int grid_count);
t_tetris			*append(void *tet_id, t_tetris *head, char c);
t_tetris			*add_piece(void *tet_id, char c);
int					*convert_id(char *id);


#endif