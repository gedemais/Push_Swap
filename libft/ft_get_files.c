/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_files.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gedemais <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/21 14:47:24 by gedemais          #+#    #+#             */
/*   Updated: 2019/03/21 14:50:01 by gedemais         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_count_files(char *path)
{
	DIR				*d;
	struct dirent	*dir;
	int				ret;

	ret = 0;
	if (!(d = opendir(path)))
		return (-1);
	while ((dir = readdir(d)))
		ret++;
	closedir(d);
	return (ret);
}

char		**ft_get_files(char *path)
{
	DIR				*d;
	struct dirent	*dir;
	char			**files;
	int				i;

	i = 0;
	if (!(files = (char**)malloc(sizeof(char*) * (ft_count_files(path) + 1))))
		return (NULL);
	if (!(d = opendir(path)))
		return (NULL);
	while ((dir = readdir(d)))
	{
		if (!(files[i] = ft_strdup(dir->d_name)))
			return (NULL);
		i++;
	}
	files[i] = NULL;
	closedir(d);
	return (files);
}
