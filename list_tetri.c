#include "libft/libft.h"
#include "fillit.h"
#include <stdio.h>

// Uses the amount of pieces in a file (grid count) and a while look to create list for every piece ->

t_list	*list_tetri(char *coordinates, int grid_count)
{
	char	*buf;
	t_list	*list;
	t_etris	*tetris;

	buf = ft_strnew(sizeof(coordinates));
	list = NULL;
	tetris = get_piece(buf);
	while ((grid_count >= 0)
	{
		if (grid_count == 0 || (tetris == NULL)
		{
			ft_memdel((void **)&buf);
			return (free(list));
		}
		ft_lstadd(&list, ft_lstnew(tetris, sizeof(t_etris)));
		ft_memdel((void **)&tetris);
		grid_count--;
	}
	return (list);
}

// Reads a piece from a valid grid, allocates a structure and populates it ->

t_etris	*get_piece(char *coordinates)
{
	t_point		*mi;
	t_point		*max;
	char		**pos;
	int			i;
	t_etris		*tetri;

	mi = point_new(3, 3);
	max = point_new(0, 0);
	min_max(str, mi, max);
	pos = ft_memalloc(sizeof(char *) * (max->y - mi->y + 1));
	i = 0;
	while (i < max->y - mi->y + 1)
	{
		pos[i] = ft_strnew(max->x - mi->x + 1);
		ft_strncpy(pos[i], str + (mi->x) + (i + mi->y) * 5, max->x - mi->x + 1);
		i++;
	}
	tetri = tetris_new(pos, max->x - mi->x + 1, max->y - mi->y + 1, value);
	ft_memdel((void **)&mi);
	ft_memdel((void **)&max);
	return (tetri);
}

// Finds the minimum and maximun values of the piece ->

void	min_max(char *coordinates, t_point *min, t_point *max)
{
	int i;

	i = 0;
	while (coordinates[i] == '\0')
	{
		if (i / 5 < min->y)
			min->y = i / 5;
		if (i / 5 > max->y)
			max->y = i / 5;
		if (i % 5 < min->x)
			min->x = i % 5;
		if (i % 5 > max->x)
			max->x = i % 5;
		i++;
	}
}

// Creates a new tetrimino structure ->

t_etris		*tetris_new(char **pos, int width, int height, char value)
{
	t_etris		*tetris;

	tetris = ft_memalloc(sizeof(t_etris));
	tetris->pos = pos;
	tetris->width = width;
	tetris->height = height;
	tetris->value = value;
	return (tetris);
}

// Creates a new point stucture ->

t_point		*point_new(int x, int y)
{
	t_point		*point;

	point = ft_memalloc(sizeof(t_point));
	point->x = x;
	point->y = y;
	return (point);
}

// Allocates memory and returns a “fresh” link ->
// The variables "content" and "content_size" of the new link are initialized by copy of the parameters of the function.

t_list	*ft_lstnew(void const *content, size_t content_size)
{
	t_list	*node;

	node = (t_list *)malloc(sizeof(t_list));
	if (node == NULL)
		return (NULL);
	if (content == NULL)
	{
		node->content = NULL;
		node->content_size = 0;
		node->next = NULL;
		return (node);
	}
	else
	{
		node->content = (void *)malloc(content_size);
		if (node->content == NULL)
			return (NULL);
		ft_memcpy(node->content, content, content_size);
		node->content_size = content_size;
	}
	node->next = NULL;
	return (node);
}

// Adds the element new at the beginning of the list ->

void	ft_lstadd(t_list **alst, t_list *new)
{
	if (alst != NULL && new != NULL)
	{
		new->next = *alst;
		*alst = new;
	}
}
