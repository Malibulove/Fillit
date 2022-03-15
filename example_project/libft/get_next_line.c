/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekantane <ekantane@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/12 11:33:57 by ycucchi           #+#    #+#             */
/*   Updated: 2022/03/14 18:05:32 by ekantane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static int	get_line(char **s, char **line)
{
	int		len;
	char	*temp;

	len = 0;
	while ((*s)[len] != '\n' && (*s)[len] != '\0')
		len++;
	if ((*s)[len] == '\n')
	{
		if (!(*line = ft_strsub(*s, 0, len)))
			return (-1);
		if (!(temp = ft_strdup(&((*s)[len + 1]))))
			return (-1);
		ft_strdel(s);
		*s = temp;
	}
	else
	{
		if (!(*line = ft_strdup(*s)))
			return (-1);
		ft_strdel(s);
		return (0);
	}
	return (1);
}

static int	ret_value(char **s, char **line, int ret, int fd)
{
	if (ret < 0)
		return (-1);
	else if (ret == 0 && s[fd] == NULL)
		return (0);
	else
		return (get_line(&s[fd], line));
}

int			get_next_line(const int fd, char **line)
{
	int			ret;
	char		buff[BUFF_SIZE + 1];
	char		*temp;
	static char	*s[FD_MAX];

	if (fd < 0 || line == NULL)
		return (-1);
	*line = NULL;
	while ((ret = read(fd, buff, BUFF_SIZE)) > 0)
	{
		buff[ret] = '\0';
		if (s[fd] == NULL)
			s[fd] = ft_strdup(buff);
		else
		{
			if (!(temp = ft_strjoin(s[fd], buff)))
				return (-1);
			free(s[fd]);
			s[fd] = temp;
		}
		if (ft_strchr(s[fd], '\n'))
			break ;
	}
	return (ret_value(s, line, ret, fd));
}
