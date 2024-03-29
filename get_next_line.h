/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgomes-o <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/06 11:45:06 by lgomes-o          #+#    #+#             */
/*   Updated: 2022/07/16 13:50:00 by lgomes-o         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1
# endif

# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>

size_t	ft_strlen(char *str);
void	ft_bzero(void *str, size_t len);
void	*ft_calloc(size_t count, size_t len);
char	*ft_strchr(char *str, int c);
char	*ft_strjoin(char *s1, char *s2);

char	*get_next_line(int fd);

#endif
