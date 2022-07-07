/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgomes-o <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/06 11:44:49 by lgomes-o          #+#    #+#             */
/*   Updated: 2022/07/07 18:59:44 by lgomes-o         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_line(char *s)
{
	char	*line;
	size_t	i;

	i = 0;
	if (!*(s + i))
		return (NULL);
	while (*(s + i) != '\0' && *(s + i) != '\n')
		i++;
	line = (char *) malloc((i + 1) * sizeof(char));
	if (!line)
		return (NULL);
	i = 0;
	while (*(s + i) != '\0' && *(s + i) != '\n')
	{
		*(line + i) = *(s + i);
		i++;
	}
	if (*(s + i) == '\n')
	{
		*(line + i) = *(s + i);
		i++;
	}
	*(line + i) = '\0';
	return (line);
}

char	*read_save_buffer(int fd, char *subbuf)
{
	char	*buf;
	int	n_bytes;

	buf = (char *) malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (buf == NULL)
		return (NULL);
	n_bytes = 1;
	printf("llega");
	while ((ft_strchr(buf, '\n')) == NULL && n_bytes != 0)
	{
		n_bytes = read(fd, buf, BUFFER_SIZE);
		if (n_bytes == -1)
		{
			free(buf);
			return (NULL);
		}
		buf[n_bytes] = '\0';
		subbuf = ft_strjoin(subbuf, buf);
	}
	free(buf);
	return (subbuf);
}

char	*get_next_line(int fd)
{
	static char	*subbuf;
	char	*line;

	printf("aqui");
	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	printf("fd: %d", fd);
	subbuf = read_save_buffer(fd, subbuf);
	if (subbuf == NULL)
		return (NULL);
	line = get_line(subbuf);
	return (line);
}	
