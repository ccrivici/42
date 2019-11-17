/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccrivici <ccrivici@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/14 15:53:55 by ccrivici          #+#    #+#             */
/*   Updated: 2019/11/14 16:09:47 by ccrivici         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s1)
{
	char *d;

	d = malloc(ft_strlen(s1) + 1);
	if (d != NULL)
		ft_strcpy(d, s1);
	return (d);
}
