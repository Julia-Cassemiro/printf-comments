/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   to_hexa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgomes-c <jgomes-c@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/05 15:55:46 by jgomes-c          #+#    #+#             */
/*   Updated: 2021/07/17 02:14:08 by jgomes-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"
#include "../libft/libft.h"

void ft_to_hexa(t_print *content, int cont)
{
	unsigned int	x;
	int				len;
	char			*nbr;

	x = va_arg(content->args, unsigned int);
	if (!x) //zero, 0
	{
		ft_write_zero(content);
		return ;
	}
	len = ft_numlen_base(x, 16); //pega o tamanho //converter para char
	nbr = (char *)malloc(sizeof(char) * (len + 1)); //malloc cm espaço pro \0
	if (!nbr)
		return ;
	nbr = ft_hexatoi(nbr, x, 16, cont);
	ft_update_lenght(content, len);
	ft_right(content);
	while (nbr && len-- > 0)
		content->tl += write(1, &nbr[len], 1);
	ft_left(content);
	free(nbr);
}
