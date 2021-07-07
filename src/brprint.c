#include "../includes/ft_printf.h"

t_print *ft_initialise(t_print *arrow)
{
	arrow->wdt = 0;
	arrow->prc = 0;
	arrow->zero = 0;
	arrow->pnt = 0;
	arrow->sign = 0;
	arrow->tl = 0;
	arrow->is_zero = 0;
	arrow->dash = 0;
	arrow->porc = 0;
	return (arrow);
}


int	ft_printf(const char *sms, ...)
{
	t_print		*content;
	int			nothing; //printf retorna um int
	int			count; //sempre usamos um count Julia

	// *primeira coisa q sempre fazemos é conferir se ta certo
    if (sms == NULL)
	  return (-1);
	content = (t_print *)malloc(sizeof(t_print));
	if (content == NULL)
		return (-1);
	ft_initialise(content);
	va_start(content->args, sms); // passamos a variavel arg primeiro, depois o ultimo elemento conhecido em nosso
	count = 0;
	nothing = 0; //precisamos iniciar ambos
	while (sms[count]) // while string não acabou
	{
		if (sms[count] == '%')
			count = ft_verific_symb(content, sms, count + 1);	// ' ', '0', '', '-' ou '.' count + 1 pq ele cmc a verificar depois do %
														// se é um digito
		else
			// se n for o % write o que ta la
			write(1, &sms[count], 1);
	  count++;
	}
	va_end(content->args);
	free(content);
	return (nothing);
}
