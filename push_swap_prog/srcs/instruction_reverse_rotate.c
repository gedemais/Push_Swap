#include "../includes/push_swap.h"

void	reverse_rotate_a(t_env *env)
{
	t_stack		*tmp;
	t_stack		*tmp2;

	if (env->a == NULL || env->a->next == NULL)
		return ;
	tmp = env->a;
	while (env->a->next != NULL)
	{
		if (env->a->next->next == NULL)
		{
			tmp2 = env->a->next;
			env->a->next = NULL;
			env->a = tmp2;
			env->a->next = tmp;
			break ;
		}
		env->a = env->a->next;
	}
}

void	reverse_rotate_b(t_env *env)
{
	t_stack		*tmp;
	t_stack		*tmp2;

	if (env->b == NULL || env->b->next == NULL)
		return ;
	tmp = env->b;
	while (env->b->next != NULL)
	{
		if (env->b->next->next == NULL)
		{
			tmp2 = env->b->next;
			env->b->next = NULL;
			env->b = tmp2;
			env->b->next = tmp;
			break ;
		}
		env->b = env->b->next;
	}
}

void	reverse_rotate_s(t_env *env)
{
	reverse_rotate_a(env);
	reverse_rotate_b(env);
}
