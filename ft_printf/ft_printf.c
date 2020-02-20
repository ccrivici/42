/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccrivici <ccrivici@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/11 13:52:46 by ccrivici          #+#    #+#             */
/*   Updated: 2020/02/11 20:41:49 by ccrivici         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "structures.h"
#include <stdlib.h>
#include <stdio.h>

int		ft_printf(char *s, ...)
{
	va_list	list;
	t_tabla	tabla;
	int		i;
	int		ret;

	i = 0;
	ret = 0;
	va_start(list, s);
	while (s[i] != '\0')
	{
		if (s[i] == '%')
		{
			tabla = get_flags(list, s, &i);
			ret += write_cases(tabla, list, s, &i);
		}
		else
			ret += write(1, &s[i], 1);
		if (s[i] != '\0')
			i++;
	}
	va_end(list);
	return (ret);
}
