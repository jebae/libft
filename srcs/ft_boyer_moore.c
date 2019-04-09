/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_boyer_moore.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jebae <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/09 17:58:15 by jebae             #+#    #+#             */
/*   Updated: 2019/04/09 17:58:16 by jebae            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#define CHARACTER_TABLE_SIZE 256
#define MAX(a, b) ((a) > (b)) ? (a) : (b)

static void			make_bc_table(int *table, const char *pat, int len)
{
	int		i;

	i = 0;
	while (i < CHARACTER_TABLE_SIZE)
		table[i++] = -1;
	i = 0;
	while (i < len)
	{
		table[(int)(pat[i])] = i;
		i++;
	}
}

static void			make_gs_table(int *shift_table, const char *pat, int len)
{
	int		pos_table[len];
	int		i;
	int		j;

	i = len;
	j = i + 1;
	pos_table[i] = j;
	while (i > 0)
	{
		while (j <= len && pat[i - 1] != pat[j - 1])
		{
			if (shift_table[j] == 0)
				shift_table[j] = j - i;
			j = pos_table[j];
		}
		pos_table[--i] = --j;
	}
	j = pos_table[0];
	while (i <= len)
	{
		if (shift_table[i] == 0)
			shift_table[i] = j;
		if (i++ == j)
			j = pos_table[j];
	}
}

static void			preprocess(int *bc_table, int *shift_table,\
		const char *pat, int len)
{
	make_bc_table(bc_table, pat, len);
	make_gs_table(shift_table, pat, len);
}

static char			*search(const char *text, const char *pat,\
		int *bc_table, int *shift_table)
{
	int		i;
	int		j;
	int		text_len;
	int		pat_len;

	text_len = ft_strlen(text);
	pat_len = ft_strlen(pat);
	i = 0;
	while (i <= text_len - pat_len)
	{
		j = pat_len - 1;
		while (j >= 0 && pat[j] == text[i + j])
			j--;
		if (j < 0)
			return ((char *)text + i);
		else
			i += MAX(shift_table[j + 1],\
					j - bc_table[(int)(text[i + j])]);
	}
	return (NULL);
}

char				*ft_boyer_moore(const char *text, const char *pat)
{
	int			pat_len;
	int			bc_table[CHARACTER_TABLE_SIZE];
	int			*shift_table;
	char		*loc;

	loc = NULL;
	pat_len = ft_strlen(pat);
	shift_table = ft_memalloc(sizeof(int) * (pat_len + 1));
	if (shift_table == NULL)
		return (NULL);
	preprocess(bc_table, shift_table, pat, pat_len);
	loc = search(text, pat, bc_table, shift_table);
	free(shift_table);
	return (loc);
}
