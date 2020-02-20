/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccrivici <ccrivici@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/11 13:52:54 by ccrivici          #+#    #+#             */
/*   Updated: 2020/02/11 13:52:54 by ccrivici         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "structures.h"

static int		ft_strlen(char *s)
{
	int i;

	i = 0;
	while (s[i] != '\0')
		i++;
	return (i);
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

int				ft_putnstr(char *s, int n)
{
	int i;
	int ret;

	ret = 0;
	i = 0;
	while (s[i] != '\0' && i < n)
	{
		ret += write(1, &s[i], 1);
		i++;
	}
	return (ret);
}

int				ft_puts(t_tabla tabla, char *s, int p, int x)
{
	int ret;
	int j;

	j = 0;
	ret = 0;
	tabla.aster > 0 && tabla.align == false
		&& tabla.ceros == false ? ret += ft_print(x, ' ') : 0;
	tabla.aster > 0 && tabla.align == false && tabla.ceros == true
		? ret += ft_print(x, '0') : 0;
	j = p;
	tabla.width > 0 && tabla.punto == true
		? j = tabla.width : 0;
	tabla.width == 0 && tabla.align == false && tabla.punto == true
		? j = 0 : 0;
	tabla.width == 0 && tabla.align == true && tabla.punto == true
		&& tabla.aster > 0 ? ret += (ft_print(tabla.aster, ' ')) : 0;
	tabla.width == 0 ? j = 0 : 0;
	ret += ft_putnstr(s, j);
	tabla.aster < 0 ? tabla.align = true : 0;
	tabla.aster < 0 ? x = (tabla.aster * -1) : 0;
	tabla.align == true && tabla.aster < 0 ? (x = (tabla.aster *= -1) - p) : 0;
	tabla.align == true && tabla.aster > 0 && tabla.width != 0
		? ret += ft_print(x, ' ') : 0;
	return (ret);
}

int				ft_putstr_global(t_tabla tabla, char *s)
{
	int		p;
	int		ret;
	int		x;
	int		j;

	ret = 0;
	j = 0;
	p = ft_strlen(s);
	if (tabla.width >= 0)
	{
		tabla.width >= p ? x = tabla.aster - p : 0;
		tabla.width < p ? x = tabla.aster - tabla.width : 0;
	}
	else
		x = tabla.aster - p;
	ret += ft_puts(tabla, s, p, x);
	return (ret);
}
