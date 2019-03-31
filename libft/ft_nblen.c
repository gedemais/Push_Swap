/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_nblen.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gedemais <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/12 12:45:08 by gedemais          #+#    #+#             */
/*   Updated: 2019/02/11 08:46:40 by gedemais         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_nb_len(long long int nb)
{
	if (nb >= 0 && nb < 10)
		return (1);
	else if (nb >= 10 && nb < 100)
		return (2);
	else if (nb >= 100 && nb < 1000)
		return (3);
	else if (nb >= 1000 && nb < 10000)
		return (4);
	else if (nb >= 10000 && nb < 100000)
		return (5);
	else if (nb >= 100000 && nb < 1000000)
		return (6);
	else if (nb >= 1000000 && nb < 10000000)
		return (7);
	else
		return (-1);
}
