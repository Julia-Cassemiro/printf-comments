#include "libft.h"

// retorna a qnd de caracteres necessarios para imprimir n
int	ft_numlen(long n)
{
	int	count;

	count = 0;
	if (n <= 0)
	{
		count = count + 1;
		n = n * -1;
	}
	while (n > 0)
	{
		count++;
		n = n / 10;
	}
	return (count);
}

