#ifndef CHECKER_H
# define CHECKER_H

# include "../../libft/libft.h"
# include <stdio.h>
# include <stdint.h>
# include <stdbool.h>

# define PUT ft_putstr("There\n");
# define PUT1 ft_putstr("There1\n");
# define PUT2 ft_putstr("There2\n");
# define PUT3 ft_putstr("There3\n");

# define NB_MOVES 11

typedef struct s_stack	t_stack;

struct	s_stack
{
	t_stack	*next;
	int	val;
	int	_pad;
};

typedef struct	s_env
{
	t_stack	*a;
	t_stack	*b;
	int	*moves;
	unsigned int		nb_push;
	unsigned int	size;
	unsigned int	_pad;
	char		stack;
	char		s[3];
}		t_env;

void		free_stacks(t_env *env);
int		run_instructions(t_env *env);
int		init_stack(t_env *env, long long int *stack, int len);
long long int	*get_numbers(int argc, char **argv, unsigned int len);
int		start_check(int argc, char **argv);
long long int	*parsing(int argc, char **argv, int *len);

/*
** Instructions
*/
void		push_a(t_env *env);
void		push_b(t_env *env);
void		swap_a(t_env *env);
void		swap_b(t_env *env);
void		swap_s(t_env *env);
void		rotate_a(t_env *env);
void		rotate_b(t_env *env);
void		rotate_s(t_env *env);
void		reverse_rotate_a(t_env *env);
void		reverse_rotate_b(t_env *env);
void		reverse_rotate_s(t_env *env);

void			print_lst(t_env *env);
#endif
