#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <unistd.h>
# include <stdlib.h>
# include <stdarg.h>
# include <stdio.h>
#include "libft.h"

//CRIA UMA ESTRUTURA IGUAL FOI CRIADO NA GNL
// a gente faz isso pq o print f printa em varios formatos, e são as flags que vão nos proporcionar isso
// essas informações serão usadas pelas flags, mas elas precisam estar em algum lugar (struct)
// portanto vamo criar as struct q mostra as coisas especifiicas

typedef struct s_print			 
{		
	va_list  args;	//conteudo para impressão		  
	int   wdt;	  // size, tamanho, largura, width, wdt
	int   prc;	  // precisão	  
	int   zero;	 // veio zero	 
	int   pnt;	  // ponto . 
	int   dash;	 // - traço 
	int   tl;	// total_length (return value)	  
	int   sign;	// pos ou neg numero	   
	int   is_zero;	//  numer zero		   
	int   porc;	// %	   
}	t_print;

int		ft_printf(const char *sms, ...);
t_print *ft_initialise(t_print *arrow);
int		ft_verific_symb(t_print *content, const char *sms, int cont);
int 	ft_verific_letter(t_print *content, const char *sms, int cont);
int 	ft_maybe_zero(t_print *content, const char *sms, int cont);
int		ft_maybe_width(t_print *content, const char *sms, int cont);
int 	ft_maybe_tracinho(t_print *content, const char *sms, int cont);
int		ft_maybe_precision(t_print *content, const char *sms, int cont);
int		ft_maybe_estrelinha(t_print *content, const char *sms, int cont);
void	to_char(t_print *content);
void	to_string(t_print *content);
void	to_int(t_print *content);
void 	to_hexa(t_print *content, int cont);
void	to_unsigned(t_print *content);
void	check_sign(t_print *content, int i);


# endif