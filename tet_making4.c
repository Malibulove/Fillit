/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tet_making4.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekantane <ekantane@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/25 17:31:20 by ycucchi           #+#    #+#             */
/*   Updated: 2022/03/30 14:09:45 by ekantane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

t_piece	ss_piece(void)
{
	return ((t_piece){"ss_piece", {1, 0, 2, 0, 0, 1, 1, 1}});
}

t_piece	sr_piece(void)
{
	return ((t_piece){"sr_piece", {0, 0, 0, 1, 1, 1, 1, 2}});
}

t_piece	z_piece(void)
{
	return ((t_piece){"z_piece", {0, 0, 1, 0, 1, 1, 2, 1}});
}

t_piece	zr_piece(void)
{
	return ((t_piece){"zr_piece", {1, 0, 0, 1, 1, 1, 0, 2}});
}
