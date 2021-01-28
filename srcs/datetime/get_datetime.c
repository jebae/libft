#include "libft.h"

static int	get_month(char *s)
{
	static char	months[12][4] = {
		"Jan", "Feb", "Mar", "Apr", "May", "Jun",
		"Jul", "Aug", "Sep", "Oct", "Nov", "Dec",
	};
	int			i;

	i = 0;
	while (i < 12)
	{
		if (ft_strncmp(s, months[i], 3) == 0)
			return (i + 1);
		i++;
	}
	return (-1);
}

int			get_datetime(time_t t, t_datetime *dt)
{
	char	*date;

	date = ctime(&t);
	if (date == NULL)
		return (-1);
	ft_memset(dt, 0, sizeof(t_datetime));
	dt->year = ft_atoi(date + 20);
	dt->month = get_month(date + 4);
	dt->day = ft_atoi(date + 8);
	dt->hour = ft_atoi(date + 11);
	dt->minute = ft_atoi(date + 14);
	dt->second = ft_atoi(date + 17);
	return (1);
}
