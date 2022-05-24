/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkaczoro <kkaczoro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/19 18:35:38 by kkaczoro          #+#    #+#             */
/*   Updated: 2022/05/24 14:59:36 by kkaczoro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_line(int fd)
{
	static char	buffer[BUFFER_SIZE];
	char		*new_line;
	char		*next_line;
	int			len_next;
	char		*temp;

	printf("buffer beginning: %s\n", buffer);
	if (BUFFER_SIZE <= 0 || fd < 0
		|| (ft_strlen(buffer) == 0 && read(fd, buffer, BUFFER_SIZE) <= 0))
		return (NULL);
	new_line = ft_memchr(buffer, '\n', BUFFER_SIZE);
	if (new_line)
	{
		new_line++;
		next_line = malloc(sizeof(char) * (new_line - buffer) + 1);
		if (next_line == NULL)
			return (NULL);
		(void)ft_strlcpy(next_line, buffer, new_line - buffer + 1);
		next_line[new_line - buffer] = '\0';
		len_next = ft_strlen(next_line);
		(void)ft_memmove(buffer, buffer + (new_line - buffer),
			BUFFER_SIZE - len_next);
		(void)ft_memset(buffer + (BUFFER_SIZE - len_next), '\0', len_next);
		return (next_line);
	}
	else if (ft_strlen(buffer) != BUFFER_SIZE)
	{
		next_line = malloc(sizeof(char) * (ft_strlen(buffer)) + 1);
		if (next_line == NULL)
			return (NULL);
		(void)ft_strlcpy(next_line, buffer, ft_strlen(buffer) + 1);
		(void)ft_memset(buffer, '\0', BUFFER_SIZE);
		return (next_line);
	}
	else
	{
		temp = malloc(sizeof(char) * (BUFFER_SIZE) + 1);//allocation likely unnecessary
		if (temp == NULL)
			return (NULL);
		printf("heyhay\n");
		(void)ft_strlcpy(temp, buffer, ft_strlen(buffer) + 1);
		len_next = read(fd, buffer, BUFFER_SIZE);//change name of len_next to more intuivitive in the diff function 
		if (len_next <= 0)
			return (NULL);
		new_line = get_next_line(fd);//dont forget to free
		if (new_line == NULL)
		{
			new_line = malloc(sizeof(char));
			if (new_line == NULL)
				return (NULL);
			new_line[0] = '\0';
		}
		next_line = malloc(sizeof(char) * (BUFFER_SIZE + ft_strlen(new_line)) + 1);//if split into different functions: change new_line name to smth more easy to comprehend
		if (next_line == NULL)
		{
			free (temp);
			free (new_line);
			return (NULL);
		}
		(void)ft_strlcpy(next_line, temp, BUFFER_SIZE + 1);
		(void)ft_strlcpy(next_line + BUFFER_SIZE, new_line, ft_strlen(new_line) + 1);
		free (temp);
		free (new_line);
		return (next_line);
	}
}
