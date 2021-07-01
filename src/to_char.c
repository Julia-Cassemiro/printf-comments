/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   to_char.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgomes-c <jgomes-c@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/29 21:21:30 by jgomes-c          #+#    #+#             */
/*   Updated: 2021/07/01 17:53:24 by jgomes-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"
#include "../libft/libft.h"

void	to_char(t_print *content)
{
	char	a;

	//estamos passando um argumento
	a = va_arg(content->args, int); // Cada chamada para va_arg modifica ap para que a próxima chamada retorne o próximo argumento
									// O tipo de parâmetro é um nome de tipo de valor que ap aponta.
	content->tl = + write(1, &a, 1);
}
