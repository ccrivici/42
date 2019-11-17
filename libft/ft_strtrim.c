/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccrivici <ccrivici@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/15 17:44:36 by ccrivici          #+#    #+#             */
/*   Updated: 2019/11/17 14:49:17 by ccrivici         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static	char	ft_strncpy(char *dst, char *src, unsigned int n)
{
	unsigned int i;

	i = 0;
	while (src[i] != 0 && i < n)
	{
		dst[i] = src[i];
		i++;
	}
	while (i < n)
	{
		dst[i] = 0;
		i++;
	}
	return (*dst);
}

char			*ft_strtrim(const char *s1, const char *set)
{
	int		a;
	int		b;
	char	*s2;

	a = 0;
	if (s1 == 0)
		return (0);
	while (ft_strchr(set, s1[a]) && s1[a] != 0)
		a++;
	b = ft_strlen(s1) - a;
	if (b != 0)
	{
		while (ft_strchr(set, s1[b + a - 1]) && a < b - 1)
			b--;
	}
	if (!(s2 = (char*)malloc(sizeof(char) * (b + 1))))
		return (0);
	ft_strncpy(s2, &((char *)s1)[a], b);
	s2[b] = 0;
	return (s2);
}
