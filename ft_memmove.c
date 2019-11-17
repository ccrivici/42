/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccrivici <ccrivici@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/08 19:15:24 by ccrivici          #+#    #+#             */
/*   Updated: 2019/11/13 19:40:31 by ccrivici         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	size_t				a;
	unsigned char		*ptr;
	const unsigned char	*ptr2;

	if (dst == NULL && src == NULL)
		return (NULL);
	ptr = (unsigned char*)dst;
	ptr2 = (unsigned char*)src;
	a = 0;
	if (ptr2 < ptr)
		while (++a <= len)
		{
			ptr[len - a] = ptr2[len - a];
		}
	else
	{
		while (len-- > 0)
		{
			*(ptr++) = *(ptr2++);
		}
	}
	return (dst);
}
