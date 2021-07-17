
#include "../includes/ft_printf.h"
#include "../libft/libft.h"

int main()
{
    printf(" seu retorno %d", printf("|% 7d|", 33));
	printf("\n");
    printf("\n");
    printf("\n");
    printf(" meu retorno %d", ft_printf("|% 7d|", 33));
    //ft_printf("teste |%5c|\n", 'a');
    return 0;
}
// gcc -Wall -Wextra -Werror main.c brprint.c ft_lenght.c ft_maybe.c ft_verific.c to_string.c ../libft/ft*