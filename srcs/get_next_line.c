#include "get_next_line.h"
#include <stdio.h>

int			check_bucket(t_bucket *bucket)
{
	if (bucket->loc == 0)
		return (BUCKET_EMPTY);
	if (bucket->loc > BUFF_SIZE)
		return (BUCKET_FULL);
	return (BUCKET_REMAINED);
}

int			write_line(t_bucket *bucket, char **line)
{
	char		*buf;
	char		*tmp_line;
	char		stop;
	size_t		i;

	i = 0;
	buf = bucket->buf + bucket->loc;
	while (i < BUFF_SIZE && buf[i] != '\n')
		i++;
	tmp_line = *line;
	stop = buf[i];
	buf[i] = '\0';
	*line = ft_strjoin(*line, buf);
	buf[i] = stop;
	ft_memdel((void **)&tmp_line);
	if (*line == NULL)
		return (WRITE_LINE_FAIL);
	bucket->loc += i + 1;
	return (WRITE_LINE_SUCCESS);
}


int			preprocess(const int fd, char **line)
{
	if (fd < 0 || line == NULL || BUFF_SIZE <= 0)
		return (PREPROCESS_FAIL);
	*line = ft_strnew(0);
	return (PREPROCESS_SUCCESS);
}

int			get_next_line(const int fd, char **line)
{
	static t_bucket		bucket;
	int					ret;
	int					bucket_status;

	if (preprocess(fd, line) == PREPROCESS_FAIL)
		return (GNL_ERROR);
	bucket_status = check_bucket(&bucket);
	while (bucket_status == BUCKET_EMPTY || bucket_status == BUCKET_REMAINED)
	{
		if (bucket_status == BUCKET_EMPTY)
		{
			ret = read(fd, bucket.buf, BUFF_SIZE);
			if (ret == -1)
				return (GNL_ERROR);
			if (ret == 0 && (*line)[0] == '\0')
			{
				ft_memdel((void **)line);
				return (GNL_READ_COMPLETE);
			}
		}
		if (write_line(&bucket, line) == WRITE_LINE_FAIL)
			return (GNL_ERROR);
		if (check_bucket(&bucket) == BUCKET_FULL)
		{
			ft_bzero((void *)bucket.buf, BUFF_SIZE + 1);
			bucket.loc = 0;
			bucket_status = BUCKET_EMPTY;
			if (bucket.buf[BUFF_SIZE - 1] != '\0')
				continue ;
		}
		return (GNL_LINE_READ);
	}
	return (GNL_ERROR);
}
