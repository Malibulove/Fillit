/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ycucchi <yoan066@yahoo.fr>                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/28 12:37:55 by ycucchi           #+#    #+#             */
/*   Updated: 2022/01/31 18:12:48 by ycucchi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <fcntl.h>
#include "libft/libft.h"

int	check_grid(char **grid);

int	main(int argc, char **argv)
{
	int	check;
	int	fd;
	char **grid = NULL;

	check = 0;
	printf("first if");
	if (argc > 2)
		return (0);
	printf("apres first if");
	fd = open(argv[1], O_RDONLY);
	if (fd < 0)
		return (-1);
	printf("apres fd");
	get_next_line(fd, grid);
	printf("%s", grid);
	if (check == 1)
		printf("yes");
	if (check == -1)
		printf("no");
	return (0);
}
