#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "../../checker_prog/includes/checker.h"

# define NB_ALGOS 3

# define A_SELECTION 2
# define A_QUICKSORT 4
# define A_THREESORT 8

# define PA_ID 2
# define PB_ID 4
# define SA_ID 8
# define SB_ID 16
# define SS_ID 32
# define RA_ID 64
# define RB_ID 128
# define RR_ID 256
# define RRA_ID 512
# define RRB_ID 1024
# define RRR_ID 2048

int		selection_sort(t_env *env);
int		three_sort_a(t_env *env);
unsigned int	ps_lstlen(t_stack *lst);

int		sort_stacks(t_env *env, int algo);
int		moves_buffer(char *move, int flush);

#endif
