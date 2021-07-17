
#include "../includes/ft_printf.h"
#include "../libft/libft.h"

int main()
{
    printf(" seu retorno %d", printf("|%+8.5d|", 0));
	printf("\n");
    printf("\n");
    printf("\n");
    printf(" meu retorno %d", ft_printf("|%+8.5d|", 0));
    return 0;
}
// gcc -Wall -Wextra -Werror main.c brprint.c ft_lenght.c ft_maybe.c ft_verific.c to_string.c ../libft/ft*