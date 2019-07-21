/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_numbers.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gedemais <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/21 01:38:30 by gedemais          #+#    #+#             */
/*   Updated: 2019/07/21 02:02:56 by gedemais         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

static inline int	is_number_start(char *arg, unsigned int j)
{
	if (j == 0)
	{
		if (arg[j] == '-' || arg[j] == '+' || ft_isdigit(arg[j]))
			return (1);
	}
	else if (arg[j] == '-' || arg[j] == '+' || ft_isdigit(arg[j]))
		if (ft_is_whitespace(arg[j - 1]))
			return (1);
	return (0);
}

long long int		*get_numbers(int argc, char **argv, unsigned int len)
{
	long long int	*stack;
	unsigned int	i;
	int		j;
	int		k;

	i = 0;
	k = 0;
	if (!(stack = (long long int*)malloc(sizeof(long long int) * len)))
		return (NULL);
	while (++i < (unsigned int)argc)
	{
		j = -1;
		while (argv[i][++j])
			if (is_number_start(argv[i], (unsigned int)j))
			{
				stack[k] = ft_atoi(&argv[i][j]);
				if (stack[k] > 2147483647 || stack[k] < -2147483648)
				{
					free(stack);
					return (NULL);
				}
				k++;
			}
	}
	return (stack);
}
