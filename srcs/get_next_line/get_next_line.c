/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jebae <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/17 17:45:47 by jebae             #+#    #+#             */
/*   Updated: 2019/04/18 16:09:05 by jebae            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static int	safe_return(char **line, int *cur, int *r, int res)
{
	if (*line != NULL)
		ft_memdel((void **)line);
	*cur = BUFF_SIZE;
	*r = BUFF_SIZE;
	return (res);
}

static int	copy_buf(char *buf, int offset, int end, char **line)
{
	int		cur;
	char	*temp;

	if (offset >= end)
		return (end);
	cur = offset;
	while (cur < end && buf[cur] != '\n')
		cur++;
	buf[cur] = '\0';
	if (*line == NULL)
	{
		if ((*line = ft_strnew(cur - offset)) == NULL)
			return (-1);
		ft_strncpy(*line, buf + offset, cur - offset);
	}
	else
	{
		temp = *line;
		if ((*line = ft_strjoin(*line, buf + offset)) == NULL)
			return (-1);
		ft_memdel((void **)&temp);
	}
	return (cur);
}

int			get_next_line(const int fd, char **line)
{
	static char		buf[OPEN_MAX][BUFF_SIZE + 1];
	static int		cur[OPEN_MAX] = {BUFF_SIZE, };
	static int		r[OPEN_MAX] = {BUFF_SIZE, };

	if (line == NULL || fd < 0)
		return (-1);
	*line = NULL;
	if ((cur[fd] = copy_buf(buf[fd], cur[fd], r[fd], line)) == -1)
		return (safe_return(line, &cur[fd], &r[fd], -1));
	while (cur[fd] == r[fd])
	{
		r[fd] = read(fd, &buf[fd], BUFF_SIZE);
		if (r[fd] == -1)
			return (safe_return(line, &cur[fd], &r[fd], -1));
		else if (r[fd] == 0 && *line == NULL)
			return (safe_return(line, &cur[fd], &r[fd], 0));
		else if (r[fd] == 0)
			return (1);
		cur[fd] = 0;
		if ((cur[fd] = copy_buf(buf[fd], cur[fd], r[fd], line)) == -1)
			return (safe_return(line, &cur[fd], &r[fd], -1));
	}
	cur[fd]++;
	return (1);
}
