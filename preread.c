/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   preread.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ycucchi <yoan066@yahoo.fr>                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/15 12:33:37 by ycucchi           #+#    #+#             */
/*   Updated: 2022/02/15 14:42:34 by ycucchi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include "fillit.h"
#include <stdio.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <fcntl.h>

int	preread(int fd)
{
	int		size;
	int		ret;
	char	*line;

	size = 0;
	line = NULL;
	ret = get_next_line(fd, &line);
	while (ret > 0)
	{
		size++;
		ret = get_next_line(fd, &line);
	}
	printf("size = %d\n", size);
	close(fd);
	return (size);
}
