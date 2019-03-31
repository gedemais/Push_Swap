/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gedemais <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/28 19:18:38 by gedemais          #+#    #+#             */
/*   Updated: 2019/03/30 18:00:09 by gedemais         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/checker.h"

int		ft_sa(t_env *env) // Swap les deux premiers de a
{
	t_stack	*tmp;

	if (ft_ps_lstlen(env->a) < 2)
		return (1);
	else
	{
		tmp = env->a->next;
		ft_swap(&env->a->val, &tmp->val);
	}
	return (0);
}

int		ft_sb(t_env *env) // Swap les deux permiers de b
{
	t_stack	*tmp;

	if (ft_ps_lstlen(env->b) < 2)
		return (1);
	else
	{
		tmp = env->b->next;
		ft_swap(&env->b->val, &tmp->val);
	}
	return (0);
}

int		ft_ss(t_env *env) // sa et sb en meme temps
{
	ft_sa(env);
	ft_sb(env);
	return (0);
}

int		ft_pa(t_env *env) // Mets le premier de b sur a
{
	t_stack		*tmp;

	if (ft_ps_lstlen(env->b) < 1)
		return (1);
	tmp = env->b->next;
	env->b->next = env->a;
	env->a = env->b;
	env->b = tmp;
	return (0);
}

int		ft_pb(t_env *env) // Mets le premier de a sur b
{
	t_stack		*tmp;

	if (ft_ps_lstlen(env->a) < 1)
		return (1);
	tmp = env->a->next;
	env->a->next = env->b;
	env->b = env->a;
	env->a = tmp;
	return (0);
}

int		ft_ra(t_env *env) // Decale tous les nombres de a un cran vers le haut (permier -> dernier)
{
	t_stack		*tmp;
	t_stack		*tmp2;

	if (ft_ps_lstlen(env->a) < 2)
		return (0);
	tmp = env->a;
	tmp2 = env->a;
	while (tmp2->next)
		tmp2 = tmp2->next;
	env->a = env->a->next;
	tmp2->next = tmp;
	tmp->next = NULL;
	return (1);
}

int		ft_rb(t_env *env) // Decale tous les nombres de b un cran vers le haut (permier -> dernier)
{
	t_stack		*tmp;
	t_stack		*tmp2;

	if (ft_ps_lstlen(env->b) < 2)
		return (1);
	tmp = env->b;
	tmp2 = env->b;
	while (tmp2->next)
		tmp2 = tmp2->next;
	env->b = env->b->next;
	tmp2->next = tmp;
	printf("tmp->val = %d\n", tmp->val);
	tmp->next = NULL;
	return (0);
}

int		ft_rr(t_env *env) // ra et rb en meme temps
{
	ft_ra(env);
	ft_rb(env);
	return (0);
}

int		ft_rra(t_env *env)
{
	t_stack		*tmp;
	t_stack		*tmp2;

	tmp = env->a;
	tmp2 = env->a;
	while (tmp2->next)
	{
		if (tmp->next->next)
			tmp = tmp->next;
		tmp2 = tmp2->next;
	}
	tmp->next = NULL;
	tmp2->next = env->a;
	env->a = tmp2;
	return (0);
}

int		ft_rrb(t_env *env)
{
	t_stack		*tmp;
	t_stack		*tmp2;

	tmp = env->b;
	tmp2 = env->b;
	while (tmp2->next)
	{
		if (tmp->next->next)
			tmp = tmp->next;
		tmp2 = tmp2->next;
	}
	tmp->next = NULL;
	tmp2->next = env->b;
	env->b = tmp2;
	return (0);
}

int		ft_rrr(t_env *env)
{
	ft_rra(env);
	ft_rrb(env);
	return (0);
}


