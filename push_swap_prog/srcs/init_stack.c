/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_stack.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gedemais <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/21 07:26:40 by gedemais          #+#    #+#             */
/*   Updated: 2019/07/21 07:26:42 by gedemais         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

static inline void	lstdel(t_stack *stack)
{
	if (stack->next)
		lstdel(stack->next);
	free(stack);
}

void			free_stacks(t_env *env)
{
	if (env->a)
		lstdel(env->a);
	if (env->b)
		lstdel(env->b);
}

static inline t_stack	*lstnew(long long int stack)
{
	t_stack		*a;

	if (!(a = (t_stack*)malloc(sizeof(t_stack))))
		return (NULL);
	a->val = (int)stack;
	a->next = NULL;
	return (a);
}

int			init_stack(t_env *env, long long int *stack, int len)
{
	unsigned int	i;
	t_stack		*tmp;

	i = 1;
	env->b = NULL;
	if (!(env->a = lstnew(stack[0])))
		return (-1);
	tmp = env->a;
	while (i < (unsigned int)len)
	{
		if (!(env->a->next = lstnew(stack[i])))
			return (-1);
		env->a = env->a->next;
		env->a->next = NULL;
		i++;
	}
	env->a = tmp;
	return (0);
}
