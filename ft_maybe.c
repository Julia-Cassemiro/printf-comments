/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_maybe.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgomes-c <jgomes-c@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/29 15:24:52 by jgomes-c          #+#    #+#             */
/*   Updated: 2021/07/08 20:17:43 by jgomes-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft.h"

int ft_maybe_zero(t_print *content, const char *sms, int cont)
{
	int count;

	count = 0;
	cont++;
	content->zero = 1;
	if (ft_isdigit(sms[cont]))
	{
		count = ft_atoi(&sms[cont]);
		cont = cont + ft_numlen(count);
	}
	content->wdt = count;
	return (cont);
}

void	ft_check_width(t_print *content)
{
	if (content->wdt < 0)
	{
		content->wdt *= -1;
		content->dash = 1;
		content->zero = 0;
	}
}

int	ft_maybe_estrelinha(t_print *content, const char *sms, int cont)
{
    cont++;//verifica o proximo
	//se n tem ponto, o * é o width
    if (!(content->pnt))  // ou seja, se não tem ponto, n tem precisão (n tem um tamanho certo para impressão)
	{
		content->wdt = va_arg(content->args, int); // ela pega o proximo argumento
		ft_check_width(content);
	}
	else
	//caso tenha ponto, o * é a precisão
	{
		content->prc = va_arg(content->args, int);  // se tem ponto, o * é o argumento da precisão então ele coloca na precisão
		if (content->prc < 0)
			content->pnt = 0;
	}
	if (sms[cont] == '.')
		ft_maybe_precision(content, sms, cont);
	while (sms[cont] == '*')
		cont++;
	return (cont);
}

int	ft_maybe_precision(t_print *content, const char *sms, int cont)
{
	int count;

	count = 0;
	cont++;
	content->pnt = 1;
	while (sms[cont] == '0' || sms[cont] == '-' || sms[cont] == '.')
		cont++;
	if (ft_isdigit(sms[cont])) //if veio o numero depois
	{
		count = ft_atoi(&sms[cont]);
		cont = cont + ft_numlen(count); //o num len retorna a qntd de caracteres certo para impressão
	}
	content->prc = count; //retorna a qnd de caracteres necessarios para imprimir
	if (sms[cont] == '*')
		cont = ft_maybe_estrelinha(content, sms, cont); //ele ve as estrelinhas
	while (sms[cont] == '*')
		cont++;
	return (cont);
}

int	ft_maybe_width(t_print *content, const char *sms, int cont)
{
	int count;

	count = 0;
	if (ft_isdigit(sms[cont]))
	{
		count = ft_atoi(&sms[cont]); //passa a string pra um numero inteiro
		cont = cont + ft_numlen(count); // retorna a qnd de caracteres necessarios para imprimir n
	}
	content->wdt = count; //o nosso wdt fica cm o valor q tem a qntd de caracteres para ser impresso no minimo
	if (sms[cont] == '.')
		cont = ft_maybe_precision(content, sms, cont);
	return (cont);
}

int ft_maybe_tracinho(t_print *content, const char *sms, int cont)
{
	cont++;
	if(content->dash == 1) //o - pode repetir varias vezes
	{
		while (sms[cont] == '-' || sms[cont] == '0')
			cont++;
		return (cont);
	}
	content->dash = 1;
	content->zero = 0;
	while (sms[cont] == '-' || sms[cont] == '0')
		cont++;
	cont = ft_maybe_width(content, sms, cont); //vai la ver se tem width
	return (cont);
}
