/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pitab.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gedemais <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/06 19:46:42 by gedemais          #+#    #+#             */
/*   Updated: 2019/03/21 16:29:09 by gedemais         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_pitab(int *tab, int size)
{
	int		i;

	i = 0;
	while (i < size)
	{
		ft_putstr("tab[");
		ft_putnbr(i);
		ft_putstr("] = ");
		ft_putnbr(tab[i]);
		ft_putchar('\n');
		i++;
	}
}
