/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gedemais <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/22 02:30:10 by gedemais          #+#    #+#             */
/*   Updated: 2019/07/22 03:14:52 by gedemais         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHECKER_H
# define CHECKER_H

# include "../../libft/libft.h"
# include <stdint.h>
# include <stdbool.h>

# define NB_MOVES 11

# define CLEAR "\033[H\033[J"
# define STOP "\033[0m"
# define GRA "\033[1m"
# define L_RED "\033[01;31m"
# define L_GREEN "\033[01;32m"
# define CYA "\033[01;36m"

# define V_C_BUFF_SIZE 4096
# define V_P_BUFF_SIZE 8192
# define V_DELAY 50
# define V_PAD 30

typedef struct s_stack	t_stack;

struct					s_stack
{
	t_stack				*next;
	int					val;
	int					pad;
};

typedef struct			s_env
{
	t_stack			*a;
	t_stack			*b;
	int				*moves;
	unsigned int	nb_push;
	unsigned int	size_a;
	unsigned int	size_b;
	char			stack;
	char			pad[3];
}						t_env;

int						run_instructions(t_env *env, bool val);
void					free_stacks(t_env *env);

/*
** Parsing
*/
long long int			*parsing(int argc, char **argv, int *len);
int						start_check(int argc, char **argv);
long long int			*get_numbers(int argc, char **argv, unsigned int len);
int						init_stack(t_env *env, long long int *stack, int len);

/*
** Visualiser
*/
bool					*visu(void);
void					print_lst(t_env *env);
void					draw_line(unsigned int size, bool free_mem);
void					pad(int size, bool free_mem);

/*
** Instructions
*/
void					push_a(t_env *env);
void					push_b(t_env *env);
void					swap_a(t_env *env);
void					swap_b(t_env *env);
void					swap_s(t_env *env);
void					rotate_a(t_env *env);
void					rotate_b(t_env *env);
void					rotate_s(t_env *env);
void					reverse_rotate_a(t_env *env);
void					reverse_rotate_b(t_env *env);
void					reverse_rotate_s(t_env *env);

#endif
