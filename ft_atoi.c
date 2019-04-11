/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jebae <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/05 14:59:48 by jebae             #+#    #+#             */
/*   Updated: 2019/04/11 14:29:08 by jebae            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	is_whitespace(const char ch)
{
	return (ch == ' ' || (ch >= '\t' && ch <= '\r'));
}

int			ft_atoi(const char *str)
{
	unsigned long		res;
	char				neg;

	res = 0;
	neg = 0;
	while (*str != '\0' && is_whitespace(*str))
		str++;
	if (*str == '+')
		str++;
	else if (*str == '-')
	{
		neg = -1;
		str++;
	}
	while (ft_isdigit(*str))
	{
		res = res * 10 + (*str - '0');
		str++;
	}
	if (res / 10 > LONG_LIMIT / 10 ||
		(res / 10 == LONG_LIMIT / 10 && res % 10 > LONG_LIMIT % 10))
		return (neg ? 0 : -1);
	return ((int)res * (neg ? neg : 1));
}
