/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialization.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ycucchi <yoan066@yahoo.fr>                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/26 05:05:24 by ycucchi           #+#    #+#             */
/*   Updated: 2022/03/26 05:05:25 by ycucchi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include "fillit.h"

char	*get_tetid_io(int *tet, char *name)
{
	t_piece	i_piece(void);
	t_piece	ih_piece(void);	
	t_piece	o_piece(void);

	((tetcmp(tet, i_piece().coord) == 1) && (name = "i_piece"));
	((tetcmp(tet, ih_piece().coord) == 1) && (name = "ih_piece"));
	((tetcmp(tet, o_piece().coord) == 1) && (name = "o_piece"));
	return (name);
}

char	*get_tetid_l(int *tet, char *name)
{
	t_piece	l_piece(void);
	t_piece	lr_piece(void);
	t_piece	ld_piece(void);
	t_piece	ll_piece(void);

	((tetcmp(tet, l_piece().coord) == 1) && (name = "l_piece"));
	((tetcmp(tet, lr_piece().coord) == 1) && (name = "lr_piece"));
	((tetcmp(tet, ld_piece().coord) == 1) && (name = "ld_piece"));
	((tetcmp(tet, ll_piece().coord) == 1) && (name = "ll_piece"));
	return (name);
}

char	*get_tetid_j(int *tet, char *name)
{
	t_piece	j_piece(void);
	t_piece	jr_piece(void);
	t_piece	jd_piece(void);
	t_piece	jl_piece(void);

	((tetcmp(tet, j_piece().coord) == 1) && (name = "j_piece"));
	((tetcmp(tet, jr_piece().coord) == 1) && (name = "jr_piece"));
	((tetcmp(tet, jd_piece().coord) == 1) && (name = "jd_piece"));
	((tetcmp(tet, jl_piece().coord) == 1) && (name = "jl_piece"));
	return (name);
}

char	*get_tetid_tt(int *tet, char *name)
{
	t_piece	tt_piece(void);
	t_piece	tr_piece(void);
	t_piece	td_piece(void);
	t_piece	tl_piece(void);

	((tetcmp(tet, tt_piece().coord) == 1) && (name = "tt_piece"));
	((tetcmp(tet, tr_piece().coord) == 1) && (name = "tr_piece"));
	((tetcmp(tet, td_piece().coord) == 1) && (name = "td_piece"));
	((tetcmp(tet, tl_piece().coord) == 1) && (name = "tl_piece"));
	return (name);
}

char	*get_tetid_sz(int *tet, char *name)
{
	t_piece	ss_piece(void);
	t_piece	sr_piece(void);
	t_piece	z_piece(void);
	t_piece	zr_piece(void);

	((tetcmp(tet, ss_piece().coord) == 1) && (name = "ss_piece"));
	((tetcmp(tet, sr_piece().coord) == 1) && (name = "sr_piece"));
	((tetcmp(tet, z_piece().coord) == 1) && (name = "z_piece"));
	((tetcmp(tet, zr_piece().coord) == 1) && (name = "zr_piece"));
	return (name);
}
