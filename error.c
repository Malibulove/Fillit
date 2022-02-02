/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ycucchi <yoan066@yahoo.fr>                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/27 12:38:59 by ycucchi           #+#    #+#             */
/*   Updated: 2022/02/02 14:09:06 by ycucchi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

we need to handle errors like
- same tetriminos (there is 19 differents possibilities)
- Each block of a Tetrimino must touch at least one other block on any of his 4 sides (up, down, left and right)
- if multiples solutions exists,  the solution with the pieces placed in the order they are provided at their top-most left-most positions is correct. 

