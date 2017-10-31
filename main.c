#include "ls.h"

int	main(int argc, char **argv)
{
	int	i;
	char	flag[6];
	t_list	*wait;
	int	ct;

	i = 1;
	wait = NULL;
	flag[0] = '\0';
	ct = 0;
	while (i < argc)
	{
		if (argv[i][0] == '-')
			ft_flag(argv[i], flag);
		else
		{
			ft_lstpushadd(&wait, ft_lstnew(ft_strdup(argv[i]), sizeof(argv[i])));
			ct++;
		}
		i++;
	}
	if (!wait)
		ft_ls(flag, ".");
	while (wait)
	{
		if (!ft_strchr(flag, 'R') && ct > 1)
			ft_printf("%s:\n", wait->content);
		ft_ls(flag, wait->content);
		wait = wait->next;
		if (wait)
			ft_printf("\n");
	}
	return (0);
}
