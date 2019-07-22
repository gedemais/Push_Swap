/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   optimize_buff.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gedemais <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/21 07:29:49 by gedemais          #+#    #+#             */
/*   Updated: 2019/07/22 00:24:38 by gedemais         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

static inline int	*optimize_push(int *buff, unsigned int i, bool *changed)
{
	if ((buff[i] == PA_ID && buff[i + 1] == PB_ID)
		|| (buff[i] == PB_ID && buff[i + 1] == PA_ID))
	{
		*changed = true;
		buff[i] = -1;
		buff[i + 1] = -1;
	}
	return (buff);
}

static inline int	*optimize_swap(int *buff, unsigned int i, bool *changed)
{
	if ((buff[i] == SA_ID || buff[i] == SB_ID || buff[i] == SS_ID)
		&& buff[i + 1] == buff[i])
	{
		buff[i] = -1;
		buff[i + 1] = -1;
		*changed = true;
	}
	else if ((buff[i] == SA_ID && buff[i + 1] == SB_ID)
		|| (buff[i] == SB_ID && buff[i + 1] == SA_ID))
	{
		buff[i] = SS_ID;
		buff[i + 1] = -1;
		*changed = true;
	}
	return (buff);
}

static inline int	*optimize_rotate(int *buff, unsigned int i, bool *changed)
{
	if ((buff[i] == RA_ID && buff[i + 1] == RRA_ID)
		|| (buff[i] == RRA_ID && buff[i + 1] == RA_ID)
		|| (buff[i] == RB_ID && buff[i + 1] == RRB_ID)
		|| (buff[i] == RRB_ID && buff[i + 1] == RB_ID))
	{
		buff[i] = -1;
		buff[i + 1] = -1;
		*changed = true;
	}
	else if ((buff[i] == RR_ID && buff[i + 1] == RRR_ID)
		|| (buff[i] == RRR_ID && buff[i + 1] == RR_ID))
	{
		buff[i] = -1;
		buff[i + 1] = -1;
		*changed = true;
	}
	return (buff);
}

static inline int	*refresh_buff(int *buff)
{
	int				*new;
	unsigned int	n_size;
	int				i;
	int				j;

	i = -1;
	n_size = 0;
	while (buff[++i] != 0)
		if (buff[i] != -1)
			n_size++;
	if (!(new = (int*)malloc(sizeof(int) * (n_size + 1))))
		return (NULL);
	ft_memset(new, 0, sizeof(int) * (n_size + 1));
	i = -1;
	j = -1;
	while (buff[++i] != 0)
		if (buff[i] != -1)
			new[++j] = buff[i];
	free(buff);
	return (new);
}

int					*optimize_buff(int *buff)
{
	unsigned int	i;
	bool			changed;

	changed = true;
	while (changed)
	{
		changed = false;
		i = 0;
		while (buff[i] != 0)
		{
			buff = optimize_push(buff, i, &changed);
			buff = optimize_swap(buff, i, &changed);
			buff = optimize_rotate(buff, i, &changed);
			if (buff[i] == -1)
			{
				while (buff[i] != 0 && buff[i] == -1)
					i++;
			}
			else
				i++;
		}
		if (!(buff = refresh_buff(buff)))
			return (NULL);
	}
	return (buff);
}
