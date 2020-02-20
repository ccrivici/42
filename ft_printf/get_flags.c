/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_flags.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccrivici <ccrivici@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/11 13:53:01 by ccrivici          #+#    #+#             */
/*   Updated: 2020/02/11 13:53:01 by ccrivici         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "structures.h"
#include <unistd.h>

int			ft_atoi(const char *str, int *i)
{
	int nb;

	nb = 0;
	while (str[*i] >= '0' && str[*i] <= '9')
	{
		nb = nb * 10 + (str[*i] - '0');
		*i += 1;
	}
	*i -= 1;
	return (nb);
}

t_tabla		init_tabla(t_tabla tabla)
{
	tabla.espacios = 0;
	tabla.ceros = false;
	tabla.align = false;
	tabla.punto = false;
	tabla.aster = 0;
	tabla.width = -1;
	return (tabla);
}

t_tabla		flags_punto_true(t_tabla tabla, va_list list, char *s, int *i)
{
	int k;

	k = 0;
	if (s[*i] == '-')
	{
		tabla.align = true;
		tabla.ceros = false;
	}
	if (s[*i] == '*')
	{
		k = va_arg(list, int);
		tabla.width = k;
	}
	else if (s[*i] >= '0' && s[*i] <= '9')
	{
		k = ft_atoi(s, i);
		tabla.width = k;
	}
	return (tabla);
}

t_tabla		flags_punto_false(t_tabla tabla, va_list list, char *s, int *i)
{
	int	j;

	j = 0;
	if (s[*i] == '0')
		tabla.ceros = true;
	else if (s[*i] == '-')
	{
		tabla.align = true;
		tabla.ceros = false;
	}
	else if (s[*i] == '*')
	{
		j = va_arg(list, int);
		tabla.aster = j;
	}
	else if (s[*i] > '0' && s[*i] <= '9')
	{
		j = ft_atoi(s, i);
		tabla.aster = j;
	}
	return (tabla);
}

t_tabla		get_flags(va_list list, char *s, int *i)
{
	t_tabla		tabla;

	tabla = init_tabla(tabla);
	*i += 1;
	while (s[*i] == '.' || s[*i] == '0' || s[*i] == '*' || s[*i] == '-'
			|| (s[*i] >= '0' && s[*i] <= '9'))
	{
		if (s[*i] == '.')
		{
			tabla.punto = true;
			tabla.ceros = false;
			tabla.width = 0;
		}
		else if (tabla.punto == false)
			tabla = flags_punto_false(tabla, list, s, i);
		else if (tabla.punto == true)
			tabla = flags_punto_true(tabla, list, s, i);
		*i += 1;
	}
	return (tabla);
}
