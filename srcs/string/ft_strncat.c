/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jebae <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/04 14:52:20 by jebae             #+#    #+#             */
/*   Updated: 2019/04/04 14:52:21 by jebae            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strncat(char *s1, const char *s2, size_t n)
{
	char	*p_s1;

	p_s1 = s1;
	while (*p_s1 != '\0')
		p_s1++;
	while (*s2 != '\0' && n-- > 0)
		*(p_s1++) = *(s2++);
	*p_s1 = '\0';
	return (s1);
}

char	*strnewncat(char *s1, char *s2, size_t n)
{
	char	*token;

	token = ft_strnew(ft_strlen(s1) + n);
	if (token == NULL)
		return (NULL);
	ft_strcpy(token, s1);
	ft_strncat(token, s2, n);
	return (token);
}
