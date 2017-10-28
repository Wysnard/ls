#include "ls.h"

void	ft_strmod(mode_t mode)
{
	char	chars[10];
	int		i;
	char	buf[10];

	i = 0 ;
	ft_strcpy(chars, "rwxrwxrwx");
	while (i < 9)
	{
		buf[i] = (mode & (1 << (8-i))) ? chars[i] : '-';
		i++;
	}
	buf[9] = '\0';
	ft_printf("%s ", buf);
}
