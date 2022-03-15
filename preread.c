/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   preread.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ycucchi <yoan066@yahoo.fr>                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/15 12:33:37 by ycucchi           #+#    #+#             */
/*   Updated: 2022/03/11 17:23:11 by ycucchi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include "fillit.h"
int	preread(const int fd)
{
	char *line;

	line = NULL;
	while (1)
	{
		printf("before read one\n");
		read_one(fd, line);
		printf("after read one \n");
		if (!get_next_line(fd, &line))
			break ;
//		free(line);
		if (ft_strlen(line) != 0)
			ft_exit();
	}
	close(fd);
	return (1);
}
