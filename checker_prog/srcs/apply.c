/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   apply.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gedemais <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/29 17:53:16 by gedemais          #+#    #+#             */
/*   Updated: 2019/05/07 13:22:25 by gedemais         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/checker.h"

int		ft_tree(t_env *env, char *input)
{
	if (ft_strcmp(input, "sa") == 0 || ft_strcmp(input, "sb") == 0)
		env = ft_ss(env, ((ft_strcmp(input, "sa") == 0) ? 'a' : 'b'));
	else if (ft_strcmp(input, "ss") == 0)
		env = ft_ss(env, ' ');
	else if (ft_strcmp(input, "pa") == 0)
		env = ft_pa(env);
	else if (ft_strcmp(input, "pb") == 0)
		env = ft_pb(env);
	else if (ft_strcmp(input, "ra") == 0)
		env = ft_ra(env);
	else if (ft_strcmp(input, "rb") == 0)
		env = ft_rb(env);
	else if (ft_strcmp(input, "rr") == 0)
		env = ft_rr(env);
	else if (ft_strcmp(input, "rra") == 0)
		env = ft_rra(env);
	else if (ft_strcmp(input, "rrb") == 0)
		env = ft_rrb(env);
	else if (ft_strcmp(input, "rrr") == 0)
		env = ft_rrr(env);
	else
		return (-1);
	return (0);
}

int		ft_apply(t_env *env)
{
	char	*input;
	int		ret;

	while ((ret = get_next_line(0, &input)) > 0)
	{
		if (ft_tree(env, input) != 0)
		{
			ft_strdel(&input);
			return (-1);
		}
		ft_strdel(&input);
	}
	if (ret == -1)
		return (-1);
	return (0);
}
