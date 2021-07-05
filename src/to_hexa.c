/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   to_hexa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgomes-c <jgomes-c@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/05 15:55:46 by jgomes-c          #+#    #+#             */
/*   Updated: 2021/07/05 15:55:52 by jgomes-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"
#include "../libft/libft.h"

void to_hexa(t_print *content, int cont)
{
	unsigned int	x;
	int				len;
	char			*nbr;

	x = va_arg(content->args, unsigned int);
	if (!x) //zero, 0
	{
		ft_update_lenght(content, 1); //ajusta o tamanho a ser escrito
		while (!content->dash && --content->wdt > 0) //n tem traço preenche cm espaço, e depois cm o 0
			{
				content->tl = write (1, " ", 1);
				content->tl = write (1, "0", 1); //escreve o 0
				return;
			}
		content->tl = write (1, "0", 1); //escreve o 0
		while (content->dash && --content->wdt > 0) //e preenche cm espaço ate acabar o wdt
			{
			content->tl = write (1, " ", 1);
			return;
			}
	}
	len = ft_numlen_hexa(x, 16); //pega o tamanho //converter para char
	nbr = (char *)malloc(sizeof(char) * (len + 1)); //malloc cm espaço pro \0
	if (!nbr)
		return ;
	nbr = ft_hexatoi(nbr, x, 16, cont);
	ft_update_lenght(content, len);
	while (nbr && len-- > 0)
		tab->tl += write(1, &num[len], 1);
	free(nbr);
}