#include "../includes/push_swap.h"

static inline void	optimize_push(int *buff, unsigned int i, bool *changed)
{
	if ((buff[i] == PA_ID && buff[i + 1] == PB_ID)
		|| (buff[i] == PB_ID && buff[i + 1] == PA_ID))
	{
		*changed = true;
		buff[i] = -1;
		buff[i + 1] = -1;
	}
}

static inline void	optimize_swap(int *buff, unsigned int i, bool *changed)
{
	if ((buff[i] == SA_ID || buff[i] == SB_ID || buff[i] == SS_ID)
		&& buff[i + 1] == buff[i])
	{
		buff[i] = -1;
		buff[i + 1] = -1;
		*changed = true;
	}
	else if ((buff[i] == SA_ID && buff[i + 1] == SB_ID)
		|| (buff[i] == SB_ID && buff[i + 1] == SA_ID))
	{
		buff[i] = SS_ID;
		buff[i + 1] = -1;
		*changed = true;
	}
}

static inline void	optimize_rotate(int *buff, unsigned int i, bool *changed)
{
	if ((buff[i] == RA_ID && buff[i + 1] == RRA_ID)
		|| (buff[i] == RRA_ID && buff[i + 1] == RA_ID)
		|| (buff[i] == RB_ID && buff[i + 1] == RRB_ID)
		|| (buff[i] == RRB_ID && buff[i + 1] == RB_ID))
	{
		buff[i] = -1;
		buff[i + 1] = -1;
		*changed = true;
	}
}

static inline void	optimize_rrotate(int *buff, unsigned int i, bool *changed)
{
	if ((buff[i] == RR_ID && buff[i + 1] == RRR_ID)
		|| (buff[i] == RRR_ID && buff[i + 1] == RR_ID))
	{
		buff[i] = -1;
		buff[i + 1] = -1;
		*changed = true;
	}
}

int	*optimize_buff(int *buff)
{
	unsigned int	i;
	bool		changed;

	i = 0;
	changed = true;
	while (changed)
	{
		changed = false;
		while (buff[i] != 0)
		{
			while (buff[i] != 0 && buff[i] == -1)
				i++;
			optimize_push(buff, i, &changed);
			optimize_swap(buff, i, &changed);
			optimize_rotate(buff, i, &changed);
			optimize_rrotate(buff, i, &changed);
			i++;
		}
	}
	return (buff);
}
