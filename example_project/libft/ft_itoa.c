/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ycucchi <yoan066@yahoo.fr>                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/22 13:43:48 by ycucchi           #+#    #+#             */
/*   Updated: 2021/11/22 19:03:42 by ycucchi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_len(int n)
{
	int	count;

	count = 0;
	if (n <= 0)
		count++;
	while (n != 0)
	{
		n = n / 10;
		count++;
	}
	return (count);
}

static void	ft_fill_str(int count, int offset, int n, char *str)
{
	while (count > offset)
	{
		str[count - 1] = n % 10 + '0';
		n = n / 10;
		count--;
	}
}

char	*ft_itoa(int n)
{
	char	*str;
	int		count;
	int		offset;

	offset = 0;
	count = ft_len(n);
	str = (char *)malloc(sizeof(char) * (count + 1));
	if (str == NULL)
		return (NULL);
	if (n == -2147483648)
	{
		str[0] = '-';
		str[1] = '2';
		n = 147483648;
		offset = 2;
	}
	if (n < 0)
	{
		str[0] = '-';
		offset = 1;
		n = -n;
	}
	ft_fill_str(count, offset, n, str);
	str[count] = '\0';
	return (str);
}
