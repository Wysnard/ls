#include "ls.h"

void	ft_options(char *flag, t_list **list)
{
	if (ft_strchr(flag, 't'))
		ft_lstmergesort(list);
	if (ft_strchr(flag, 'R'))
		ft_printf("%s:\n", arg);
	if (ft_strchr(flag, 'r'))
		ft_lstrev(list);
}

void	ft_flag(char *arg, char *flag)
{
	if (ft_strchr(arg, 'l') && !ft_strchr(flag, 'l'))
		ft_strcat(flag, "l");
	if (ft_strchr(arg, 'R') && !ft_strchr(flag, 'R'))
		ft_strcat(flag, "R");
	if (ft_strchr(arg, 'a') && !ft_strchr(flag, 'a'))
		ft_strcat(flag, "a");
	if (ft_strchr(arg, 'r') && !ft_strchr(flag, 'r'))
		ft_strcat(flag, "r");
	if (ft_strchr(arg, 't') && !ft_strchr(flag, 't'))
		ft_strcat(flag, "t");
}
