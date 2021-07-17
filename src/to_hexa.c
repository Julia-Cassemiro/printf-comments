/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   to_hexa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgomes-c <jgomes-c@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/05 15:55:46 by jgomes-c          #+#    #+#             */
/*   Updated: 2021/07/17 15:11:36 by jgomes-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"
#include "../libft/libft.h"


void	ft_right_hexa(t_print *content, int cont)
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
		if (content->hash && cont + 23 == 'X')
			content->tl += write(1, "0X", 2);
		else
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
		if (content->hash && cont + 23 == 'X')
			content->tl += write(1, "0X", 2);
		else
			content->tl += write(1, "0x", 2);
	}
	while (--content->prc > -1)
		content->tl += write(1, "0", 1);
}

void ft_to_hexa(t_print *content, int cont)
{
	unsigned int	x;
	int				len;
	char			*nbr;

	x = va_arg(content->args, unsigned int);
	if (!x) //zero, 0
	{
		content->hash = 0;
		ft_write_zero(content);
		return ;
	}
	len = ft_numlen_base(x, 16); //pega o tamanho //converter para char
	nbr = (char *)malloc(sizeof(char) * (len + 1)); //malloc cm espaço pro \0
	if (!nbr)
		return ;
	nbr = ft_hexatoi(nbr, x, 16, cont);
	ft_update_lenght(content, len);
	ft_right_hexa(content, cont);
	while (nbr && len-- > 0)
		content->tl += write(1, &nbr[len], 1);
	ft_left(content);
	free(nbr);
}
