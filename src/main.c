
#include "../includes/ft_printf.h"
#include "../libft/libft.h"

int main()
{
    printf(" seu retorno %d\n", printf("|%#10x|", 123));
    printf(" seu retorno %d\n", printf("|%+#10X|", 123));
    printf(" seu retorno %d\n", printf("|%-#10X|", 123));
    printf(" seu retorno %d\n", printf("|%0#10x|", 123));
    printf(" meu retorno %d\n", ft_printf("|%#10x|", 123));
    printf(" meu retorno %d\n", ft_printf("|%+#10X|", 123));
    printf(" meu retorno %d\n", ft_printf("|%-#10X|", 123));
    printf(" meu retorno %d\n", ft_printf("|%0#10x|", 123));
    return 0;
}
// gcc -Wall -Wextra -Werror main.c brprint.c ft_lenght.c ft_maybe.c ft_verific.c to_string.c ../libft/ft*]