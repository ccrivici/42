/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccrivici <ccrivici@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/09 18:39:09 by ccrivici          #+#    #+#             */
/*   Updated: 2019/11/14 16:27:37 by ccrivici         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	char *i;

	i = 0;
	while (*s)
	{
		if (*s == c)
			i = (char *)s;
		s++;
	}
	if (i)
		return (i);
	if (c == '\0')
		return ((char*)s);
	return (NULL);
}
