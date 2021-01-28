#include "libft.h"

static void	borrow_month(t_datetime *dt)
{
	int		m;
	int		y;

	m = dt->month;
	y = dt->year;
	if (m == 3)
	{
		if ((y % 4 == 0 && y % 100 != 0) || y % 400 == 0)
			dt->day += 29;
		else
			dt->day += 28;
	}
	else if (m == 5 || m == 7 || m == 10 || m == 12)
		dt->day += 30;
	else
		dt->day += 31;
	dt->month -= 1;
}

/*
** hour, second is not supporting
*/

int			timedelta(time_t t1, time_t t2, t_timedelta *td)
{
	t_datetime	bigger;
	t_datetime	smaller;
	time_t		temp;

	if (t1 > t2)
	{
		temp = t1;
		t1 = t2;
		t2 = temp;
	}
	if (get_datetime(t1, &smaller) == -1)
		return (-1);
	if (get_datetime(t2, &bigger) == -1)
		return (-1);
	while (bigger.day < smaller.day)
		borrow_month(&bigger);
	td->day = bigger.day - smaller.day;
	if (bigger.month < smaller.month)
	{
		bigger.month += 12;
		bigger.year -= 1;
	}
	td->month = bigger.month - smaller.month;
	td->year = bigger.year - smaller.year;
	return (1);
}
