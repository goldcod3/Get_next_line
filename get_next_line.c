/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgomes-o <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/06 11:44:49 by lgomes-o          #+#    #+#             */
/*   Updated: 2022/07/06 19:40:58 by lgomes-o         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUFFER_SIZE
#define BUFFER_SIZE 1
#endif

#include "get_next_line.h"

static char	*subbuf;

char	*get_line(char *s)
{
	size_t	i;
	char	*tmp;

	i = 0;
	while (*(s + i) != '\0')
	{
		if (*(s + i) == '\n')
			break ;
		i++;
	}
	tmp = ft_substr(s, 0, i);
	subbuf = ft_substr(s, ++i, ft_strlen(s));
	return (tmp);
}

char	*get_next_line(int fd)
{
	char	*buf;
	size_t	n_bytes;

	if (fd != -1)
	{
		buf = (char *) ft_calloc(BUFFER_SIZE, sizeof(char));	
		n_bytes = read(fd, buf, BUFFER_SIZE);
		if (n_bytes != 0)
		{
			if (subbuf == NULL)
				return (get_line(buf));
			else
				return (get_line(subbuf));
		}
	}
	return (NULL);
}	
