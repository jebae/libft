/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jebae <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/09 17:58:50 by jebae             #+#    #+#             */
/*   Updated: 2019/04/10 13:54:43 by jebae            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	char	*part;
	char	*loc;
	size_t	d;

	d = 0;
	part = ft_strnew(len);
	ft_strncpy(part, haystack, len);
	loc = ft_strstr(part, needle);
	if (loc == NULL)
	{
		free(part);
		return (NULL);
	}
	d = loc - part;
	free(part);
	return ((char *)haystack + d);
}
