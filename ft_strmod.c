#include "ls.h"

void	ft_strmod(mode_t mode, char *buf)
{
	char	chars[10];
	int		i;

	i = 0 ;
	ft_strcpy(chars, "rwxrwxrwx");
	while (i < 9)
	{
		buf[i] = (mode & (1 << (8-i))) ? chars[i] : '-';
		i++;
	}
	buf[9] = '\0';
}

void	ft_mod(struct stat *buf)
{
	char		str[10];

	ft_strmod(buf->st_mode, str);
	ft_printf("%s %d ", str, buf->st_nlink);
}
