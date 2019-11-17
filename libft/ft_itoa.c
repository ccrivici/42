/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccrivici <ccrivici@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/16 15:52:19 by ccrivici          #+#    #+#             */
/*   Updated: 2019/11/16 16:10:49 by ccrivici         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_itoa_length(int c)
{
	int i;
	int neg;

	i = 1;
	neg = 0;
	if (c < 0)
	{
		c = -c;
		neg = 1;
	}
	while (c > 9)
	{
		c = c / 10;
		i++;
	}
	return (i + neg + 1);
}

char		*ft_itoa(int c)
{
	char	*str;
	int		length;
	int		neg;

	neg = 0;
	if (c == -2147483648)
		return (ft_strdup("-2147483648"));
	length = ft_itoa_length(c);
	str = (char*)malloc(sizeof(*str) * (length));
	if (str == NULL)
		return (NULL);
	str[--length] = '\0';
	if (c < 0)
	{
		c = -c;
		neg = 1;
	}
	while (length--)
	{
		str[length] = (c % 10) + '0';
		c = c / 10;
	}
	if (neg)
		str[0] = '-';
	return (str);
}
