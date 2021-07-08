/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgomes-c <jgomes-c@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/28 17:22:48 by jgomes-c          #+#    #+#             */
/*   Updated: 2021/07/05 16:26:48 by jgomes-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
static int	ft_nbsize(long n)
{
	int		size;

	size = 1;
	while (n / 10)
	{
		n = n / 10;
		size++;
	}
	if (n < 0)
		size++;
	return (size);
}

static long	ft_getunit(long n, int unit)
{
	while (unit--)
		n = n / 10;
	return (n % 10);
}

char	*ft_itoa(int n)
{
	char	*rst;
	int		i;
	int		j;
	long	nbr;

	nbr = n;
	i = 0;
	j = ft_nbsize(nbr);
	rst = (char *)malloc(sizeof(char) * (j + 1));
	if (!rst)
		return (NULL);
	if (rst)
	{
		if (nbr < 0)
		{
			rst[i] = '-';
			i++;
			nbr *= -1;
		}
		while (j - i)
		{
			rst[i] = '0' + ft_getunit(nbr, j - i - 1);
			i++;
		}
		rst[i] = '\0';
	}
	return (rst);
}
