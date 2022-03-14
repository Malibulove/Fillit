/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekantane <ekantane@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/17 17:28:36 by ycucchi           #+#    #+#             */
/*   Updated: 2022/03/14 17:53:29 by ekantane         ###   ########.fr       */
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

# define MAX 27

typedef struct	s_trm
{
	int		rows[3];
	int		cols[3];
	char	alphabet;
}				t_trm;

int				validate_file(int fd, char **blocks);
char			**make_bigger_map(int mapsize, char **map);
int				struct_creator(t_trm *tetriminos, char **blocks);
char			**solver(t_trm *arr_tetriminos);
void			free_map(char **map);
int				back_tracking(t_trm *arr_tetriminos, char **map, int mapsize);
void			remove_tetrimino(char **map, int x, int y, t_trm tetrimino);
void			place_tetrimino(char **map, int x, int y, t_trm tetrimino);
int				check_plc(char **map, int x, int y, t_trm tetrimino);
void			print_status(char **map);

#endif
