/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   to_unsigned.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgomes-c <jgomes-c@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/05 14:51:35 by jgomes-c          #+#    #+#             */
/*   Updated: 2021/07/05 16:31:19 by jgomes-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"
#include "../libft/libft.h"

void	to_unsigned(t_print *content)
{
	int count;
	unsigned int u;
	int len;
	char *nbr;

	count = 0;
	u = va_arg(content->args, int);
	if (!u) //zero, 0
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
	nbr = ft_utoa(u); //transforma pra alphanumeric
	if (!nbr)
		return ;
	len = ft_strlen(u);
	ft_update_lenght(content, len); //confere tamanho q vai ser escrito wdt, prc
	while (nbr[count])
		content->tl = write (1, &nbr[count++], 1);
	free(nbr);
}
