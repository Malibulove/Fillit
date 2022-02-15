/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ycucchi <yoan066@yahoo.fr>                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/15 16:54:54 by ycucchi           #+#    #+#             */
/*   Updated: 2022/02/15 17:03:42 by ycucchi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./libft/libft.h"
#include "fillit.h"

int	main(int argc, char **argv)
{
	int		fd;
	char	*line;
	int		ret;
	int		i;
	char	**grid;
	int		grid_count;

	i = 0;
	grid_count = 0;
	if (argc > 2)
		return (0);
	fd = open(argv[1], O_RDONLY);
	grid = (char **)malloc(sizeof(char *) * (preread(fd)));
	fd = open(argv[1], O_RDONLY);
	if (fd < 0)
		return (0);
	ret = get_next_line(fd, &line);
	while (ret > 0)
	{
		grid[i] = ft_strdup(line);
		i++;
		free(line);
		ret = get_next_line(fd, &line);
	}
	if (&grid[i][0] != NULL)
		printf("error\n");
	else
		while (i > 0)
		{
//			printf("i = %d\n", i);
			if (check_grid(grid, grid_count, i) == -1)
				printf("grid is not ok\n");
			else
				printf("grid is fine\n");
			i = i - 5;
			grid_count++;
		}
	close(fd);
}
