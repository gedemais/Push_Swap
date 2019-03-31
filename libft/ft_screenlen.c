/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_screenlen.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gedemais <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/21 15:43:02 by gedemais          #+#    #+#             */
/*   Updated: 2019/03/21 16:58:18 by gedemais         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_screenlen(void)
{
	struct ttysize	screen;

	ioctl(0, TIOCGSIZE, &screen);
	return (screen.ts_cols);
}
