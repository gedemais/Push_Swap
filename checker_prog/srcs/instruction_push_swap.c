#include "../includes/checker.h"

void	push_a(t_env *env)
{
	t_stack	*tmp;

	if (env->b == NULL)
		return ;
	tmp = env->b;
	env->b = env->b->next;
	tmp->next = env->a;
	env->a = tmp;
}

void	push_b(t_env *env)
{
	t_stack	*tmp;

	if (env->a == NULL)
		return ;
	tmp = env->a;
	env->a = env->a->next;
	tmp->next = env->b;
	print_lst(env);
	env->b = tmp;
}

void	swap_a(t_env *env)
{
	t_stack	*tmp;

	if (env->a == NULL || env->a->next == NULL)
		return;
	tmp = env->a;
	env->a = env->a->next;
	tmp->next = env->a->next;
	env->a->next = tmp;
}

void	swap_b(t_env *env)
{
	t_stack	*tmp;

	if (env->b == NULL || env->b->next == NULL)
		return;
	tmp = env->b;
	env->b = env->b->next;
	tmp->next = env->b->next;
	env->b->next = tmp;
}

void	swap_s(t_env *env)
{
	swap_a(env);
	swap_b(env);
}
