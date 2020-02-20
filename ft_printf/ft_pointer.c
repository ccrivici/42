/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pointer.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccrivici <ccrivici@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/11 13:52:41 by ccrivici          #+#    #+#             */
/*   Updated: 2020/02/11 20:23:05 by ccrivici         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <unistd.h>
#include <stdarg.h>
#include "structures.h"

static	int		ft_count(unsigned long n)
{
	if (n >= 16)
		return (1 + ft_count(n / 16));
	else
		return (1);
}

static	int		ft_print(int x, char c)
{
	int ret;
	int nb;

	nb = x;
	ret = 0;
	while (nb > 0)
	{
		ret += write(1, &c, 1);
		nb--;
	}
	return (ret);
}

int				ft_pointer(unsigned long n)
{
	int ret;

	ret = 0;
	if (n > 15)
	{
		ret += ft_pointer(n / 16);
		ret += ft_pointer(n % 16);
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

int				ft_putpoint(t_tabla tabla, unsigned long n, int x, int p)
{
	int	ret;
	int	j;

	ret = 0;
	j = 0;
	(n == 0 && tabla.width == 0) ? (x += 1) : 0;
	tabla.aster > 0 && tabla.align == false && tabla.ceros == false
		? ret += ft_print(x, ' ') : 0;
	ret += write(1, "0x", 2);
	tabla.aster > 0 && tabla.align == false && tabla.ceros == true
		? ret += ft_print(x, '0') : 0;
	j = p;
	tabla.width > 0 && tabla.punto == true ? j = tabla.width : 0;
	tabla.width == 0 && tabla.align == false && tabla.punto == true
		? j = 0 : 0;
	tabla.width == 0 && tabla.align == true && tabla.punto == true
		&& tabla.aster > 0 ? ret += (ft_print(tabla.aster, ' ')) : 0;
	tabla.width == 0 ? j = 0 : 0;
	tabla.width > 0 && tabla.align == false && tabla.punto == true
		? ret += ft_print(j, '0') : 0;
	n == 0 && tabla.width == 0 && tabla.punto == true
		? 1 : (ret += ft_pointer(n));
	tabla.align == true && tabla.aster > 0 ? ret += ft_print(x, ' ') : 0;
	return (ret);
}

int				ft_pointer_global(t_tabla tabla, unsigned long n)
{
	int		p;
	int		ret;
	int		x;
	int		j;

	ret = 0;
	p = ft_count(n) + 2;
	if (tabla.width > p)
	{
		x = tabla.aster - (tabla.width);
	}
	else
		x = tabla.aster - (p);
	ret += ft_putpoint(tabla, n, x, p);
	return (ret);
}
