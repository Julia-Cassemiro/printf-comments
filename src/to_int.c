/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   to_int.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgomes-c <jgomes-c@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/05 15:55:56 by jgomes-c          #+#    #+#             */
/*   Updated: 2021/07/07 02:26:11 by jgomes-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"
#include "../libft/libft.h"

void	check_sign(t_print *content, int i)
{
	int	count;
	//int len;
	char *nbr;
	count = 0;
	content->sign = 1;
	i = i * -1;
	nbr = ft_itoa(i); //transforma pra alphanumeric
	//len = ft_strlen(nbr);
	//ft_update_lenght(content, len); //confere tamanho q vai ser escrito wdt, prc
	write (1, "-", 1);
	while (i && nbr[count])
		content->tl = write (1, &nbr[count++], 1);
}

void	ft_to_int(t_print *content)
{
	int count;
	int i;
	//int len;
	char *nbr;

	count = 0;
	i = va_arg(content->args, int);
	if (!i) //zero, 0
	{
		//ft_update_lenght(content, 1); //ajusta o tamanho a ser escrito
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
	if (i < 0)
	{
		check_sign(content, i);
		return;
	}
	nbr = ft_itoa(i); //transforma pra alphanumeric
	if (!nbr)
		return;
	//len = ft_strlen(nbr);
	//ft_update_lenght(content, len); //confere tamanho q vai ser escrito wdt, prc
	while (i && nbr[count])
		content->tl = write (1, &nbr[count++], 1);
	free(nbr);
}
