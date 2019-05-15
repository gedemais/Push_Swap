/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   buff.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gedemais <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/30 16:12:05 by gedemais          #+#    #+#             */
/*   Updated: 2019/05/15 19:45:43 by gedemais         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	ft_puttil(char *str, char stop)
{
	int		len;

	len = 0;
	while (str[len] && str[len] != stop)
		len++;
	write(1, str, len);
}

char	*ft_replace(char *str)
{
	int		i;
	int		j;
	int		k;

	i = 0;
	while (str[i])
	{
		j = 0;
		while (str[i + j] && str[i + j] == ' ')
			j++;
		if (j != 0)
		{
			k = 0;
			while (str[i + k + j - 1])
			{
				str[i + k] = str[i + j + k + 1];
				k++;
			}
			while (str[i] && str[i] != '\n')
				i++;
		}
		i++;
	}
	return (str);
	j = 0;
}

char	*ft_trim_ops(char *str)
{
	if (ft_strncmp(str, "pa\npb", 5) == 0)
		ft_memset(str, ' ', 5);
	else if (ft_strncmp(str, "pb\npa", 5) == 0)
		ft_memset(str, ' ', 5);
	else if (ft_strncmp(str, "sa\nsa", 5) == 0)
		ft_memset(str, ' ', 5);
	else if (ft_strncmp(str, "sb\nsb", 5) == 0)
		ft_memset(str, ' ', 5);	
	else if (ft_strncmp(str, "sa\nsb", 5) == 0)
		ft_memset(str, 's', 5);	
	else if (ft_strncmp(str, "sb\nsa", 5) == 0)
		ft_memset(str, 's', 5);	
	else if (ft_strncmp(str, "rra\nra", 6) == 0)
		ft_memset(str, ' ', 6);
	else if (ft_strncmp(str, "ra\nrra", 6) == 0)
		ft_memset(str, ' ', 6);
	else if (ft_strncmp(str, "rrb\nrb", 6) == 0)
		ft_memset(str, ' ', 6);
	else if (ft_strncmp(str, "rb\nrrb", 6) == 0)
		ft_memset(str, ' ', 6);
	else if (ft_strncmp(str, "rra\nrrb", 7) == 0)
	{
		ft_memset(str, 'r', 3);
		str[3] = '\n';
		ft_memset(&str[4], ' ', 3);
	}
	else if (ft_strncmp(str, "rrb\nrra", 7) == 0)
	{
		ft_memset(str, 'r', 3);
		ft_memset(str, ' ', 4);
	}
	else
		return (NULL);
	return (str);
}

char	*ft_optimize_ops(char *str)
{
	int		i;
	bool	stop;

	if (str == NULL || str[0] == '\0')
		return (NULL);
	stop = true;
	while (stop)
	{
		i = 0;
		stop = false;
		while (str[i])
		{
			if (ft_trim_ops(&str[i]) != NULL)
			{
				stop = true;
				if (!(str = ft_replace(str)))
					return (NULL);
			}
			while (str[i] != '\n')
				i++;
			i++;
		}
	}
	return (str);
}

char	*ft_op_buff(char *op, int flush)
{
	static char	*str = NULL;
	static int	index = 0;

	if (flush)
	{
		ft_putstr(ft_optimize_ops(str));
		return (NULL);
	}
	if (!str)
		if (!(str = ft_strnew(OP_BUFF_SIZE)))
			return (NULL);
	ft_strcpy(&str[index], op);
	index += ft_strlen(op);
	str[index] = '\n';
	str[index + 1] = '\0';
	index++;
	return (NULL);
}
