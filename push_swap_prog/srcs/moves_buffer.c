/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves_buffer.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gedemais <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/21 07:29:44 by gedemais          #+#    #+#             */
/*   Updated: 2019/07/22 00:20:53 by gedemais         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

static inline int			*realloc_buff(int *buff, unsigned int size)
{
	int	*new;

	if (!(new = (int*)malloc(sizeof(int) * size)))
		return (NULL);
	new = ft_memset(new, 0, sizeof(int) * size);
	new = ft_memcpy(new, buff, sizeof(int) * size / 2);
	free(buff);
	return (new);
}

static inline int			parse_instruction(char *move)
{
	static char		*moves[NB_MOVES] = {"sa\n", "sb\n", "ss\n", "pa\n", "pb\n",
		"ra\n", "rb\n", "rr\n", "rra\n", "rrb\n", "rrr\n"};
	static int		ids[NB_MOVES] = {SA_ID, SB_ID, SS_ID, PA_ID, PB_ID,
					RA_ID, RB_ID, RR_ID, RRA_ID, RRB_ID, RRR_ID};
	unsigned int	i;

	i = 0;
	while (i < NB_MOVES)
	{
		if (ft_strcmp(moves[i], move) == 0)
			return (ids[i]);
		i++;
	}
	return (-1);
}

static inline void			write_buffer(int *buff, unsigned int size)
{
	static char		*moves[NB_MOVES] = {"sa\n", "sb\n", "ss\n", "pa\n", "pb\n",
		"ra\n", "rb\n", "rr\n", "rra\n", "rrb\n", "rrr\n"};
	static int		ids[NB_MOVES] = {SA_ID, SB_ID, SS_ID, PA_ID, PB_ID,
		RA_ID, RB_ID, RR_ID, RRA_ID, RRB_ID, RRR_ID};
	unsigned int	i;
	unsigned int	j;

	i = 0;
	while (i < size)
	{
		j = 0;
		while (j < NB_MOVES)
		{
			if (buff[i] == ids[j])
				ft_putstr(moves[j]);
			j++;
		}
		i++;
	}
}

static inline unsigned int	buff_len(int *buff)
{
	unsigned int	i;

	i = 0;
	while (buff[i] != 0)
		i++;
	return (i);
}

int							moves_buffer(char *move, int flush)
{
	static int				*buff = NULL;
	static unsigned int		size = 1024;
	static unsigned int		index = 0;

	if (!buff)
	{
		if (!(buff = (int*)malloc(sizeof(int) * size)))
			return (-1);
		ft_memset(buff, 0, sizeof(int) * size);
	}
	if (flush == 1)
	{
		if (!(buff = optimize_buff(buff)))
			return (-1);
		write_buffer(buff, buff_len(buff));
	}
	else
	{
		if ((buff[index] = parse_instruction(move)) == -1)
			return (-1);
		index++;
		if (index == size && (size *= 2) && !(buff = realloc_buff(buff, size)))
			return (-1);
	}
	return (0);
}
