/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jebae <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/03 20:30:57 by jebae             #+#    #+#             */
/*   Updated: 2019/04/03 20:30:58 by jebae            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	compare_by_1byte(unsigned char *s1, unsigned char *s2, size_t n)
{
	while (n-- > 0)
	{
		if (*s1 != *s2)
			return (*s1 - *s2);
		s1++;
		s2++;
	}
	return (0);
}

int		ft_memcmp(const void *s1, const void *s2, size_t n)
{
	unsigned long	*p1;
	unsigned long	*p2;
	size_t			quotient;

	quotient = n / sizeof(unsigned long);
	n %= sizeof(unsigned long);
	if (quotient > 0)
	{
		p1 = (unsigned long *)s1;
		p2 = (unsigned long *)s2;
		while (quotient--)
		{
			if (*p1 != *p2)
				return (compare_by_1byte((unsigned char *)p1,
						(unsigned char *)p2, sizeof(unsigned long)));
			p1++;
			p2++;
		}
		s1 = (const void *)p1;
		s2 = (const void *)p2;
	}
	return (compare_by_1byte((unsigned char *)s1, (unsigned char *)s2, n));
}
