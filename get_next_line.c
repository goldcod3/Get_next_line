/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgomes-o <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/06 11:44:49 by lgomes-o          #+#    #+#             */
/*   Updated: 2022/07/09 13:26:21 by lgomes-o         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_line(char *s)
{
	char	*line;
	size_t	i;

	i = 0;
	if (!s[i])
		return (NULL);
	while (s[i] && s[i] != '\n')
		i++;
	line = (char *) malloc((i + 2) * sizeof(char));
	if (!line)
		return (NULL);
	i = 0;
	while (s[i] && s[i] != '\n')
	{
		line[i] = s[i];
		i++;
	}
	if (s[i] == '\n')
	{
		line[i] = s[i];
		i++;
	}
	line[i] = '\0';
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
	subbuf = (char *) malloc((ft_strlen(buf) - i + 1) * sizeof(char));
	if (!subbuf)
		return (NULL);
	i++;
	j = 0;
	while (buf[i])
		subbuf[j++] = buf[i++];
	subbuf[j] = '\0';
	free(buf);
	return (subbuf);
}	

char	*read_buffer(int fd, char *subbuf)
{
	char	*buf;
	int		n_bytes;

	buf = (char *) malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (!buf)
		return (NULL);
	n_bytes = 1;
	while (!ft_strchr(buf, '\n') && n_bytes != 0)
	{
		n_bytes = read(fd, buf, BUFFER_SIZE);
		printf("bytes: %d\n", n_bytes);
		printf("ft--> %s", ft_strchr(buf, '\n'));
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
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (0);
	subbuf = read_buffer(fd, subbuf);
	if (!subbuf)
		return (NULL);
//	printf("buffer: -->%s", subbuf);
	line = get_line(subbuf);
	subbuf = get_subbuf(subbuf);
//	printf("subb: -->%s", subbuf);
	return (line);
}	
