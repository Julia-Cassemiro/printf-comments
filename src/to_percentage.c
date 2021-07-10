/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   to_percentage.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgomes-c <jgomes-c@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/09 22:07:08 by jgomes-c          #+#    #+#             */
/*   Updated: 2021/07/09 22:10:52 by jgomes-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"
#include "../libft/libft.h"

void ft_to_percent(t_print *content)
{
	if (content->porc)
		content->zero = 1;
	while (content->zero && !content->dash && --content->wdt > 0)
		content->tl += write(1, "0", 1);
	while (!content->dash && --content->wdt > 0)
		content->tl += write(1, " ", 1);
	content->tl += write(1, "%", 1);
	while (content->dash && --content->wdt > 0)
		content->tl += write(1, " ", 1);
}