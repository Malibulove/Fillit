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
		grid[i] = ft_strdup(temp);
		i++;
		free(line);
		ret = get_next_line(fd, &line);
	}
	if (check_grid(grid) == -1)
		printf("grid is not ok");
	if (check_grid(grid) == 1)
		printf("grid is fine");
	close(fd);
}
