/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgomes-o <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/06 11:45:06 by lgomes-o          #+#    #+#             */
/*   Updated: 2022/07/16 13:50:20 by lgomes-o         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1
# endif

# ifndef FD_MAX
#  define FD_MAX 1024
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
