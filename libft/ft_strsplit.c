/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gedemais <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/05 17:29:00 by gedemais          #+#    #+#             */
/*   Updated: 2018/11/07 10:12:50 by gedemais         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int		ft_isw(char c, char s)
{
	if (c == s || c == '\0')
		return (1);
	return (0);
}

static int		ft_strlen_ws(char *str, char s)
{
	int		i;

	i = 0;
	while (!ft_isw(str[i], s))
		i++;
	return (i);
}

static int		ft_cw(char *str, char s)
{
	int		i;
	int		nb;

	i = -1;
	nb = 0;
	while (str[++i])
		if (!ft_isw(str[i], s) && ft_isw(str[i + 1], s))
			nb++;
	return (nb);
}

static char		*ft_strdup_ws(char *src, char s)
{
	char	*dest;
	int		i;

	i = 0;
	if (!(dest = (char*)malloc(sizeof(char) * ft_strlen_ws(src, s))))
		return (NULL);
	while (!ft_isw(src[i], s))
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}

char			**ft_strsplit(char const *s, char c)
{
	char	**tab;
	char	*str;
	int		i;
	int		j;

	i = 0;
	j = 0;
	if (!s)
		return (NULL);
	str = ft_strtrim(s);
	if (!(tab = (char**)malloc(sizeof(char*) * ft_cw((char*)s, c) + 1)))
		return (NULL);
	while (j < ft_cw((char*)s, c))
	{
		while (ft_isw(s[i], c))
			i++;
		if (!ft_isw(s[i], c))
			tab[j] = ft_strdup_ws((char*)&s[i], c);
		i += ft_strlen_ws((char*)&s[i], c);
		j++;
	}
	tab[j] = 0;
	return (tab);
}
