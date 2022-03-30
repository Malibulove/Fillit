/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tet_making.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekantane <ekantane@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/25 17:31:20 by ycucchi           #+#    #+#             */
/*   Updated: 2022/03/30 14:38:04 by ekantane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

t_piece	i_piece(void)
{
	return ((t_piece){"i_piece", {0, 0, 0, 1, 0, 2, 0, 3}});
}

t_piece	ih_piece(void)
{
	return ((t_piece){"ih_piece", {0, 0, 1, 0, 2, 0, 3, 0}});
}

t_piece	o_piece(void)
{
	return ((t_piece){"o_piece", {0, 0, 1, 0, 0, 1, 1, 1}});
}

t_piece	l_piece(void)
{
	return ((t_piece){"l_piece", {0, 0, 0, 1, 0, 2, 1, 2}});
}

t_piece	lr_piece(void)
{
	return ((t_piece){"lr_piece", {0, 0, 1, 0, 2, 0, 0, 1}});
}
