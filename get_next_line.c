/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkaczoro <kkaczoro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/19 18:35:38 by kkaczoro          #+#    #+#             */
/*   Updated: 2022/05/24 11:28:39 by kkaczoro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_line(int fd)
{
	static char	buffer[BUFFER_SIZE];
	char		*new_line;
	char		*next_line;

	if (BUFFER_SIZE <= 0 || fd < 0
		|| (ft_strlen(buffer) == 0 && read(fd, buffer, BUFFER_SIZE) <= 0))
		return (NULL);
	new_line = ft_memchr(buffer, '\n', BUFFER_SIZE);
	if (new_line)
	{
		next_line = malloc(sizeof(char) * (new_line - buffer) + 2);
		if (next_line == NULL)
			return (NULL);
		(void)ft_strlcpy((char *)(next_line), buffer, new_line - buffer + 2);
		next_line[new_line - buffer + 1] = '\0';
		//printf("next_line: %s\n", next_line);
	}
	else
		(void)ft_strlen(buffer);
	return (next_line);
}
