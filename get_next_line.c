/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abaur <abaur@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/04 16:19:44 by abaur             #+#    #+#             */
/*   Updated: 2020/01/02 14:59:12 by abaur            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

#include <unistd.h>
#include <stdio.h>

int		get_next_line(int fd, char **line)
{
	static char	buffer[BUFFER_SIZE];
	int			i;
	int			err;

	err = 1;
	i = 0;
	while(i < BUFFER_SIZE)
		buffer[i++] = '\0';
	i = 0;
	while (i < (BUFFER_SIZE - 2) &&  0 < err)
	{
		err = read(fd, &buffer[i], 1);
		i++;
		if (buffer[i] == '\n' || buffer[i] == EOF)
			break;
	}
		i++;

	*line = (char*)buffer;
	return (err > 0 ? 1 : err);
}
