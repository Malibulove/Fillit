#include "./libft/libft.h"
#include <stdio.h>

#include <fcntl.h>
#include <sys/stat.h>
#include <string.h>
#include <stdlib.h>

int	check_grid(char **grid, int grid_count);
int main(int argc, char **argv)
{
	int		fd;
	char	*line;
	int		ret;
	int		i;
	char	**grid;
	int		grid_count;

	i = 0;
	grid_count = 0;
	grid = (char **)malloc(sizeof(char *) * 50);
	if (argc > 2)
		return (0);
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
			printf("i = %d\n", i);
			if (check_grid(grid, grid_count) == -1)
				printf("grid is not ok\n");
			else
				printf("grid is fine\n");
			i = i - 5;
			grid_count++;
		}
	close(fd);
}
