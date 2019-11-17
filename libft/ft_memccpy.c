/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccrivici <ccrivici@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/08 19:14:02 by ccrivici          #+#    #+#             */
/*   Updated: 2019/11/16 15:43:27 by ccrivici         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dst, const void *src, int c, size_t n)
{
	unsigned const char	*s;
	unsigned char		*p;
	size_t				x;

	s = src;
	p = dst;
	x = 0;
	while (x < n)
	{
		p[x] = s[x];
		if (s[x] == (unsigned char)c)
			return (dst + x + 1);
		x++;
	}
	return (NULL);
}
