#include "ls.h"

void	ft_options(char *flag, char *arg, t_list **list)
{
	if (ft_strchr(flag, 'R'))
		ft_printf("%s:\n", arg);
	if (ft_strchr(flag, 'r') && ft_strchr(flag, 't'))
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

void	ft_get_flag(int argc, char **argv, char *flag)
{
	int	i;

	i = 1;
	while (i < argc)
	{
		if (argv[i][0] == '-')
			ft_flag(argv[i], flag);
		i++;
	}
}
