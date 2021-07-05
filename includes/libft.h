/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgomes-c <jgomes-c@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/18 09:37:41 by jgomes-c          #+#    #+#             */
/*   Updated: 2021/05/18 09:37:42 by jgomes-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <unistd.h>
# include <stdlib.h>
# include <stdarg.h>
# include <stdio.h>
# include <limits.h>


typedef struct s_list
{
	void			*content;
	struct s_list	*next;
}					t_list;

int			ft_atoi (const char *str);
int			ft_isalpha (int c);
int			ft_isdigit(int c);
int			ft_numlen(long n);
size_t		ft_strlen(const char *str);
char		*ft_itoa(int n);
char		*ft_utoa(unsigned int n);
int			ft_numlen_base(unsigned long n, int base);
char		*ft_hexatoi(char *str, unsigned long n, int base, int c);


#endif