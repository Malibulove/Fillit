#include "./libft/libft.h"
#include <stdio.h>

#include <fcntl.h>
#include <sys/stat.h>
#include <string.h>
#include <stdlib.h>

int	check_grid(char **grid);
int main(int argc, char **argv)
{
	int		fd;
	char	*line;
	int		ret;
	char	*temp;
	int		i;
	char	**grid;

	i = 0;
	grid = (char **)malloc(sizeof(char *) * 5);
	if (argc > 2)
		return (0);
	fd = open(argv[1], O_RDONLY);
	if (fd < 0)
		return (0);
	ret = get_next_line(fd, &line);
	while (ret > 0)
	{
		temp = line;
		printf("line = %s\n", line);
		grid[i] = ft_strdup(temp);
		printf("grid[%d] = %s\n", i, grid[i]);
		i++;
		free(line);
		ret = get_next_line(fd, &line);
	}
	check_grid(grid);
//	printf("grid[1][0] = %c\n", grid[1][0]);
//	printf("grid[1][1] = %c\n", grid[1][1]);
//	printf("grid[1][2] = %c\n", grid[1][2]);
//	printf("grid[1][3] = %c\n", grid[1][3]);
	close(fd);
}
