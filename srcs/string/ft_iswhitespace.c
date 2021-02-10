/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_iswhitespace.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jebae <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/28 15:43:05 by jebae             #+#    #+#             */
/*   Updated: 2019/05/28 15:43:05 by jebae            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_iswhitespace(char ch)
{
	return (ch == ' ' || (ch >= 0x09 && ch <= 0x0d));
}

int		isstrwhitespace(char *s)
{
	while (*s != '\0')
	{
		if (!ft_iswhitespace(*s))
			return (0);
		s++;
	}
	return (1);
}
