/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strndup.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gedemais <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/13 12:51:50 by gedemais          #+#    #+#             */
/*   Updated: 2018/12/13 15:14:33 by gedemais         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strndup(char *str, int size)
{
	char	*dest;

	if (size > (int)ft_strlen(str))
		return (NULL);
	if (!(dest = (char*)malloc(sizeof(char) * size + 1)))
		return (NULL);
	dest = ft_strncpy(dest, str, size);
	return (dest);
}
