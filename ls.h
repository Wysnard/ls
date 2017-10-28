#ifndef	__LS_H__
#define	__LS_H__

#include "libft.h"
#include <sys/stat.h>
#include <sys/types.h>
#include <dirent.h>
#include <time.h>
#include <pwd.h>
#include <grp.h>
#include <attr/xattr.h>

typedef	struct	info
{
	struct	dirent	*dir;
	struct	stat	*st;
}								info;

int			ft_ls(char *flag, char *arg);
struct	dirent	*direntcpy(struct dirent *dir);
void		ft_printlst(t_list *list, char *flag);
void		ft_alstdel(t_list *list);
void		ft_uid(struct stat *buf);
void		ft_gid(struct stat *buf);
void		ft_strmod(mode_t mode, char *buf);
info		*createinfo(struct dirent *dir);
struct	stat	*statcpy(struct stat *cp);

#endif
