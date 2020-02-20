/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_charc.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccrivici <ccrivici@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/11 13:51:51 by ccrivici          #+#    #+#             */
/*   Updated: 2020/02/11 16:05:07 by ccrivici         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <unistd.h>
#include <stdarg.h>
#include "structures.h"

int		ft_putchar(char c)
{
	int ret;

	ret = 0;
	ret += write(1, &c, 1);
	return (ret);
}

int		ft_print_o(int x, char c)
{
	int ret;
	int nb;

	ret = 0;
	nb = x;
	while (nb > 0)
	{
		ret += ft_putchar(c);
		nb--;
	}
	return (ret);
}

int		ft_putchar_o(t_tabla tabla, char *str)
{
	int ret;

	ret = 0;
	tabla.aster > 0 && tabla.align == false
		? ret += ft_print_o((tabla.aster - 1), ' ') : 0;
	ret += ft_putchar('\0');
	tabla.aster > 0 && tabla.align == true
		? ret += ft_print_o((tabla.aster - 1), ' ') : 0;
	return (ret);
}

int		ft_putchar_global(t_tabla tabla, char c)
{
	int		ret;
	char	str[2];

	ret = 0;
	if (c != '\0')
	{
		str[0] = c;
		str[1] = '\0';
		ret += ft_putstr_global(tabla, str);
	}
	else
	{
		str[0] = '\0';
		ret += ft_putchar_o(tabla, str);
	}
	return (ret);
}
