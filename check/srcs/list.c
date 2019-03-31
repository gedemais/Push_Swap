/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gedemais <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/28 19:24:58 by gedemais          #+#    #+#             */
/*   Updated: 2019/03/30 17:51:13 by gedemais         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/checker.h"

void	ft_putstack(t_stack *stack)
{
	t_stack *tmp;

	tmp = stack;
	while (tmp->next)
	{	
		ft_putnbr(tmp->val);
		ft_putchar(' ');
		tmp = tmp->next;
	}
	ft_putchar('\n');
}

/***********************************************************************/

int		ft_ps_lstlen(t_stack *stack)
{
	t_stack	*tmp;
	int		len;

	if (!stack)
		return (0);
	tmp = stack;
	len = 0;
	while (tmp->next)
	{
		tmp = tmp->next;
		len++;
	}
	return (len);
}

int		ft_ps_pushfront(t_stack **lst, t_stack *new)
{
	if (!new)
		return (-1);
	if (!(new->next = *lst))
		return (-1);
	if (!(*lst = new))
		return (-1);
	return (0);
}

t_stack	*ft_ps_lstnew(int index, int val)
{
	t_stack *new;

	if (!(new = (t_stack*)malloc(sizeof(t_stack))))
		return (NULL);
	new->index = index;
	new->val = val;
	new->next = NULL;
	return (new);
}

t_stack	*ft_init_a(int *suit, int len)
{
	t_stack	*lst;
	int		i;
	int		exist;

	i = len;
	exist = 0;
	while (i >= 0)
	{
		if (i == len)
		{
			if (!(lst = ft_ps_lstnew(i, suit[i])))
				return (NULL);
			exist++;
		}
		else if (ft_ps_pushfront(&lst, ft_ps_lstnew(i, suit[i])) == -1)
			return (NULL);
		i--;
	}
	if (exist == 0)
		return (NULL);
	return (lst);
}
