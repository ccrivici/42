/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccrivici <ccrivici@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/08 16:36:07 by ccrivici          #+#    #+#             */
/*   Updated: 2019/11/14 13:57:09 by ccrivici         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	unsigned char *ptr;
	unsigned char *ptr2;

	ptr = (unsigned char*)dst;
	ptr2 = (unsigned char*)src;
	if (ptr || ptr2)
	{
		while (n-- > 0)
		{
			*(ptr++) = *(ptr2++);
		}
	}
	return (dst);
}
