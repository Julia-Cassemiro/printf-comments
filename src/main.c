
#include "../includes/ft_printf.h"
#include "../libft/libft.h"

int main()
{
    printf(" euzinha %d\n", ft_printf("|% 1.0d|", 0));
    printf(" original %d\n", printf("|% 1.0d|", 0));
    printf("\n");
    printf(" euzinha %d\n", ft_printf("|%+1.0d|", 0));
    printf(" original %d\n", printf("|%+1.0d|", 0));
    printf("\n");
    printf(" euzinha %d\n", ft_printf("|%0 1.0d|", 0));
    printf(" original %d\n", printf("|%0 1.0d|", 0));
    printf("\n");
    printf(" euzinha %d\n", ft_printf("|%- 1.0d|", 0));
    printf(" original %d\n", printf("|%- 1.0d|", 0));
    printf("\n");
    printf(" euzinha %d\n", ft_printf("|%0+1.0d|", 0));
    printf(" original %d\n", printf("|%0+1.0d|", 0));
    printf("\n");
    printf(" euzinha %d\n", ft_printf("|%-+1.0d|", 0));
    printf(" original %d\n", printf("|%-+1.0d|", 0));

    return 0;
}
// gcc -Wall -Wextra -Werror main.c brprint.c ft_lenght.c ft_maybe.c ft_verific.c to_string.c ../libft/ft*]