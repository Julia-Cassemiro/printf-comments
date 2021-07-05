/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hexatoi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgomes-c <jgomes-c@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/05 14:51:25 by jgomes-c          #+#    #+#             */
/*   Updated: 2021/07/05 15:57:36 by jgomes-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_hexatoi(char *str, unsigned long n, int base, int c)
{
	int		count;

	count = 0;
	if (n == 0)
		str[count++] = '0';
	while (n > 0)
	{
		if (n % base >= 10)
			str[count++] = (n % base) - 10 + c;
		else
			str[count++] = (n % base) + '0';
		n /= base;
	}
	str[count] = '\0';
	return (str);
}
