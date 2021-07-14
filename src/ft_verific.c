/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_verific.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgomes-c <jgomes-c@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/29 13:40:38 by jgomes-c          #+#    #+#             */
/*   Updated: 2021/07/14 15:12:06 by jgomes-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"
#include "../libft/libft.h"

int 	ft_verific_letter(t_print *content, const char *sms, int cont)
{
	if (sms[cont] == 'c')
	 	ft_to_char(content);
	else if (sms[cont] == 's')
	  	ft_to_string(content);
	else if (sms[cont] == 'd' || sms[cont] == 'i')
	 	ft_to_int(content);
	else if (sms[cont] == 'u')
	   	ft_to_unsigned(content);
	else if (sms[cont] == 'x' || sms[cont] == 'X')
 	  	ft_to_hexa(content, sms[cont] - 23);
	else if (sms[cont] == '%')
		ft_to_percent(content);
	else if (sms[cont] == 'p')
		ft_to_pointer(content);
	return (cont);
}

// while n é o cspdiuxX%
int		ft_verific_symb(t_print *content, const char *sms, int cont)// aonde vamos cmc o check, poisção
{
	while (!(ft_isalpha(sms[cont]) || (sms[cont] == '%')))
	{
		if (sms[cont] == '-')
			cont = ft_maybe_tracinho(content, sms, cont);
		else if (sms[cont] == '0')
			cont = ft_maybe_zero(content, sms, cont);
		else if (sms[cont] == '.')
			cont = ft_maybe_precision(content, sms, cont);
		else if (sms[cont] == '*')
			cont = ft_maybe_estrelinha(content, sms, cont);
		else if (ft_isdigit(sms[cont])) //if tem um numero la, define o width
			cont = ft_maybe_width(content, sms, cont);
	}
	ft_verific_letter(content, sms, cont);
	ft_reset(content);
	return (cont);
}
