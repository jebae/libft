#include "libft.h"
#include <stdio.h>

static char	*concat_path(char *from, char *path)
{
	char	*concat;
	char	*pwd;

	if (from[0] == '/')
		concat = strcat_all(3, from, "/", path);
	else
	{
		pwd = getcwd(NULL, 0);
		if (pwd == NULL)
			return (NULL);
		concat = strcat_all(5, pwd, "/", from, "/", path);
		ft_memdel((void **)&pwd);
	}
	return (concat);
}

static char	*concat_stack(char **stack)
{
	char	*path;
	char	*temp;

	if ((path = ft_strnew(1)) == NULL)
		return (NULL);
	while (*stack)
	{
		temp = path;
		path = ft_strjoin(path, "/");
		ft_memdel((void **)&temp);
		if (path == NULL)
			return (NULL);
		temp = path;
		path = ft_strjoin(path, *stack);
		ft_memdel((void **)&temp);
		if (path == NULL)
			return (NULL);
		stack++;
	}
	path[0] = '/';
	return (path);
}

static char	*resolve_stack(char **stack)
{
	int		i;
	int		j;

	i = -1;
	j = 0;
	while (stack[j])
	{
		if (ft_strcmp(stack[j], "..") == 0)
		{
			if (i >= 0)
				ft_memdel((void **)&stack[i--]);
			ft_memdel((void **)&stack[j]);
		}
		else if (ft_strcmp(stack[j], ".") == 0)
			ft_memdel((void **)&stack[j]);
		else
			stack[++i] = stack[j];
		j++;
	}
	stack[i + 1] = NULL;
	return (concat_stack(stack));
}

char 		*resolve_path(char *from, char *path)
{
	char	**stack;
	char	**temp;

	if (from == NULL || path == NULL)
		return (NULL);
	path = (path[0] == '/')
		? ft_strdup(path)
		: concat_path(from, path);
	if (path == NULL)
		return (NULL);
	stack = ft_strsplit(path, '/');
	ft_memdel((void **)&path);
	if (stack == NULL)
		return (NULL);
	path = resolve_stack(stack);
	temp = stack;
	while (*temp)
	{
		ft_memdel((void **)temp);
		temp++;
	}
	ft_memdel((void **)&stack);
	return (path);
}
