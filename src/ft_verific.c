/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_verific.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgomes-c <jgomes-c@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/29 13:40:38 by jgomes-c          #+#    #+#             */
/*   Updated: 2021/07/05 21:43:20 by jgomes-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"
#include "../libft/libft.h"

int 	ft_verific_letter(t_print *content, const char *sms, int cont)
{
	if (sms[cont] == 'c')
		to_char(content);
	if (sms[cont] == 's')
		to_string(content);
	return (cont);
	if (sms[cont] == 'd' || sms[cont] == 'i')
		to_int(content);
	if (sms[cont] == 'u')
		to_unsigned(content);
	if (sms[cont] == 'x' || sms[cont] == 'X')
		to_hexa(content, sms[cont] - 23);
}

// while n é o cspdiuxX%
int		ft_verific_symb(t_print *content, const char *sms, int cont)// aonde vamos cmc o check, poisção
{
	while (!(ft_isalpha(sms[cont]) || sms[cont] == '%'))
	{
		if (sms[cont] == '-')
			cont = ft_maybe_tracinho(content, sms, cont);
		if (sms[cont] == '0')
			cont = ft_maybe_zero(content, sms, cont);
		if (sms[cont] == '.')
			cont = ft_maybe_precision(content, sms, cont);
		if (sms[cont] == '*')
			cont = ft_maybe_estrelinha(content, sms, cont);
		if (ft_isdigit(sms[cont])) //if tem um numero la, define o width
			cont = ft_maybe_width(content, sms, cont);
		
	}
	ft_verific_letter(content, sms, cont);
	return (cont);
}
