/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccrivici <ccrivici@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/12 16:04:17 by ccrivici          #+#    #+#             */
/*   Updated: 2019/11/13 20:33:54 by ccrivici         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t cont;

	cont = 0;
	if (n == 0)
		return (0);
	while (s1[cont] && s2[cont] && s1[cont] == s2[cont] && cont < n - 1)
		cont++;
	return ((unsigned char)s1[cont] - (unsigned char)s2[cont]);
}
