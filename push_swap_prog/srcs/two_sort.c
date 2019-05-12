/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   two_sort.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gedemais <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/12 20:12:54 by gedemais          #+#    #+#             */
/*   Updated: 2019/05/12 20:16:28 by gedemais         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

t_env	*ft_two_sort_a(t_env *env)
{
	if (env->a == NULL || env->a->next == NULL)
		return (env);
	if (env->a->val > env->a->next->val)
	{
		env = ft_ss(env, 'a');
		ft_op_buff("sa", 0);
	}
	return (env);
}

t_env	*ft_two_sort_b(t_env *env)
{
	if (env->b == NULL || env->b->next == NULL)
		return (env);
	if (env->b->val < env->b->next->val)
	{
		env = ft_ss(env, 'b');
		ft_op_buff("sb", 0);
	}
	return (env);
}
