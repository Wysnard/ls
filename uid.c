#include "ls.h"

void	ft_uid(struct stat *buf)
{
	struct	passwd	*user;

	user = getpwuid(buf->st_uid);
	ft_printf("%s ", user->pw_name);
}
