/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gedemais <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/21 07:15:48 by gedemais          #+#    #+#             */
/*   Updated: 2019/07/21 07:15:50 by gedemais         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/checker.h"

static inline int	check_duplicates(long long int *stack, int len)
{
	unsigned int	i;
	unsigned int	j;

	i = 0;
	while (i < (unsigned int)len)
	{
		j = i + 1;
		while (j < (unsigned int)len)
		{
			if (stack[i] == stack[j])
				return (1);
			j++;
		}
		i++;
	}
	return (0);
}

long long int		*parsing(int argc, char **argv, int *len)
{
	long long int		*stack;

	if ((*len = start_check(argc, argv)) == -1)
		return (NULL);
	if (!(stack = get_numbers(argc, argv, (unsigned int)*len)))
		return (NULL);
	if (check_duplicates(stack, *len) == 1)
		return (NULL);
	return (stack);
}
