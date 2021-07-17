/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lenght.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgomes-c <jgomes-c@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/29 18:32:31 by jgomes-c          #+#    #+#             */
/*   Updated: 2021/07/17 16:11:06 by jgomes-c         ###   ########.fr       */
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
		else
			content->prc = 0;
		if (!content->is_zero)
			content->wdt = content->wdt - content->prc - len; //result é o preenchimento correto
	}
	else if (content->prc > content->wdt) //se a prc for maior q o wdt
	{
		content->wdt = 0; //adeus wdt
		content->prc -= len; //precisão preenche o len
	}
}

void	ft_right_string(t_print *content, int len)
{
	while (content->zero && content->wdt-- > len)
		content->tl += write(1, "0", 1);
	if (content->prc &&content->prc < len)
		while (content->wdt-- >content->prc)
			content->tl += write(1, " ", 1);
	else
		while (content->wdt-- > len)
			content->tl += write(1, " ", 1);
}

void	ft_right(t_print *content)
{
	if (content->spa)
	{
		content->tl += write(1, " ", 1);
		content->wdt -= content->spa;
	}
	if (content->sign && (content->zero || content->dash || (!content->wdt && !content->prc)))
	{
		content->tl += write(1, "-", 1); //ajuste para por o sinal antes, lembrando q n tem wdt
		content->sign = 0;
		content->plus = 0; //!mudei aqui
	}
	if (content->wdt && (content->plus || content->hash))
	{
		content->wdt -= content->plus;
		content->wdt -= content->hash;
	}
	if (content->zero || content->dash || (!content->wdt && !content->prc))
	{
		if (content->plus)
			content->tl += write(1, "+", 1);
		if (content->hash)
			content->tl += write(1, "0x", 2);
		content->plus = 0;
		content->hash = 0;
	}
	if (!content->dash)
	{
		while (!content->zero && --content->wdt > -1)// se n tiver zero completa cm espaço
			content->tl += write(1, " ", 1);
		while (content->zero && --content->wdt > -1)//se tiver zero completa cm espaço
			content->tl += write(1, "0", 1);
		if (content->sign)
			content->tl += write (1, "-", 1);
		if (content->plus)
			content->tl += write(1, "+", 1);
		if (content->hash)
			content->tl += write(1, "0x", 2);
	}
	while (--content->prc > -1)
		content->tl += write(1, "0", 1);
}

void	ft_left(t_print *content)
{
	if (content->dash)
	{
		while (content->zero && --content->prc > -1)
			content->tl += write(1, "0", 1);
		while (--content->wdt > -1)
			content->tl += write(1, " ", 1);
	}
}
