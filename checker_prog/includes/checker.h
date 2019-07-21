#ifndef CHECKER_H
# define CHECKER_H

# include "../../libft/libft.h"
# include <stdio.h>
# include <stdint.h>
# include <stdbool.h>
# include <curses.h>
# include <sys/ioctl.h>

# define PUT ft_putstr("There\n");
# define PUT1 ft_putstr("There1\n");
# define PUT2 ft_putstr("There2\n");
# define PUT3 ft_putstr("There3\n");

# define NB_MOVES 11

# define STOP "\033[0m"
# define GRA "\033[1m"
# define L_RED "\033[01;31m"
# define L_GREEN "\033[01;32m"

# define SS_MSG "The screen is too small.\nTry to resize or dezoom your window"
# define V_C_BUFF_SIZE 4096
# define V_P_BUFF_SIZE 8192
# define V_DELAY 250
# define V_PAD 30

typedef struct s_stack	t_stack;

struct	s_stack
{
	t_stack		*next;
	int		val;
	int		_pad;
};

typedef struct		s_env
{
	t_stack		*a;
	t_stack		*b;
	int		*moves;
	unsigned int	nb_push;
	unsigned int	size_a;
	unsigned int	size_b;
	char		stack;
	char		_pad[3];
}			t_env;

bool			*visu(void);
void			draw_line(unsigned int size, bool free_mem);
void			pad(int size, bool free_mem);
void			free_stacks(t_env *env);
int			run_instructions(t_env *env, bool val);
int			init_stack(t_env *env, long long int *stack, int len);
int			start_check(int argc, char **argv);
long long int		*get_numbers(int argc, char **argv, unsigned int len);
long long int		*parsing(int argc, char **argv, int *len);

/*
** Instructions
*/
void			push_a(t_env *env);
void			push_b(t_env *env);
void			swap_a(t_env *env);
void			swap_b(t_env *env);
void			swap_s(t_env *env);
void			rotate_a(t_env *env);
void			rotate_b(t_env *env);
void			rotate_s(t_env *env);
void			reverse_rotate_a(t_env *env);
void			reverse_rotate_b(t_env *env);
void			reverse_rotate_s(t_env *env);

void			print_lst(t_env *env);
#endif
