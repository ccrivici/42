/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hex.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccrivici <ccrivici@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/11 13:52:08 by ccrivici          #+#    #+#             */
/*   Updated: 2020/02/11 13:52:08 by ccrivici         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <unistd.h>
#include <stdarg.h>
#include "structures.h"

static int	ntohex(unsigned int n)
{
	long int	nb;
	int			i;
	int			temp;
	int			j;
	char		hexa[100];

	i = 0;
	j = 0;
	nb = n;
	if (nb == 0)
		return (1);
	while (nb != 0)
	{
		temp = nb % 16;
		if (temp < 10)
			temp = temp + 48;
		else
			temp = temp + 55;
		hexa[i++] = temp;
		nb = nb / 16;
	}
	return (i);
}

static int	ft_print(int x, char c)
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

int			ft_putnbr_unsigned_hex(unsigned int n)
{
	int ret;

	ret = 0;
	if (n > 15)
	{
		ret += ft_putnbr_unsigned_hex(n / 16);
		ret += ft_putnbr_unsigned_hex(n % 16);
	}
	else if (n == 10)
		ret += ft_print(1, 'a');
	else if (n == 11)
		ret += ft_print(1, 'b');
	else if (n == 12)
		ret += ft_print(1, 'c');
	else if (n == 13)
		ret += ft_print(1, 'd');
	else if (n == 14)
		ret += ft_print(1, 'e');
	else if (n == 15)
		ret += ft_print(1, 'f');
	else
		ret += ft_print(1, n + '0');
	return (ret);
}

int			ft_puth(t_tabla tabla, unsigned int n, int x, int p)
{
	int ret;
	int j;

	ret = 0;
	j = 0;
	n == 0 && tabla.width == 0 ? ret += ft_print(tabla.aster, ' ') : 0;
	tabla.aster > 0 && tabla.align == false && tabla.ceros == false
		&& tabla.width != 0 ? ret += ft_print(x, ' ') : 0;
	n < 0 ? ret += ft_print(1, '-') && (n *= -1) && p-- : 0;
	tabla.aster > 0 && tabla.align == false && tabla.ceros == true
		? ret += ft_print(x, '0') : 0;
	j = tabla.width - p;
	tabla.width > 0 && tabla.align == false && tabla.punto == true
		? ret += ft_print(j, '0') : 0;
	tabla.width > 0 && tabla.align == true && tabla.punto == true
		? ret += ft_print(j, '0') : 0;
	n == 0 && tabla.width == 0 ? 1 : (ret += ft_putnbr_unsigned_hex(n));
	tabla.align == true && tabla.aster > 0 && tabla.width != 0
		? ret += ft_print(x, ' ') : 0;
	return (ret);
}

int			ft_hex_global(t_tabla tabla, unsigned int n)
{
	int		p;
	int		ret;
	int		x;
	int		j;

	ret = 0;
	j = 0;
	p = ntohex(n);
	if (tabla.width > 0)
	{
		n < 0 ? x = tabla.aster - (tabla.width + 1) : 0;
		n >= 0 ? x = tabla.aster - tabla.width : 0;
		n < 0 && p > tabla.width ? x = tabla.aster - p : 0;
		n > 0 && p > tabla.width ? x = tabla.aster - p : 0;
	}
	else
		x = tabla.aster - p;
	ret += ft_puth(tabla, n, x, p);
	return (ret);
}
