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

typedef struct	s_point
{
	int			x;
	int			y;
}				t_point;
typedef struct	s_etris
{
	char		**pos;
	int			width;
	int			height;
	char		value;
}				t_etris;
typedef struct s_list
{
	void			*content;
	size_t			content_size;
	struct s_list	*next;
}					t_list;
t_list			*list_tetri(char **grid, int grid_count);
t_point			*point_new(int x, int y);
t_etris			*tetris_new(char **pos, int width, int height, char c);
#endif