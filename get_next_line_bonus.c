/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgomes-o <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/06 11:44:49 by lgomes-o          #+#    #+#             */
/*   Updated: 2022/07/09 18:13:01 by lgomes-o         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

char	*get_line(char *s)
{
	char	*line;
	size_t	i;

	i = 0;
	if (!s[i])
		return (NULL);
	while (s[i] && s[i] != '\n')
		i++;
	line = (char *) ft_calloc((i + 2), sizeof(char));
	if (!line)
		return (NULL);
	i = 0;
	while (s[i] && s[i] != '\n')
	{
		line[i] = s[i];
		i++;
	}
	if (s[i] && s[i] == '\n')
		line[i] = s[i];
	return (line);
}

char	*get_subbuf(char *buf)
{
	char	*subbuf;
	size_t	i;
	size_t	j;

	i = 0;
	while (buf[i] && buf[i] != '\n')
		i++;
	if (!buf[i])
	{
		free(buf);
		return (NULL);
	}
	subbuf = (char *) ft_calloc((ft_strlen(buf) - i + 1), sizeof(char));
	if (!subbuf)
		return (NULL);
	i++;
	j = 0;
	while (buf[i])
		subbuf[j++] = buf[i++];
	free(buf);
	return (subbuf);
}	

char	*read_buffer(int fd, char *subbuf)
{
	char	*buf;
	int		n_bytes;

	if (!subbuf)
		subbuf = ft_calloc(1, sizeof(char));
	buf = (char *) ft_calloc((BUFFER_SIZE + 1), sizeof(char));
	if (!buf)
		return (NULL);
	n_bytes = 1;
	while (!ft_strchr(buf, '\n') && n_bytes > 0)
	{
		n_bytes = read(fd, buf, BUFFER_SIZE);
		if (n_bytes == -1)
		{
			free(buf);
			return (NULL);
		}
		buf[n_bytes] = 0;
		subbuf = ft_strjoin(subbuf, buf);
	}
	free(buf);
	return (subbuf);
}

char	*get_next_line(int fd)
{
	static char	*subbuf[FD_MAX];
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0 || fd > FD_MAX)
		return (0);
	subbuf[fd] = read_buffer(fd, subbuf[fd]);
	if (!subbuf[fd])
		return (NULL);
	line = get_line(subbuf[fd]);
	subbuf[fd] = get_subbuf(subbuf[fd]);
	return (line);
}	
