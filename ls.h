#ifndef	__LS_H__
#define	__LS_H__
#define OPENERR "ls: cannot open directory '"

#include "libft.h"
#include <sys/stat.h>
#include <sys/types.h>
#include <dirent.h>
#include <time.h>
#include <pwd.h>
#include <grp.h>
#include <errno.h>
#include <stdio.h>

typedef	struct	info
{
	struct	dirent	*dir;
	struct	stat	*st;
}								info;

int			ft_ls(char *flag, char *arg);
struct	dirent	*direntcpy(struct dirent *dir);
void	ft_printlst(t_list *list, char *flag, char *arg);
void		ft_alstdel(t_list *list);
void		ft_uid(struct stat *buf);
void		ft_gid(struct stat *buf);
void		ft_strmod(mode_t mode, char *buf);
info	*createinfo(struct dirent *dir, struct stat *st);
int	ft_total(char *arg);
void	ft_mod(struct stat *buf);
void ft_printsize(int max, struct stat *st);
void	ft_flag(char *arg, char *flag);
void	ft_lstmergesort(t_list **list);
void	ft_options(char *flag, char *arg, t_list **list);
void	ft_recurss(t_list *list, char *arg, char *flag);
void	ft_get_flag(int argc, char **argv, char *flag);
void	ft_openerr(char *arg);
void ft_printl(struct dirent *entry, int max, char *arg);
void	ft_st(struct dirent *dir, char *arg, struct stat *buf);
struct	stat	*ft_getst(struct dirent *dir, char *arg);
int	ft_compare(void *s1, void *s2);
void	ft_btrprt(void *content);
int	ft_revcompare(void *s1, void *s2);

#endif
