
#include "../includes/ft_printf.h"
#include "../libft/libft.h"

int main()
{
    printf(" seu retorno %d\n", printf("|%+.d", 0));
    printf(" seu retorno %d\n", printf("|%+.1d|", 0));
    printf(" seu retorno %d\n", printf("|%-+2.0d|", 1));
    printf(" meu retorno %d\n", ft_printf("|%+.d", 0));
    printf(" meu retorno %d\n", ft_printf("|%+.1d|", 0));
    printf(" meu retorno %d\n", ft_printf("|%-+2.0d|", 1));
    return 0;
}
// gcc -Wall -Wextra -Werror main.c brprint.c ft_lenght.c ft_maybe.c ft_verific.c to_string.c ../libft/ft*]