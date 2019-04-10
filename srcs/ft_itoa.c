/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jebae <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/06 20:37:38 by jebae             #+#    #+#             */
/*   Updated: 2019/04/10 14:48:57 by jebae            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	get_length(int n)
{
	int		i;
	int		len;

	i = n;
	len = 0;
	while (n && ++len)
		n /= 10;
	if (i <= 0)
		len++;
	return (len);
}

char			*ft_itoa(int n)
{
	size_t	j;
	char	*a;

	j = get_length(n);
	a = (char *)malloc(sizeof(char) * (j + 1));
	if (a == NULL)
		return (NULL);
	a[j--] = '\0';
	if (n < 0)
	{
		a[0] = '-';
		a[j] = -(n % 10) + '0';
		n = n / 10 * -1;
	}
	else
	{
		a[j] = n % 10 + '0';
		n /= 10;
	}
	while (n)
	{
		a[--j] = n % 10 + '0';
		n /= 10;
	}
	return (a);
}
