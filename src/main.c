
#include "../includes/ft_printf.h"
#include "../libft/libft.h"

int main()
{
	//ft_printf("%s", "0");
//	ft_printf("\n");
//	ft_printf("|%s %s|", "", "");
//	printf("|%s %s|", "", "");
//	ft_printf("\n");
	ft_printf("|%*c%*c|", -10, '0', 10, '1');
	printf("\n|%*c%*c|", -10, '0', 10, '1');

//	ft_printf("\n");
	//ft_printf("teste |%5c|\n", 'a');
	return 0;
}
// gcc -Wall -Wextra -Werror main.c brprint.c ft_lenght.c ft_maybe.c ft_verific.c to_string.c ../libft/ft*