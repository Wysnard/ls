#include "ls.h"

void	ft_st(struct dirent *dir, char *arg, struct stat *buf)
{
	if (dir->d_type == DT_LNK || dir->d_type == DT_UNKNOWN)
		lstat(ft_strjoin(ft_strjoin(arg, "/"), dir->d_name), buf);
	else
		stat(ft_strjoin(ft_strjoin(arg, "/"), dir->d_name), buf);
}

struct	stat	*ft_getst(struct dirent *dir, char *arg)
{
	struct	stat	*buf;

	if (!(buf = (struct stat *)malloc(sizeof(struct stat))))
		exit(EXIT_FAILURE);
	ft_st(dir, arg, buf);
	return (buf);
}
