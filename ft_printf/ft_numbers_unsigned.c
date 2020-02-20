/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_numbers_unsigned.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccrivici <ccrivici@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/11 13:52:22 by ccrivici          #+#    #+#             */
/*   Updated: 2020/02/11 13:52:22 by ccrivici         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <unistd.h>
#include <stdarg.h>
#include "structures.h"

static	int	ft_count(int n)
{
	int	p;

	p = 0;
	if (n < 0)
	{
		n *= -1;
		if (n >= 10)
			return (1 + ft_count(n / 10));
		else
			return (1);
	}
	else
	{
		if (n >= 10)
			return (1 + ft_count(n / 10));
		else
			return (1);
	}
}

static	int	ft_print(int x, char c)
{
	int ret;
	int nb;

	ret = 0;
	nb = x;
	while (nb > 0)
	{
		ret += write(1, &c, 1);
		nb--;
	}
	return (ret);
}

int			ft_putnbr_unsigned(unsigned int n)
{
	int ret;

	ret = 0;
	if (n >= 10)
	{
		ret += ft_putnbr_unsigned(n / 10);
		ret += ft_putnbr_unsigned(n % 10);
	}
	else
		ret += ft_print(1, n + '0');
	return (ret);
}

int			ft_putun(t_tabla tabla, unsigned int n, int x, int p)
{
	int ret;
	int j;

	j = 0;
	ret = 0;
	n == 0 && tabla.width == 0 ? ret += ft_print(tabla.aster, ' ') : 0;
	tabla.aster > 0 && tabla.align == false && tabla.ceros == false
		&& tabla.width != 0 ? ret += ft_print(x, ' ') : 0;
	n < 0 ? ret += ft_print(1, '-') && (n *= -1) && (p--) : 0;
	tabla.aster > 0 && tabla.align == false && tabla.ceros == true
		? ret += ft_print(x, '0') : 0;
	j = tabla.width - p;
	tabla.width > 0 && tabla.align == false && tabla.punto == true
		? ret += ft_print(j, '0') : 0;
	tabla.width > 0 && tabla.align == true && tabla.punto == true
		? ret += ft_print(j, '0') : 0;
	n == 0 && tabla.width == 0 ? 1 : (ret += ft_putnbr_unsigned(n));
	tabla.align == true && tabla.aster < 0 ? (x = (tabla.aster *= -1) - p) : 0;
	tabla.align == false && tabla.aster < 0 ? (x = (tabla.aster *= -1) - p)
		&& (tabla.align = true) : 0;
	tabla.align == true && tabla.aster > 0 && tabla.width != 0
		? ret += ft_print(x, ' ') : 0;
	return (ret);
}

int			ft_unsigned_global(t_tabla tabla, unsigned int n)
{
	int		p;
	int		ret;
	int		x;
	int		j;

	ret = 0;
	j = 0;
	p = ft_count(n);
	if (tabla.width > 0)
	{
		n < 0 ? x = tabla.aster - (tabla.width + 1) : 0;
		n >= 0 ? x = tabla.aster - tabla.width : 0;
		n < 0 && p > tabla.width ? x = tabla.aster - p : 0;
		n > 0 && p > tabla.width ? x = tabla.aster - p : 0;
	}
	else
		x = tabla.aster - p;
	ret += ft_putun(tabla, n, x, p);
	return (ret);
}
