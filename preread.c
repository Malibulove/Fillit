/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   preread.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ycucchi <yoan066@yahoo.fr>                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/15 12:33:37 by ycucchi           #+#    #+#             */
/*   Updated: 2022/02/15 17:54:34 by ycucchi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include "fillit.h"

int	preread(char **argv)
{
	int		size;
	int		ret;
	char	*line;
	int		fd;

	fd = open(argv[1], O_RDONLY);
	if (fd < 0)
		return (0);
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
