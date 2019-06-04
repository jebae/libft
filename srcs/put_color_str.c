#include "libft.h"

void		put_color_str(const char *color, const char *s)
{
	ft_putstr(color);
	ft_putstr(s);
	ft_putstr(KNRM);
}
