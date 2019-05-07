/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gedemais <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/29 13:30:39 by gedemais          #+#    #+#             */
/*   Updated: 2019/05/06 18:24:41 by gedemais         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHECKER_H
# define CHECKER_H

# include "../../includes/main.h"
# include <stdbool.h>
# include <stdio.h>


typedef struct s_stack	t_stack;

struct s_stack
{
	int		val;
	t_stack	*next;
};

typedef struct	s_env
{
	t_stack	*a;
	t_stack	*b;
	int		*suit;
	int		len;
	int		alen;
	int		blen;
	bool	error;
}				t_env;

// apply.c
int		ft_apply(t_env *env);

// parsing.c
t_env	*ft_parsing(t_env *env, int argc, char **argv);

// tab.c
t_env	*ft_load_tab(t_env *env, int argc, char **argv);

// list.c
t_env	*ft_init_stack(t_env *env);

// utils.c
void	ft_print_stacks(t_env *env);
int 	ft_is_sorted(t_env *env);
void	ft_ps_lstdel(t_stack *stack);

// moves
t_env	*ft_ss(t_env *env, char c);
t_env	*ft_pa(t_env *env);
t_env	*ft_pb(t_env *env);
t_env	*ft_ra(t_env *env);
t_env	*ft_rb(t_env *env);
t_env	*ft_rr(t_env *env);
t_env	*ft_rra(t_env *env);
t_env	*ft_rrb(t_env *env);
t_env	*ft_rrr(t_env *env);

#endif
