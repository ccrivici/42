/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccrivici <ccrivici@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/12 14:12:24 by ccrivici          #+#    #+#             */
/*   Updated: 2019/11/14 13:55:30 by ccrivici         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize)
{
	size_t a;

	a = 0;
	if (!dst || !src)
		return (0);
	while (src[a] != '\0' && dstsize > 1)
	{
		dst[a] = src[a];
		a++;
		dstsize--;
	}
	if (dstsize > 0)
		dst[a] = '\0';
	return (ft_strlen(src));
}
