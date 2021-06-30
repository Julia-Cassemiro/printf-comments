/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_verific.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgomes-c <jgomes-c@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/29 13:40:38 by jgomes-c          #+#    #+#             */
/*   Updated: 2021/06/29 20:54:16 by jgomes-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "print.f"

int 	ft_verific_letter(va_list *content, const char *sms, int cont)
{
	if (sms[cont] == 'c')
		to_char(content);
}

// while n é o udcsupxX%
int		ft_verific_symb(va_list *content, const char *sms, int cont)
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
		if (ft_isdigit(sms[cont])) 
			cont = ft_maybe_width(content, sms, cont);
		
	}
	ft_verific_letter(content, sms, cont);
	ft_reset(content);
	return (cont);
}
