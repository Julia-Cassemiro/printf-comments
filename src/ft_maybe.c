/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_maybe.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgomes-c <jgomes-c@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/29 15:24:52 by jgomes-c          #+#    #+#             */
/*   Updated: 2021/07/01 16:31:52 by jgomes-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/printf.h"
#include "../libft/libft.h"

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

int	ft_maybe_estrelinha(t_print *content, const char *sms, int cont)
{
    cont++;//verifica o proximo
	//se n tem ponto, o * é o width
    if (!(content->pnt))  // ou seja, se não tem ponto, n tem precisão (n tem um tamanho certo para impressão)
		content->wdt = va_arg(content->args, int); //se nao tiver o . ele da pegando o argumento da * e colocando em width
	else
	//caso tenha ponto, o * é a precisão
		content->pnt = va_arg(content->args, int);  // se tem ponto, o * é o argumento da precisão então ele coloca na precisão
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
	if (ft_isdigit(sms[cont])) //if veio o numero depois
	{
		count = ft_atoi(&sms[cont]);
		cont = cont + ft_numlen(count); //o num len retorna a qntd de caracteres certo para impressão
	}
	content->prc = count; //retorna a qnd de caracteres necessarios para imprimir
	if (sms[cont] == '*')
		cont = ft_maybe_estrelinha(content, sms, cont); //ele ve todas as estrelinhas
	while (sms[cont] != '*')
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
	content->wdt = count;
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
	// content->zero = 0;
	while (sms[cont] == '-' || sms[cont] == '0')
		cont++;
	cont = ft_maybe_width(content, sms, cont); //vai la ver se tem width
	return (cont);
}
