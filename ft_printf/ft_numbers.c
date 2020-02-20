/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_numbers.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccrivici <ccrivici@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/11 13:52:28 by ccrivici          #+#    #+#             */
/*   Updated: 2020/02/11 15:12:02 by ccrivici         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "structures.h"

static int		ft_count(int n)
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

static int		ft_print(int x, char c)
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

int				ft_putnbr(int n)
{
	int ret;

	ret = 0;
	if (n == -2147483648)
	{
		ret += write(1, "2", 1);
		n = 147483648;
	}
	if (n >= 10)
	{
		ret += ft_putnbr(n / 10);
		ret += ft_putnbr(n % 10);
	}
	else
		ret += ft_print(1, n + '0');
	return (ret);
}

static int		ft_put(t_tabla tabla, int n, int p, int x)
{
	int ret;
	int j;
	int nb;

	nb = n;
	j = 0;
	ret = 0;
	n < 0 ? ret += ft_print(1, '-') && (n *= -1) && (p--) : 0;
	tabla.aster > 0 && tabla.align == false && tabla.ceros == true
		? ret += ft_print(x, '0') : 0;
	j = tabla.width - p;
	tabla.width > 0 && tabla.align == false && tabla.punto == true
		? ret += ft_print(j, '0') : 0;
	tabla.width > 0 && tabla.align == true && tabla.punto == true
		? ret += ft_print(j, '0') : 0;
	n == 0 && tabla.width == 0 ? 1 : (ret += ft_putnbr(n));
	tabla.align == false && tabla.aster < 0 && nb < 0
		? (x = (tabla.aster * -1) - (p + 1)) : 0;
	tabla.align == false && tabla.aster < 0 && nb < 0 ? tabla.align = true : 0;
	tabla.align == true && tabla.aster < 0 && nb > 0
		? (x = (tabla.aster *= -1) - (p)) : 0;
	tabla.align == false && tabla.aster < 0 ? (x = (tabla.aster *= -1) - (p))
		&& (tabla.align = true) : 0;
	tabla.align == true && tabla.width != 0 ? ret += ft_print(x, ' ') : 0;
	return (ret);
}

int				ft_putnbr_global(t_tabla tabla, int n)
{
	int		p;
	int		ret;
	int		x;

	ret = 0;
	p = ft_count(n);
	p += n < 0 ? 1 : 0;
	if (tabla.width > 0)
	{
		n < 0 ? x = (tabla.aster) - (tabla.width + 1) : 0;
		n >= 0 ? x = (tabla.aster) - (tabla.width) : 0;
		n < 0 && p > tabla.width ? x = tabla.aster - p : 0;
		n > 0 && p > tabla.width ? x = tabla.aster - p : 0;
	}
	else
		x = tabla.aster - p;
	n == 0 && tabla.width == 0 ? ret += ft_print(tabla.aster, ' ') : 0;
	tabla.aster > 0 && tabla.align == false && tabla.width != 0
		&& tabla.ceros == false ? ret += ft_print(x, ' ') : 0;
	ret += ft_put(tabla, n, p, x);
	return (ret);
}
