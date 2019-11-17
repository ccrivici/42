/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcat.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccrivici <ccrivici@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/15 16:34:49 by ccrivici          #+#    #+#             */
/*   Updated: 2019/11/16 14:09:34 by ccrivici         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strcat(const char *dst, const char *src)
{
	size_t			len;
	int				a;
	unsigned char	*str1;
	unsigned char	*str2;

	str1 = (unsigned char*)dst;
	str2 = (unsigned char*)src;
	len = 0;
	a = 0;
	while (str1[len] != '\0')
	{
		len++;
	}
	while (str2[a] != '\0')
	{
		str1[len + a] = str2[a];
		a++;
	}
	str1[len + a] = '\0';
	return ((char *)str1);
}
