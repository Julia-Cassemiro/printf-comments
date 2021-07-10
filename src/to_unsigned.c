/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   to_unsigned.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgomes-c <jgomes-c@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/05 14:51:35 by jgomes-c          #+#    #+#             */
/*   Updated: 2021/07/09 21:15:49 by jgomes-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"
#include "../libft/libft.h"

void	ft_to_unsigned(t_print *content)
{
	int count;
	unsigned int u;
	int len;
	char *nbr;

	count = 0;
	u = va_arg(content->args, int);
	if (!u) //zero, 0
	{
		ft_write_zero(content);
		return ;
	}
	nbr = ft_utoa(u); //transforma pra alphanumeric
	if (!nbr)
		return ;
	len = ft_numlen(u);
	ft_update_lenght(content, len); //confere tamanho q vai ser escrito wdt, prc
	ft_right(content);	
	while (nbr[count])
		content->tl += write (1, &nbr[count++], 1);
	ft_left(content);
	free(nbr);
}
