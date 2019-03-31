/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gedemais <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/28 12:59:09 by gedemais          #+#    #+#             */
/*   Updated: 2019/03/28 19:32:10 by gedemais         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "../libft/libft.h"

typedef struct s_stack t_stack;

struct	s_stack
{
	int		index;
	int		val;
	t_stack	*next;
};

typedef struct	s_env
{
	t_stack		*a;
	t_stack		*b;
	int			a_len;
	int			b_len;
}				t_env;

#endif
