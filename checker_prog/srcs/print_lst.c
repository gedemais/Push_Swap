/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_lst.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gedemais <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/21 07:17:18 by gedemais          #+#    #+#             */
/*   Updated: 2019/07/21 22:35:25 by gedemais         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/checker.h"

void			pad(int size, bool free_mem)
{
	static char	*pad_buff = NULL;

	if (free_mem)
	{
		free(pad_buff);
		return ;
	}
	if (!pad_buff)
	{
		if (!(pad_buff = ft_strnew(V_P_BUFF_SIZE)))
			return ;
		ft_memset(pad_buff, ' ', sizeof(char) * V_P_BUFF_SIZE);
	}
	if (size > V_P_BUFF_SIZE)
		return ;
	write(1, &pad_buff[0], (size_t)size);
}

static inline int	color_elem(t_stack *node, char stack)
{
	if (stack == 'a' && node->next && node->val < node->next->val)
		ft_putstr(L_GREEN);
	else if (stack == 'a' && node->next && node->val > node->next->val)
		ft_putstr(L_RED);
	if (stack == 'b' && node->next && node->val > node->next->val)
		ft_putstr(L_GREEN);
	else if (stack == 'b' && node->next && node->val < node->next->val)
		ft_putstr(L_RED);
	return (0);
}

void			draw_line(unsigned int size, bool free_mem)
{
	static char	*line_buff = NULL;
	unsigned int	i;

	i = 0;
	if (free_mem)
	{
		free(line_buff);
		return ;
	}
	if (!line_buff)
	{
		if (!(line_buff = ft_strnew(size)))
			return ;
		ft_memset(line_buff, '-', sizeof(char) * size);
	}
	if (size > V_P_BUFF_SIZE)
		return ;
	write(1, &line_buff[0], (size_t)size);
	ft_putchar('\n');
}

static inline void			print_head(void)
{
	ft_putchar('\n');
	ft_putstr(CLEAR);
	ft_putstr(CYA);
	draw_line(V_PAD + 2, false);
	ft_putstr("A");
	pad(V_PAD, false);
	ft_putstr("B\n");
	draw_line(V_PAD + 2, false);
}

void			print_lst(t_env *env)
{
	int		pad_v;
	t_stack		*a;
	t_stack		*b;

	a = env->a;
	b = env->b;
	print_head();
	while (a || b)
	{
		if (a && color_elem(a, 'a') == 0)
		{
			ft_putnbr(a->val);
			pad_v = V_PAD - ft_nb_len(a->val);
			pad(pad_v, false);
		}
		else
			pad(V_PAD, false);
		if (b && color_elem(b, 'b') == 0)
			ft_putnbr(b->val);
		ft_putchar('\n');
		a = (a && a->next ? a->next : NULL);
		b = (b && b->next ? b->next : NULL);
	}
}
