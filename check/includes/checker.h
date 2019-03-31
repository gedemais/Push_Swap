/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gedemais <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/27 21:07:55 by gedemais          #+#    #+#             */
/*   Updated: 2019/03/30 17:39:25 by gedemais         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHECKER_H
# define CHECKER_H

# define PUT ft_putstr("There\n");
# define PUT1 ft_putstr("There1\n");
# define PUT2 ft_putstr("There2\n");
# define PUT3 ft_putstr("There3\n");
# define PUT4 ft_putstr("There4\n");
# define PUT5 ft_putstr("There5\n");
# define PUT6 ft_putstr("There6\n");
# define PUT7 ft_putstr("There7\n");
# define PUT8 ft_putstr("There8\n");
# define PUT9 ft_putstr("There9\n");
# define PUT10 ft_putstr("There10\n");

# define DEBUG_PARSER 1

#include "../../includes/push_swap.h"

void	ft_putstack(t_stack *stack);

/*****************************************/

int		*ft_parsing(int argc, char **argv, int *len);
t_stack	*ft_init_a(int *suit, int len);
int		ft_is_sort(t_stack *stack);
int		ft_ps_lstlen(t_stack *stack);

// Moves
int		ft_sa(t_env *env);
int		ft_sb(t_env *env);
int		ft_ss(t_env *env);
int		ft_pa(t_env *env);
int		ft_pb(t_env *env);
int		ft_ra(t_env *env);
int		ft_rb(t_env *env);
int		ft_rr(t_env *env);
int		ft_rra(t_env *env);
int		ft_rrb(t_env *env);
int		ft_rrr(t_env *env);

#endif
