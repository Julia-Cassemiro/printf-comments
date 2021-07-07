/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   to_char.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgomes-c <jgomes-c@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/29 21:21:30 by jgomes-c          #+#    #+#             */
/*   Updated: 2021/07/07 02:52:44 by jgomes-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"
#include "../libft/libft.h"

void	ft_to_char(t_print *content)
{
	char	c;

	//estamos passando um argumento
	c = va_arg(content->args, int); // Cada chamada para va_arg modifica ap para que a próxima chamada retorne o próximo argumento.
									// O tipo de parâmetro é um nome de tipo de valor que ap aponta.
	ft_update_lenght(content, 1); //ajusta o wdt e a prc
	if (content->wdt && !content->dash) //n verifica prc, pq c não tem prc
	{
		while (content->wdt-- > 0)
			content->tl += write(1, " ", 1); //se n tem traço, fica pro lado direito
	}
	content->tl += write(1, &c, 1); //mas se tem traço, primeiro escreve
	if (content->wdt && content->dash) //n verifica prc, pq c não tem prc
	{
		while (content->wdt-- > 0)
			content->tl += write(1, " ", 1); //se tem traço, fica pro lado esquerdo
	}
}
