/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jebae <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/03 18:51:02 by jebae             #+#    #+#             */
/*   Updated: 2019/10/24 15:15:24 by jebae            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dst, const void *src, int c, size_t n)
{
	unsigned char	*p_src;
	unsigned char	*p_dst;
	unsigned char	ch;

	if (dst == NULL || src == NULL)
		return (dst);
	p_src = (unsigned char *)src;
	p_dst = (unsigned char *)dst;
	ch = (unsigned char)c;
	while (n-- > 0)
	{
		*p_dst = *p_src;
		if (*p_src == ch)
			return (p_dst + 1);
		p_dst++;
		p_src++;
	}
	return (NULL);
}
