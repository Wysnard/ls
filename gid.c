#include "ls.h"

void	ft_gid(struct stat *buf)
{
	struct	group	*grp;

	grp = getgrgid(buf->st_gid);
	ft_printf("%s ", grp->gr_name);
}
