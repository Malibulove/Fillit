/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekantane <ekantane@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/15 16:54:54 by ycucchi           #+#    #+#             */
/*   Updated: 2022/03/14 17:02:41 by ekantane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./libft/libft.h"
#include "fillit.h"

int	main(int argc, char **argv)
{
	t_trm	arr_tetriminos[MAX];
	int		fd;
	char	*blocks[MAX];

	if (argc != 2)
	{
		ft_putstr("usage: ./fillit source_file\n");
		exit(0);
	}
	if (argc == 2)
	{
		fd = open(argv[1], O_RDONLY);
		if (fd == -1 || !(validate_file(fd, blocks)))
		{
			ft_putstr("error\n");
			return (0);
		}
		struct_creator(arr_tetriminos, blocks);
		free_map(solver(arr_tetriminos));
		close(fd);
	}
	return (0);
}
