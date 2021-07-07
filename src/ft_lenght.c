/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lenght.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgomes-c <jgomes-c@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/29 18:32:31 by jgomes-c          #+#    #+#             */
/*   Updated: 2021/07/07 02:38:35 by jgomes-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"
#include "../libft/libft.h"

void	ft_update_lenght(t_print *content, int len)
{
	if (content->sign)
	{
		if (content->wdt)
			content->wdt -= 1;
	}
	if (content->prc > 0)
		content->zero = 0;
	if (content->wdt && content->wdt >= content->prc)
	{
		if (content->prc > len)
			content->prc -= len;
		else
			content->prc = 0;
		if (!content->is_zero)
			content->wdt = content->wdt - content->prc - len;
	}
	else if (content->prc > content->wdt)
	{
		content->wdt = 0;
		content->prc -= len;
	}
}