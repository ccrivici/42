/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccrivici <ccrivici@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/12 16:38:21 by ccrivici          #+#    #+#             */
/*   Updated: 2019/11/14 13:57:03 by ccrivici         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	size_t			k;
	unsigned char	*a;

	k = 0;
	a = (unsigned char*)s;
	while (++k <= n)
		if (*(a++) == (unsigned char)c)
			return ((void*)--a);
	return (0);
}
