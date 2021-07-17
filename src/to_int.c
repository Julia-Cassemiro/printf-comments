/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   to_int.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgomes-c <jgomes-c@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/05 15:55:56 by jgomes-c          #+#    #+#             */
/*   Updated: 2021/07/16 23:54:02 by jgomes-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"
#include "../libft/libft.h"

int	check_sign(t_print *content, int i)
{
	content->sign = 1;
	content->spa = 0;
	return (i * -1);
}

void	ft_write_zero(t_print *content)
{
	content->is_zero = 1; //zero
	if ((content->wdt && content->zero) || content->pnt) //se tiver . ou 0
	{
		ft_change_zero(content); //retorna diferente
		return ;
	}
	ft_update_lenght(content, 1);
	if (content->plus)
		content->tl += write (1, "+", 1);
	if (content->spa)
		content->wdt -= content->spa;
	while (content->spa || (!content->dash && --content->wdt > 0))
	{
		content->tl += write(1, " ", 1);
		content->spa = 0;
	}
	content->tl += write(1, "0", 1);
	while (content->dash && --content->wdt > 0)
		content->tl += write(1, " ", 1);
}


void	ft_to_int(t_print *content)
{
	int count;
	int i;
	int len;
	char *nbr;

	count = 0;
	i = va_arg(content->args, int);
	if (!i) //zero, 0
	{
		ft_write_zero(content);
		return ;
	}
	if (i < 0)
		i = check_sign(content, i);
	nbr = ft_itoa(i);  //transforma pra alphanumeric
	if (!nbr)
		return;
	len = ft_strlen(nbr);
	ft_update_lenght(content, len); //confere tamanho q vai ser escrito wdt, prc
	ft_right(content);
	while (i && nbr[count])
		content->tl += write (1, &nbr[count++], 1);
	ft_left(content);
	free(nbr);
}
