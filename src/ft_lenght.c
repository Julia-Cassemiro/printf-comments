/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lenght.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgomes-c <jgomes-c@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/29 18:32:31 by jgomes-c          #+#    #+#             */
/*   Updated: 2021/07/07 02:22:36 by jgomes-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"
#include "../libft/libft.h"

void	ft_update_lenght(t_print *content, int len)
{
	if (content->sign) //if o é negativo
	{
		if (content->wdt) //wdt fica cm -1, pq um dos espaços é pro -
			content->wdt -= 1;
	}
	if (content->prc > 0)
		content->zero = 0; //0 flag ignored with precision
	if (content->wdt && content->wdt >= content->prc) //se o width é maior q a precisão
	{
		if (content->prc > len) //se a minha prc for maior q o len
			content->prc -= len; //ela preenche só oq falta
		if (!content->is_zero)
			content->wdt = content->wdt - content->prc - len; //result é o preenchimento correto
	}
	else if (content->prc > content->wdt) //se a prc for maior q o wdt
	{
		content->wdt = 0; //adeus wdt
		content->prc -= len; //precisão preenche o len
	}
}
