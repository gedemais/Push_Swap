/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tab.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gedemais <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/29 16:32:20 by gedemais          #+#    #+#             */
/*   Updated: 2019/04/30 12:33:34 by gedemais         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int			ft_check_doubles(t_env *env)
{
	int 	i;
	int		j;

	i = 0;
	while (i < env->len)
	{
		j = 0;
		while (j < env->len)
		{
			if (j != i && env->suit[i] == env->suit[j])
				return (1);
			j++;
		}
		i++;
	}
	return (0);
}

int			ft_count_numbers(int argc, char **argv)
{
	int		ret;
	int 	i;
	int 	j;

	i = 1;
	ret = 0;
	while (i < argc)
	{
		j = 0;
		while (argv[i][j])
		{
			if (ft_isdigit(argv[i][j]) == 1 && (argv[i][j + 1] == ' ' || argv[i][j + 1] == '\0'))
					ret++;
			j++;
		}
		i++;
	}
	return (ret);
}

t_env		*ft_read_tab(t_env *env, int argc, char **argv)
{
	long long int	tmp;
	int 			i;
	int				j;
	int				k;

	i = 0;
	k = 0;
	while (++i < argc && k < env->len)
	{
		j = -1;
		while (argv[i][++j] && k < env->len)
		{
			while (argv[i][j] == ' ' || argv[i][j] == '\0')
				j++;
			tmp = ft_atoi(&argv[i][j]);
			if (tmp > 2147483647 || tmp < -2147483648)
				return (NULL);
			else
			{
				env->suit[k] = tmp;
				k++;
			}
			while (argv[i][j] == '-' || argv[i][j] == '+' || ft_isdigit(argv[i][j]) == 1)
				j++;
		}
	}
	return (env);
}

t_env		*ft_load_tab(t_env *env, int argc, char **argv)
{
	env->len = ft_count_numbers(argc, argv);
	if (!(env->suit = (int*)malloc(sizeof(int) * (env->len + 1))))
		return (NULL);
	if (!(env = ft_read_tab(env, argc, argv)))
		return (NULL);
	if (ft_check_doubles(env) == 1)
		return (NULL);
	return (env);
}
