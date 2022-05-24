/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkaczoro <kkaczoro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/19 18:36:35 by kkaczoro          #+#    #+#             */
/*   Updated: 2022/05/24 11:47:25 by kkaczoro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <unistd.h>
# include <stdlib.h>

# include <stdio.h> //remove later

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE=10
# endif

char	*get_next_line(int fd);
size_t	ft_strlen(const char *s);
void	*ft_memchr(const void *s, int c, size_t n);
size_t	ft_strlcpy(char *dst, const char *src, size_t size);
void	*ft_memmove(void *dest, const void *src, size_t n);
void	*ft_memset(void *s, int c, size_t n);

#endif