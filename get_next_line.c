/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkaczoro <kkaczoro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/19 18:35:38 by kkaczoro          #+#    #+#             */
/*   Updated: 2022/05/24 17:21:10 by kkaczoro         ###   ########.fr       */
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

	//printf("-buffer at beginning f call: %s\n", buffer);
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
		//printf("bambam");
		return (next_line);
	}
	else
	{
		temp = malloc(sizeof(char) * (BUFFER_SIZE) + 1);//allocation likely unnecessary
		if (temp == NULL)
			return (NULL);
		//printf("entering last case function\n");
		(void)ft_strlcpy(temp, buffer, ft_strlen(buffer) + 1);
		//printf("--temp last case before read: %s\n", temp);
		len_next = read(fd, buffer, BUFFER_SIZE);//change name of len_next to more intuivitive in the diff function 
		//printf("--temp last case after read: %s\n", temp);
		if (len_next <= 0)
		{
			(void)ft_memset(buffer, '\0', BUFFER_SIZE);
			return (temp);
		}
		//printf("before rec\n");
		new_line = get_next_line(fd);//dont forget to free
		//printf("--temp last case after GNL call: %s\n", temp);
		//printf("new_line after GNL call: %s\n", new_line);
		if (new_line == NULL)
		{
			new_line = malloc(sizeof(char));
			if (new_line == NULL)
				return (NULL);
			new_line[0] = '\0';
		}
		//printf("new_line after NULL check: %s\n", new_line);
		next_line = malloc(sizeof(char) * (BUFFER_SIZE + ft_strlen(new_line)) + 1);//if split into different functions: change new_line name to smth more easy to comprehend
		if (next_line == NULL)
		{
			free (temp);
			free (new_line);
			return (NULL);
		}
		//printf("next_line before 2 strlcpu: %s\n", next_line);
		//printf("--temp before 2 strlcpu: %s\n", temp);
		(void)ft_strlcpy(next_line, temp, BUFFER_SIZE + 1);
		(void)ft_strlcpy(next_line + BUFFER_SIZE, new_line, ft_strlen(new_line) + 1);
		free (temp);
		free (new_line);
		//printf("next_line after rec: %s\n", next_line);
		return (next_line);
	}
}

// char	*get_next_line(int fd)
// {
// 	static char	buffer[BUFFER_SIZE];
// 	char		*new_line;
// 	char		*next_line;
// 	int			len_next;
// 	char		*temp;

// 	printf("-buffer at beginning f call: %s\n", buffer);
// 	if (BUFFER_SIZE <= 0 || fd < 0
// 		|| (ft_strlen(buffer) == 0 && read(fd, buffer, BUFFER_SIZE) <= 0))
// 		return (NULL);
// 	new_line = ft_memchr(buffer, '\n', BUFFER_SIZE);
// 	if (new_line)
// 	{
// 		new_line++;
// 		next_line = malloc(sizeof(char) * (new_line - buffer) + 1);
// 		if (next_line == NULL)
// 			return (NULL);
// 		(void)ft_strlcpy(next_line, buffer, new_line - buffer + 1);
// 		next_line[new_line - buffer] = '\0';
// 		len_next = ft_strlen(next_line);
// 		(void)ft_memmove(buffer, buffer + (new_line - buffer),
// 			BUFFER_SIZE - len_next);
// 		(void)ft_memset(buffer + (BUFFER_SIZE - len_next), '\0', len_next);
// 		return (next_line);
// 	}
// 	else if (ft_strlen(buffer) != BUFFER_SIZE)
// 	{
// 		next_line = malloc(sizeof(char) * (ft_strlen(buffer)) + 1);
// 		if (next_line == NULL)
// 			return (NULL);
// 		(void)ft_strlcpy(next_line, buffer, ft_strlen(buffer) + 1);
// 		(void)ft_memset(buffer, '\0', BUFFER_SIZE);
// 		printf("bambam");
// 		return (next_line);
// 	}
// 	else
// 	{
// 		temp = malloc(sizeof(char) * (BUFFER_SIZE) + 1);//allocation likely unnecessary
// 		if (temp == NULL)
// 			return (NULL);
// 		printf("entering last case function\n");
// 		(void)ft_strlcpy(temp, buffer, ft_strlen(buffer) + 1);
// 		printf("--temp last case before read: %s\n", temp);
// 		len_next = read(fd, buffer, BUFFER_SIZE);//change name of len_next to more intuivitive in the diff function 
// 		printf("--temp last case after read: %s\n", temp);
// 		if (len_next <= 0)
// 			return (NULL);
// 		printf("before rec\n");
// 		new_line = get_next_line(fd);//dont forget to free
// 		printf("--temp last case after GNL call: %s\n", temp);
// 		printf("new_line after GNL call: %s\n", new_line);
// 		if (new_line == NULL)
// 		{
// 			new_line = malloc(sizeof(char));
// 			if (new_line == NULL)
// 				return (NULL);
// 			new_line[0] = '\0';
// 		}
// 		printf("new_line after NULL check: %s\n", new_line);
// 		next_line = malloc(sizeof(char) * (BUFFER_SIZE + ft_strlen(new_line)) + 1);//if split into different functions: change new_line name to smth more easy to comprehend
// 		if (next_line == NULL)
// 		{
// 			free (temp);
// 			free (new_line);
// 			return (NULL);
// 		}
// 		printf("next_line before 2 strlcpu: %s\n", next_line);
// 		printf("--temp before 2 strlcpu: %s\n", temp);
// 		(void)ft_strlcpy(next_line, temp, BUFFER_SIZE + 1);
// 		(void)ft_strlcpy(next_line + BUFFER_SIZE, new_line, ft_strlen(new_line) + 1);
// 		free (temp);
// 		free (new_line);
// 		printf("next_line after rec: %s\n", next_line);
// 		return (next_line);
// 	}
// }