/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   identification.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekantane <ekantane@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/26 02:38:58 by ycucchi           #+#    #+#             */
/*   Updated: 2022/03/30 16:36:02 by ekantane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

char	*check_tet(int *tet)
{
	char	*name;

	name = NULL;
	if (!name)
		name = get_tetid_io(tet, name);
	if (!name)
		name = get_tetid_l(tet, name);
	if (!name)
		name = get_tetid_j(tet, name);
	if (!name)
		name = get_tetid_tt(tet, name);
	if (!name)
		name = get_tetid_sz(tet, name);
	return (name);
}

int	tetcmp(int *tet, int *libtet)
{
	int	i;

	i = 0;
	while (i < 8)
	{
		if (tet[i] != libtet[i])
			return (-1);
		i++;
	}
	return (1);
}

int	*char_to_int_id(char *name)
{
	int	*tet;

	tet = (int *)malloc(sizeof(int) * 8);
	if (!tet)
		return (NULL);
	(ft_strcmp(name, "i_piece") == 0) && (dup_coord(tet, i_piece().coord));
	(ft_strcmp(name, "ih_piece") == 0) && (dup_coord(tet, ih_piece().coord));
	(ft_strcmp(name, "o_piece") == 0) && (dup_coord(tet, o_piece().coord));
	(ft_strcmp(name, "l_piece") == 0) && (dup_coord(tet, l_piece().coord));
	(ft_strcmp(name, "lr_piece") == 0) && (dup_coord(tet, lr_piece().coord));
	(ft_strcmp(name, "ld_piece") == 0) && (dup_coord(tet, ld_piece().coord));
	(ft_strcmp(name, "ll_piece") == 0) && (dup_coord(tet, ll_piece().coord));
	(ft_strcmp(name, "j_piece") == 0) && (dup_coord(tet, j_piece().coord));
	(ft_strcmp(name, "jr_piece") == 0) && (dup_coord(tet, jr_piece().coord));
	(ft_strcmp(name, "jd_piece") == 0) && (dup_coord(tet, jd_piece().coord));
	(ft_strcmp(name, "jl_piece") == 0) && (dup_coord(tet, jl_piece().coord));
	(ft_strcmp(name, "tt_piece") == 0) && (dup_coord(tet, tt_piece().coord));
	(ft_strcmp(name, "tr_piece") == 0) && (dup_coord(tet, tr_piece().coord));
	(ft_strcmp(name, "td_piece") == 0) && (dup_coord(tet, td_piece().coord));
	(ft_strcmp(name, "tl_piece") == 0) && (dup_coord(tet, tl_piece().coord));
	(ft_strcmp(name, "ss_piece") == 0) && (dup_coord(tet, ss_piece().coord));
	(ft_strcmp(name, "sr_piece") == 0) && (dup_coord(tet, sr_piece().coord));
	(ft_strcmp(name, "z_piece") == 0) && (dup_coord(tet, z_piece().coord));
	(ft_strcmp(name, "zr_piece") == 0) && (dup_coord(tet, zr_piece().coord));
	return (tet);
}
