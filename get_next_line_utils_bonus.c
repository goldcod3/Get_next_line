/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgomes-o <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/06 16:39:28 by lgomes-o          #+#    #+#             */
/*   Updated: 2022/07/09 18:01:32 by lgomes-o         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

size_t	ft_strlen(char *str)
{
	size_t	i;

	i = 0;
	if (!str)
		return (0);
	while (str[i] != '\0')
		i++;
	return (i);
}

void	ft_bzero(void *str, size_t len)
{
	char	*tmp;
	size_t		i;

	i = 0;
	tmp = (char *)str;
	while (i < len)
	{
		tmp[i] = '\0';
		i++;
	}
}	

void	*ft_calloc(size_t count, size_t size)
{
	char	*res;

	res = malloc(count * size);
	if (!res)
		return (NULL);
	ft_bzero(res, count * size);
	return (res);
}	

char	*ft_strchr(char *str, int c)
{
	size_t	i;

	if (!str)
		return (NULL);
	if (c == '\0')
		return (str);
	i = 0;
	while (str[i] != '\0')
	{
		if (str[i] == (char)c)
			return ((char *)&str[i]);
		i++;
	}
	return (NULL);
}

char	*ft_strjoin(char *s1, char *s2)
{
	char	*str;
	size_t	t_len;
	size_t	i;
	size_t	j;

	t_len = ft_strlen(s1) + ft_strlen(s2);
	str = (char *) malloc((t_len + 1) * sizeof(char));	
	if (!s1 || !s2 || !str)
		return (NULL);
	i = 0;
	while (s1[i] != '\0')
	{
		str[i] = s1[i];
		i++;
	}
	j = 0;
	while (s2[j] != '\0')
		str[i++] = s2[j++];
	str[t_len] = '\0';
	free(s1);
	return (str);
}
