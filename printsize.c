#include "ls.h"

void ft_printsize(int max, struct stat *st)
{
	int	i;

	i = ft_intlen(st->st_size, 10);
	if (!i)
		max--;
	while (i < max)
	{
		ft_putchar(' ');
		i++;
	}
	ft_printf("%d ", st->st_size);
}
