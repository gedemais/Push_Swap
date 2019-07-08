#include "../includes/push_swap.h"

unsigned int	ps_lstlen(t_stack *lst)
{
	t_stack		*tmp;
	unsigned int	ret;

	ret = 0;
	tmp = lst;
	while (tmp)
	{
		tmp = tmp->next;
		ret++;
	}
	return (ret);
}
