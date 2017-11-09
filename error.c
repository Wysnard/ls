#include "ls.h"

void	ft_openerr(void)
{
	//gerer les differents message d'erreur car la tu fais pas les EACCESS
		write(2, OPENERR, ft_strlen(OPENERR));
		write(2, arg, ft_strlen(arg));
		perror("'");
}
