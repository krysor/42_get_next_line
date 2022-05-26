/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkaczoro <kkaczoro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/19 18:36:05 by kkaczoro          #+#    #+#             */
/*   Updated: 2022/05/26 19:36:41 by kkaczoro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

void	*ft_memchr(const void *s, int c, size_t n)
{
	size_t	i;

	i = 0;
	while (i < n)
	{
		if (((unsigned char *)s)[i] == (unsigned char)c)
			return ((void *)(s + i));
		i++;
	}
	return (0);
}

size_t	ft_strlcpy(char *dst, const char *src, size_t size)
{
	size_t	i;

	i = 0;
	if (size > 0)
	{
		while (i < (size - 1) && src[i])
		{
			dst[i] = src[i];
			i++;
		}
		dst[i] = '\0';
	}
	while (src[i])
		i++;
	return (i);
}

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	int		i;
	char	*temp;

	if (dest == NULL && src == NULL)
		return (NULL);
	i = 0;
	temp = (char *)src;
	if (src > dest)
	{
		while (i < (int)n)
		{
			((char *)dest)[i] = temp[i];
			i++;
		}	
	}
	else
	{
		while (i < (int)n)
		{
			((char *)dest)[n - 1 - i] = temp[n - 1 - i];
			i++;
		}	
	}
	return (dest);
}

void	*ft_memset(void *s, int c, size_t n)
{
	int	i;

	i = 0;
	if (s == NULL && c == 0)
		return (NULL);
	while (i < (int)n)
	{
		((char *)s)[i] = c;
		i++;
	}
	return (s);
}
