/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   to_string.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgomes-c <jgomes-c@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/30 15:31:05 by jgomes-c          #+#    #+#             */
/*   Updated: 2021/07/08 04:54:09 by jgomes-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"
#include "../libft/libft.h"

int	ft_lenght_string(char *s, t_print *content, int len)
{
	if (content->prc > 0 && len > content->prc)
		len = content->prc;
	len = ft_strlen(s);
	return (len);
}

void	ft_write_nothing(t_print *content)
{	
	while (content->wdt--)
		content->tl += write(1, " ", 1);
}

void	ft_to_string(t_print *content)
{
	char	*s;
	int		count;
	int		len;

	count = 0;
	len = 0;
	s = va_arg(content->args, char *); // Cada chamada para va_arg modifica ap para que a próxima chamada retorne o próximo argumento.
									// O tipo de parâmetro é um nome de tipo de valor que ap aponta. (agr ap é um char *)
	if (!s)
		s = "(null)";
	if (content->pnt == 1 && content->prc == 0) //se tem um ponto, mas nenhuma precisão foi tomada, escreve nada
		return (ft_write_nothing(content));
	len = ft_lenght_string(s, content, len); // ajusta o len da nossa string
	if (!content->dash && content->wdt > len) //se n tem a flag -, digita antes
		ft_right_string(content, len);
	if (content-> prc > 0) //se tem precisão
		while (s[count] && content->prc--)
			content->tl = write(1, &s[count++], 1); // digita a string, enqt a precisão é preenchida
	else //caso n tenha precisão
		while (s[count])
			content->tl = write(1, &s[count++], 1); //digita a string
	if (content->dash) // se tem a flag -, é necessario digitar " ", só depois da string ja estar la
		while (content->wdt-- > len)
			content->tl = write(1, " ", 1);
	// if !-, fica do lado direito
	// if -, fica do lado esquerdo
}
