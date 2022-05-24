/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkaczoro <kkaczoro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/19 18:35:38 by kkaczoro          #+#    #+#             */
/*   Updated: 2022/05/23 18:20:21 by kkaczoro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_line(int fd)
{
	char		*next_line;
	static char	buffer[BUFFER_SIZE];

	if (BUFFER_SIZE <= 0 || fd < 0 || buffer == NULL)
		return (NULL);
	return (next_line);
}
