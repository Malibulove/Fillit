/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tet_making3.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekantane <ekantane@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/25 17:31:20 by ycucchi           #+#    #+#             */
/*   Updated: 2022/03/30 14:09:38 by ekantane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

t_piece	jl_piece(void)
{
	return ((t_piece){"jl_piece", {0, 0, 1, 0, 2, 0, 2, 1}});
}

t_piece	tt_piece(void)
{
	return ((t_piece){"tt_piece", {1, 0, 0, 1, 1, 1, 2, 1}});
}

t_piece	tr_piece(void)
{
	return ((t_piece){"tr_piece", {0, 0, 0, 1, 1, 1, 0, 2}});
}

t_piece	td_piece(void)
{
	return ((t_piece){"td_piece", {0, 0, 1, 0, 2, 0, 1, 1}});
}

t_piece	tl_piece(void)
{
	return ((t_piece){"tl_piece", {1, 0, 0, 1, 1, 1, 1, 2}});
}
