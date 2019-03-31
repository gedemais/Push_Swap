/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strfind.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gedemais <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/16 08:56:32 by gedemais          #+#    #+#             */
/*   Updated: 2019/03/02 14:09:23 by gedemais         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_strfind(const char *str, int c)
{
	int		ret;
	int		i;

	i = -1;
	ret = 0;
	if (!str)
		return (0);
	while (str[++i])
		if (str[i] == c)
			ret++;
	return (ret);
}
