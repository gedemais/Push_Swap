/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gedemais <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/13 10:21:21 by gedemais          #+#    #+#             */
/*   Updated: 2019/04/01 12:43:01 by gedemais         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include "libft.h"
# include <unistd.h>
# include <sys/types.h>
# include <fcntl.h>

# define BUFF_SIZE 64

int		get_next_line(const int fd, char **line);

#endif
