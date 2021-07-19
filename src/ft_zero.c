/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_zero.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgomes-c <jgomes-c@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/17 12:43:40 by jgomes-c          #+#    #+#             */
/*   Updated: 2021/07/19 11:34:17 by jgomes-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"
#include "../libft/libft.h"

void ft_plus(t_print *content)
{
	if (content->spa)
	{
		content->tl += write(1, " ", 1);
		if (content->wdt > 1)
			content->wdt -= content->spa;
		if (content->wdt == 1)
			content->wdt = 0;
	}
	if (content->wdt > 1)
		content->wdt -= content->plus;
	if (!content->prc)
	{
		if (content->plus)
		{
			content->tl += write(1, "+", 1);
			if (content->wdt > 1)
				content->wdt -= content->plus;
			if (content->wdt == 1)
				content->wdt = 0;
			content->plus = 0;
		}
		while (content->zero && content->wdt-- > 0) 
			content->tl += write(1, "0", 1);
		while (!content->zero && content->wdt-- > 0 && !content->spa)
			content->tl += write(1, " ", 1);
	}
	else
	{
		if (content->dash || (content->zero && !content->pnt))
		{
			content->tl += write(1, "+", 1);
			content->plus = 0;
		}
		content->wdt -= content->prc + 1;
		if (content->prc > 1 && content->wdt > 0)
			content->prc += 1;
	}
	while (content->dash && content->prc-- > 0)
		content->tl += write(1, "0", 1);
	if (!content->prc && content->zero)
	{
		while (content->wdt-- > 0 )
			content->tl += write(1, "0", 1);
	}
	while (content->wdt-- > 0)
		content->tl += write(1, " ", 1);
	if (!content->dash && content->plus)
		content->tl += write(1, "+", 1);
	while (!content->dash && content->prc-- > 0)
		content->tl += write(1, "0", 1);
	if (content->prc && content->dash && !content->wdt)//caso tenha prc e dash, mas n tem width
		while (!content->wdt && content->prc-- > 0)
			content->tl += write(1, "0", 1);	
}

void	ft_change_zero(t_print *content)
{
	if (content->pnt || content->zero)
	{
		if (content->plus)
		{
			ft_plus(content);
			return ;
		}
		if (content->spa)
		{
			content->tl += write(1, " ", 1);
			if (content->wdt > 1)
				content->wdt -= content->spa;
			if (content->wdt == 1)
				content->wdt = 0;
		}
		if (!content->prc)
		{
			while (content->zero && content->wdt-- > 0) 
				content->tl += write(1, "0", 1);
			while (!content->zero && content->wdt-- > 0 && !content->spa)
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
