#ifndef PRINTF_H
# define PRINTF_H

# include <unistd.h>
# include <stdlib.h>
# include <string.h>
# include <stdarg.h>
# include <stdio.h>

//CRIA UMA ESTRUTURA IGUAL FOI CRIADO NA GNL
// a gente faz isso pq o print f printa em varios formatos, e são as flags que vão nos proporcionar isso
// essas informações serão usadas pelas flags, mas elas precisam estar em algum lugar (struct)
// portanto vamo criar as struct q mostra as coisas especifiicas

typedef struct s_print			 
{		
	va_list  args;	//conteudo para impressão		  
	int   wdt;	  // size, tamanho, largura, width, wdt
	int   prc;	  // precisão	  
	int   zero;	 // zero	 
	int   pnt;	  // ponto . 
	int   dash;	 // - traço 
	int   tl;	// total_length (return value)	  
	int   sign;	// pos ou neg numero	   
	int   is_zero;	//  numer zero		   
	int   porc;	// %	   
	int   spa;	// space flag ' '	  
}	t_print;

int			ft_printf(const char *sms, ...);
t_print 	*ft_initialise(t_print *arrow);
int			(t_print *content, const char *sms, int cont;

# endif