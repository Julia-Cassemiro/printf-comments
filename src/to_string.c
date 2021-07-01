/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   to_string.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgomes-c <jgomes-c@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/30 15:31:05 by jgomes-c          #+#    #+#             */
/*   Updated: 2021/07/01 17:53:31 by jgomes-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"
#include "../libft/libft.h"


void	to_string(t_print *content)
{
	char	*s;
	int		count;
	int		len;

	count = 0;
	len = 0;
	s = va_arg(content->args, char *); // Cada chamada para va_arg modifica ap para que a próxima chamada retorne o próximo argumento.
									// O tipo de parâmetro é um nome de tipo de valor que ap aponta. (agr ap é um char *)
	if (s == NULL)
		s = "(null)";
	len = ft_strlen(s); // pega o tamanho da nossa string, qntd de caracteres q vamos imprimir
	if (content->prc > 0 && len > content->prc) // se a minha precisão for maior q o len
		len = content->prc; //nosso len pega o tamanho da precisão
	if (content-> prc > 0) //se tem precisão, mas o len n é maior
		while (s[count])
		{
			content->tl = write(1, &s[count], 1); // escreve s, enqt a precisão é preenchida
			count++;
			content->prc--;
		}
	else //caso n tenha precisão
		while (s[count])
			content->tl = write(1, &s[count++], 1); //digita a string	
}
