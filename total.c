#include "ls.h"

int	ft_total(char *arg)
{
	DIR		*dir;
	struct	dirent	*entry;
	int		max;
	int		total;
	struct	stat	buf;

	total = 0;
	max = 0;
	if (!(dir = opendir(arg)))
	{
		ft_openerr();
		return (-1);
	}
	while (entry = readdir(dir))
	{
		if (entry->d_type == DT_LNK || entry->d_type == DT_UNKNOWN)
			lstat(ft_strjoin(ft_strjoin(arg, "/"), entry->d_name), buf);
		else
			stat(ft_strjoin(ft_strjoin(arg, "/"), entry->d_name), buf);
		if (max < ft_intlen(buf->st_size, 10))
			max = ft_intlen(buf->st_size, 10);
		total += buf->st_blocks;
	}
	ft_printf("total %d\n", total);
	closedir(dir);
	return (total);
}
