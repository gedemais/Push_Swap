/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start_check.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gedemais <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/21 07:30:31 by gedemais          #+#    #+#             */
/*   Updated: 2019/07/21 07:30:33 by gedemais         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

static inline int	is_unwanted(char c)
{
	if (ft_isdigit(c))
		return (0);
	if (ft_is_whitespace(c))
		return (0);
	if (c == '-' || c == '+')
		return (2);
	return (1);
}

static inline int	is_wellsigned(char *arg, unsigned int j)
{
	if (j == 0 && arg[j + 1] && ft_isdigit(arg[j + 1]))
		return (0);
	if (j > 0 && ft_is_whitespace(arg[j - 1]))
	{
		if (arg[j + 1] && ft_isdigit(arg[j + 1]))
			return (0);
	
	}
	return (-1);
}

static inline int	is_number_end(char *arg, unsigned int j)
{
	if (ft_isdigit(arg[j]))
		if ((arg[j + 1] == '\0' || ft_is_whitespace(arg[j + 1])))
			return (1);
	return (0);
}

int			start_check(int argc, char **argv)
{
	unsigned int	i;
	unsigned int	j;
	int		nb_n;
	int		ret;

	i = 1;
	nb_n = 0;
	while (i < (unsigned int)argc)
	{
		j = 0;
		while (argv[i][j])
		{
			if ((ret = is_unwanted(argv[i][j])) == 1)
				return (-1);
			if (ret == 2 && is_wellsigned(argv[i], j) == -1)
				return (-1);
			if (is_number_end(argv[i], j) == 1)
				nb_n++;
			j++;
		}
		i++;
	}
	return (nb_n);
}
