
#include "../includes/ft_printf.h"
#include "../libft/libft.h"

int main()
{
    printf(" seu retorno %d\n", printf("|%0 1d|", 0));
    printf(" seu retorno %d\n", printf("|%+.2d|", 0));
    printf(" seu retorno %d\n", printf("|%0+1.2d|", 0));
    printf(" meu retorno %d\n", ft_printf("|%0 1d|", 0));
    printf(" meu retorno %d\n", ft_printf("|%+.2d|", 0));
    printf(" meu retorno %d\n", ft_printf("|%0+1.2d|", 0));
    return 0;
}
// gcc -Wall -Wextra -Werror main.c brprint.c ft_lenght.c ft_maybe.c ft_verific.c to_string.c ../libft/ft*]