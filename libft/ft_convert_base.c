/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_base.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gedemais <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/03 23:25:51 by gedemais          #+#    #+#             */
/*   Updated: 2019/02/03 23:26:01 by gedemais         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_lenb(long long nb, int lenb)
{
	int ret;

	ret = 0;
	while (nb >= (long long)lenb)
	{
		ret++;
		nb /= (long long)lenb;
	}
	return (ret + 1);
}

char	*ft_strrev(char *str)
{
	int		i;
	int		j;
	char	c;

	i = ft_strlen(str) - 1;
	j = 0;
	while (j < i)
	{
		c = str[i];
		str[i] = str[j];
		str[j] = c;
		i--;
		j++;
	}
	return (str);
}

char	*ft_convert_base(long long nb, char *base)
{
	int				i;
	unsigned int	lenb;
	char			*ret;
	int				sign;

	i = 0;
	lenb = ft_strlen(base);
	sign = 0;
	if (nb < 0)
	{
		sign = -1;
		nb = -nb;
	}
	if (!(ret = (char*)malloc(sizeof(char*) * ft_lenb(nb, lenb) + 1)))
		return (NULL);
	while (nb >= (long long)lenb)
	{
		ret[i] = base[nb % lenb];
		i++;
		nb /= lenb;
	}
	ret[i] = base[nb];
	ret[i + 1] = (sign == -1) ? '-' : 0;
	ret[i + 2] = 0;
	return (ft_strrev(ret));
}
