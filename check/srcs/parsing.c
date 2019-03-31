/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gedemais <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/28 13:24:48 by gedemais          #+#    #+#             */
/*   Updated: 2019/03/29 10:44:37 by gedemais         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/checker.h"

int		*ft_read(int *tab, char *str)
{
	int			i;
	static int	j = 0;

	i = 0;
	while (str[i])
	{
		while (str[i] && str[i] == ' ' && ft_isdigit(str[i]) == 0)
			i++;
		if (ft_isdigit(str[i]) == 1 || str[i] == '-')
		{
			tab[j] = ft_atoi(&str[i]);
			j++;
		}
		while (str[i] && str[i] != ' ')
			i++;
	}
	return (tab);
}

int		ft_count_nbs(int argc, char **argv)
{
	int		i;
	int		j;
	int		ret;

	i = 1;
	ret = 0;
	while (i < argc)
	{
		j = 0;
		while (argv[i][j])
		{
			if (ft_isdigit(argv[i][j]) == 1 && (argv[i][j + 1] == '\0'
				|| argv[i][j + 1] == ' '))
				ret++;
			j++;
		}
		i++;
	}
	return (ret);
}

int		*ft_get_numbers(int argc, char **argv, int *len)
{
	int		*tab;
	int		i;

	i = 0;
	*len = ft_count_nbs(argc, argv);
	if (!(tab = (int*)malloc(sizeof(int) * (*len + 1))))
		return (NULL);
	while (i < argc)
	{
		if (!(tab = ft_read(tab, argv[i])))
			return (NULL);
		i++;
	}
	return (tab);
}

int		ft_prime_check(int argc, char **argv)
{
	int		i;
	int		j;
	int		size;

	i = 1;
	size = 0;
	while (i < argc)
	{
		j = -1;
		while (argv[i][++j])
			if (size > 9)
				return (-1);
			else if (argv[i][j] && ft_isdigit(argv[i][j]) == 0
				&& argv[i][j] != ' ' && argv[i][j] != '-')
				return (-1);
			else if (ft_isdigit(argv[i][j]) == 1)
				size++;
			else if (argv[i][j] == ' ' || argv[i][j] == '\0')
				size = 0;
		i++;
		size = 0;
	}
	return (0);
}

int		ft_check_doubles(int *suit, int len)
{
	int		i;
	int		j;

	i = 0;
	while (i < len)
	{
		j = 0;
		while (j < len)
		{
			if (i != j && suit[i] == suit[j])
				return (1);
			j++;
		}
		i++;
	}
	return (0);
}

int		*ft_parsing(int argc, char **argv, int *len)
{
	int		*suit;
	int		i;

	i = 0;
	suit = NULL;
	if (ft_prime_check(argc, argv) != 0)
		return (NULL);
	if (!(suit = ft_get_numbers(argc, argv, len)))
		return (NULL);
	if (ft_check_doubles(suit, *len) == 1)
	{
		free(suit);
		return (NULL);
	}
	return (suit);
}
