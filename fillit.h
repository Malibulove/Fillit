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

typedef struct		t_piece
{
	char			name[20]; 
	int				coord[8];
}					s_piece;

void		give_value_to_tet(void);
int		h_count(char *line);
int		chk_char(char *line);
int			check_grid(char **grid, int size);
int			check_grid_old(char **grid, int grid_count);
int			*print_tet(int *tet, int grid_count);
int			error_check(char** grid, int count_hash, int i, int x, int y);
int		solve_driver(int fd);
char		*get_tetid(int *tet);
int			*trans_coord(int *tet);
int			dup_coord(int *dst, int *src);
int			read_one(const int fd, char *line);
int			low_x(int *tet);
int			low_y(int *tet);
int			tetcmp(int *tet, int *arr, int n);
t_tetris	*store_tet(const int fd, char *line);
t_tetris	*append(void *tet_id, t_tetris *head, char c);
t_tetris	*add_piece(void *tet_id, char c);
int			*convert_id(char *id);
void		ft_exit(void);
int			top_x(int *tet);
int			top_y(int *tet);
int			box_collision(int *tet, int size);
int			piece_collision(char **grid, int *tet);
int			collision(char **grid, int *tet, int size);
char		contain_grid(char **grid);
int			preread(const int fd);
int			solve_tet(char **grid, t_tetris *stack, int size);
int			stack_tet(t_tetris *stack);
int			*x_shift(int *tet, int x);
int			*y_shift(int *tet, int y);
int			*shift_tet(int *tet, int x, int y);
void		print_grid(char **grid, int size);
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
int		*one_tetris(const int fd, char *line);
t_tetris	*store_first(int *first_tet);

#endif
