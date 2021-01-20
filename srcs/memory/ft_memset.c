/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jebae <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/05 16:42:58 by jebae             #+#    #+#             */
/*   Updated: 2019/04/05 19:48:35 by jebae            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static unsigned long	get_data_buf(unsigned char c)
{
	int				i;
	unsigned long	buf;

	buf = 0;
	i = sizeof(unsigned long) / sizeof(unsigned char);
	while (i > 0)
	{
		i--;
		buf <<= 8;
		buf |= c;
	}
	return (buf);
}

static void				*write_by_8byte(
		unsigned long *b, unsigned long data, size_t len)
{
	unsigned long	*next;
	int				i;

	i = len / sizeof(unsigned long);
	next = b + i;
	while (i-- > 0)
		b[i] = data;
	return ((void *)next);
}

void					*ft_memset(void *b, int c, size_t len)
{
	unsigned long	data;
	void			*ptr;
	int				remain;

	data = get_data_buf((unsigned char)c);
	ptr = write_by_8byte((unsigned long *)b, data, len);
	remain = len % sizeof(unsigned long);
	while (remain--)
		((unsigned char *)ptr)[remain] = (unsigned char)data;
	return (b);
}
