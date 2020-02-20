/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   structures.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccrivici <ccrivici@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/11 15:11:14 by ccrivici          #+#    #+#             */
/*   Updated: 2020/02/11 15:11:17 by ccrivici         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCTURES_H
# define STRUCTURES_H

# include <stdio.h>
# include <unistd.h>
# include <stdarg.h>
# include <stdbool.h>

typedef	struct	s_tabla
{
	int			espacios;
	bool		ceros;
	bool		align;
	bool		punto;
	int			aster;
	int			width;
}				t_tabla;

int				ft_printf(char *s, ...);
int				write_cases(t_tabla tabla, va_list list, char *s, int *i);
int				ft_putnbr(int n);
int				ft_putchar(char c);
int				ft_putnstr(char *s, int n);
int				ft_putnbr_unsigned(unsigned int n);
int				ft_putnbr_unsigned_hex(unsigned int n);
int				ft_putnbr_unsigned_hex_capital(unsigned int n);
int				ft_pointer(unsigned long n);
t_tabla			get_flags(va_list list, char *s, int *i);
int				ft_putnbr_global(t_tabla tabla, int n);
int				ft_putstr_global(t_tabla tabla, char *s);
int				ft_putchar_global(t_tabla tabla, char c);
int				ft_unsigned_global(t_tabla tabla, unsigned int c);
int				ft_hex_global(t_tabla tabla, unsigned int n);
int				ft_hex_capital_global(t_tabla tabla, unsigned int n);
int				ft_write(char c);
int				ft_pointer_global(t_tabla tabla, unsigned long n);

#endif
