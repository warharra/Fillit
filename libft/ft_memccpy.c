/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: warharra <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/03 12:49:24 by warharra          #+#    #+#             */
/*   Updated: 2019/04/19 10:18:33 by warharra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dest, const void *src, int c, size_t n)
{
	char*cp_dest;
	char*cp_src;
	int i;

	i = 0;
	cp_dest = (char*)dest;
	cp_src = (char*)src;
	if (n == 0)
		return (NULL);
	while (i < (int)n)
	{
		cp_dest[i] = cp_src[i];
		if (cp_src[i] == (char)c)
		{
			i = i + 1;
			return (&dest[i]);
		}
		i++;
	}
	return (NULL);
}
