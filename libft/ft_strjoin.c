/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gedemais <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/05 17:26:35 by gedemais          #+#    #+#             */
/*   Updated: 2019/02/15 03:27:15 by gedemais         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char *s1, char *s2)
{
	char	*dest;
	int		len;

	if (!s1)
		return ((char*)s2);
	if (!s2)
		return ((char*)s1);
	len = ft_strlen(s1) + ft_strlen(s2);
	if (!(dest = (char*)malloc(sizeof(char) * len + 1)))
		return (NULL);
	dest[0] = '\0';
	ft_strcat(dest, s1);
	ft_strcat(dest, s2);
	return (dest);
}
