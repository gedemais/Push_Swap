/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gedemais <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/29 17:17:41 by gedemais          #+#    #+#             */
/*   Updated: 2019/05/03 10:59:11 by gedemais         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int		ft_ps_pushback(t_stack **lst, t_stack *new)
{
	t_stack	*tmp;

	tmp = *lst;
	while (tmp->next)
		tmp = tmp->next;
	tmp->next = new;
	new->next = NULL;
	return (0);
}

t_stack		*ft_ps_lstnew(t_env *env, int index)
{
	t_stack		*new;

	if (!(new = (t_stack*)malloc(sizeof(t_stack))))
		return (NULL);
	new->val = env->suit[index];
	new->next = NULL;
	return (new);
}

t_env		*ft_init_stack(t_env *env)
{
	int 	i;

	i = 0;
	env->a = NULL;
	env->b = NULL;
	while (i < env->len)
	{
		if (i == 0)
			env->a = ft_ps_lstnew(env, i);
		else
			ft_ps_pushback(&env->a, ft_ps_lstnew(env, i));
		i++;
	}
	env->alen = env->len;
	env->blen = 0;
	return (env);
}
