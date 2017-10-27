#ifndef	__LS_H__
#define	__LS_H__

#include "libft.h"
#include <sys/stat.h>
#include <sys/types.h>
#include <dirent.h>
#include <time.h>
#include <pwd.h>
#include <grp.h>

typedef	struct	file
{
	char	flag[6];
	t_list	*pile;
}		file;

int		ft_ls(char *flag, char *arg);
struct	dirent	*direntcpy(struct dirent *dir);
void		ft_printlst(t_list *list, char *flag);
void		ft_alstdel(t_list *list);

#endif
