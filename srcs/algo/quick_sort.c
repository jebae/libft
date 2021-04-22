#include "libft.h"
#include <stdio.h>

static void	swap(void **arr, int i, int j)
{
	void	*temp;

	temp = arr[i];
	arr[i] = arr[j];
	arr[j] = temp;
}

void		quick_sort(void **arr, int start, int end, t_sort_cmp cmp)
{
	int	left;
	int	right;

	if (start >= end)
		return ;
	left = start + 1;
	right = end;
	while (left <= right) {
		while (left <= right && cmp(arr[start], arr[left]) >= 0)
			left++;
		while (left <= right && cmp(arr[start], arr[right]) < 0)
			right--;
		if (left < right)
		{
			swap(arr, left, right);
			left++;
			right--;
		}
	}
	swap(arr, start, right);
	quick_sort(arr, start, right - 1, cmp);
	quick_sort(arr, left, end, cmp);
}
