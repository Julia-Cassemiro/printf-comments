/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgomes-c <jgomes-c@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/12 15:10:16 by jgomes-c          #+#    #+#             */
/*   Updated: 2021/07/12 15:13:18 by jgomes-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_putnbr_base(unsigned long n, char *base)
{
	unsigned long	base_len;
	unsigned long	num;
	int				l;

	l = 1;
	num = n;
	base_len = ft_strlen(base);
	if (num == 0)
	{
		write(1, "0", 1);
		return (l);
	}
	if (num >= base_len)
	{
		l += ft_putnbr_base(num / base_len, base);
		write(1, &base[num % base_len], 1);
	}
	else if (num < base_len)
		write(1, &base[num], 1);
	return (l);
}