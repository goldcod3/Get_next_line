/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgomes-o <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/06 16:39:28 by lgomes-o          #+#    #+#             */
/*   Updated: 2022/07/06 19:41:01 by lgomes-o         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(char *str)
{
	size_t	i;

	i = 0;
	while (*(str + i) != '\0')
		i++;
	return (i);
}

void	*ft_calloc(size_t count, size_t size)
{
	void	*mem;
	char	*str;

	mem = (void *) malloc(count * size);
	str = (char *)mem;
	while (count > 0)
	{
		*(str + count) = '\0';
		count--;
	}
	return (mem);
}

char	*ft_substr(char *s, size_t start, size_t len)
{
	char	*sub;
	size_t	i;

	if (s == NULL)
		return (NULL);
	sub = (char *) ft_calloc(len + 1, sizeof(char));
	if (sub == NULL)
		return (NULL);
	i = 0;
	if (!(start > ft_strlen(s)))
	{
		while (i < len)
		{
			*(sub + i) = *(s + start);
			start++;
			i++;
		}
	}
	*(sub + i) = '\0';
	return (sub);
}


