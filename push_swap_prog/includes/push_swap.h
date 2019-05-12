/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gedemais <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/29 13:44:03 by gedemais          #+#    #+#             */
/*   Updated: 2019/05/12 20:46:41 by gedemais         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAIN_H
# define MAIN_H

# define OP_BUFF_SIZE 1000000

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

# include "../../includes/main.h"
# include "../../libft/libft.h"
# include "../../checker_prog/includes/checker.h"
# include <limits.h>

t_env		*ft_ssort(t_env *env);
t_env		*ft_qsort(t_env *env, char stack, int size);
int		ft_ps_lstlen(t_stack *stack);
t_env		*ft_push_on_a(t_env *env, int val);
t_env		*ft_push_on_b(t_env *env, int val);
int		*ft_sort_tab(int *tab, int len);


char		*ft_op_buff(char *op, int flush);
char		*ft_optimize_ops(char *str);
t_env		*ft_case_two(t_env *env, char stack);
t_env		*ft_two_sort_a(t_env *env);
t_env		*ft_two_sort_b(t_env *env);
t_env		*ft_three_sort_a(t_env *env, char stack);
t_env		*ft_three_sort_b(t_env *env, char stack);
int			*ft_get_tab(t_stack *stack, int *len);

#endif
