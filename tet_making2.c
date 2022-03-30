/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tet_making2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekantane <ekantane@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/25 17:31:20 by ycucchi           #+#    #+#             */
/*   Updated: 2022/03/30 14:09:34 by ekantane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

t_piece	ld_piece(void)
{
	return ((t_piece){"ld_piece", {0, 0, 1, 0, 1, 1, 1, 2}});
}

t_piece	ll_piece(void)
{
	return ((t_piece){"ll_piece", {2, 0, 0, 1, 1, 1, 2, 1}});
}

t_piece	j_piece(void)
{
	return ((t_piece){"j_piece", {1, 0, 1, 1, 0, 2, 1, 2}});
}

t_piece	jr_piece(void)
{
	return ((t_piece){"jr_piece", {0, 0, 0, 1, 1, 1, 2, 1}});
}

t_piece	jd_piece(void)
{
	return ((t_piece){"jd_piece", {0, 0, 1, 0, 0, 1, 0, 2}});
}
