/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gedemais <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/29 15:19:24 by gedemais          #+#    #+#             */
/*   Updated: 2019/04/30 20:42:09 by gedemais         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int 	ft_is_ok(char c, char n, int nb_len)
{	
	if (c && ft_isdigit(c) == 0 && c != ' ' && c != '-' && c != '+')
		return (0);
	else if (c == '+' && ft_isdigit(n) == 0)
		return (0);
	else if (c == '-' && ft_isdigit(n) == 0)
		return (0);
	if (nb_len > 10)
		return (0);
	return (1);
}

int		ft_check_void(int argc, char **argv)
{
	
	int 	i;

	i = 0;
	while (i < argc)
	{
		if (argv[i][0] != '\0')
			return (0);
		i++;
	}
	return (1);
}

int 	ft_pre_check(int argc, char **argv)
{
	int		nb_len;
	int 	i;
	int		j;

	i = 1;
	if (ft_check_void(argc, argv) == 1)
		return (1);
	while (i < argc)
	{
		j = 0;
		nb_len = 0;
		while (argv[i][j])
		{
			if (ft_is_ok(argv[i][j], argv[i][j + 1], nb_len) == 0)
				return (1);
			if (argv[i][j] == ' ')
				nb_len = 0;
			else if (ft_isdigit(argv[i][j]) == 0)
				nb_len++;
			j++;
		}
		i++;
	}
	return (0);
}

t_env	*ft_parsing(t_env *env, int argc, char **argv)
{
	if (ft_pre_check(argc, argv) == 1)
		return (NULL);
	if (!(env = ft_load_tab(env, argc, argv)))
		return (NULL);
	return (env);
}
