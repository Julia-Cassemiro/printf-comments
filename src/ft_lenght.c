/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lenght.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgomes-c <jgomes-c@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/29 18:32:31 by jgomes-c          #+#    #+#             */
/*   Updated: 2021/07/17 00:28:26 by jgomes-c         ###   ########.fr       */
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

void	ft_change_zero(t_print *content)
{
	if (content->pnt || content->zero)
	{
		if (content->spa)
		{
			content->tl += write(1, " ", 1);
			content->wdt -= content->spa;
		}
		if (!content->prc)
		{
			while (content->zero && content->wdt-- > 0) 
				content->tl += write(1, "0", 1);
			while (!content->zero && content->wdt-- > 0)
				content->tl += write(1, " ", 1);
		}
		else
		{
			content->wdt -= content->prc;
			while (content->dash && content->prc-- > 0)
				content->tl += write(1, "0", 1);
			while (content->wdt-- > 0)
				content->tl += write(1, " ", 1);
			while (!content->dash && content->prc-- > 0)
				content->tl += write(1, "0", 1);
		}
	}
	if (content->prc && content->dash && !content->wdt)//caso tenha prc e dash, mas n tem width
		while (!content->wdt && content->prc-- > 0)
			content->tl += write(1, "0", 1);
}

void	ft_right(t_print *content)
{
	if (content->spa)
	{
		content->tl += write(1, " ", 1);
		content->wdt -= content->spa;
	}
	if (content->plus && (content->zero || content->dash || (!content->wdt && !content->prc)))
	{
		if (content->sign)
			content->plus = 0;
	}
	if (content->sign && (content->zero || content->dash || (!content->wdt && !content->prc)))
	{
		content->tl += write(1, "-", 1); //ajuste para por o sinal antes, lembrando q n tem wdt
		content->sign = 0;
	}
	if (content->wdt && content->plus)
		content->wdt -= content->plus;
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