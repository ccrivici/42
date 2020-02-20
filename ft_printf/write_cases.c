/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   write_cases.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccrivici <ccrivici@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/11 14:05:51 by ccrivici          #+#    #+#             */
/*   Updated: 2020/02/11 15:06:13 by ccrivici         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "structures.h"

int		write_lastcases(t_tabla tabla, va_list list, char *s, int *i)
{
	int				ret;
	void			*p;
	unsigned int	j;

	ret = 0;
	if (s[*i] == '%')
		ret += ft_putstr_global(tabla, "%");
	else if (s[*i] == 'u')
	{
		j = va_arg(list, unsigned int);
		ret += ft_unsigned_global(tabla, j);
	}
	else if (s[*i] == 'p')
	{
		p = va_arg(list, void *);
		p == NULL ? p = 0 : 0;
		ret += ft_pointer_global(tabla, (unsigned long)p);
	}
	return (ret);
}

int		write_othercases(t_tabla tabla, va_list list, char *s, int *i)
{
	int				ret;
	unsigned int	j;

	ret = 0;
	if (s[*i] == 'c')
	{
		j = va_arg(list, unsigned int);
		ret += ft_putchar_global(tabla, j);
	}
	else if (s[*i] == 'x')
	{
		j = va_arg(list, unsigned int);
		ret += ft_hex_global(tabla, j);
	}
	else if (s[*i] == 'X')
	{
		j = va_arg(list, unsigned int);
		ret += ft_hex_capital_global(tabla, j);
	}
	else
		ret += write_lastcases(tabla, list, s, i);
	return (ret);
}

int		write_cases(t_tabla tabla, va_list list, char *s, int *i)
{
	int		ret;
	int		d;
	char	*string;
	char	a;
	void	*p;

	ret = 0;
	if (s[*i] == 'd' || s[*i] == 'i')
	{
		d = va_arg(list, int);
		ret += ft_putnbr_global(tabla, d);
	}
	else if (s[*i] == 's')
	{
		string = va_arg(list, char *);
		string == NULL ? string = "(null)" : 0;
		ret += ft_putstr_global(tabla, string);
	}
	else
		ret += write_othercases(tabla, list, s, i);
	return (ret);
}
