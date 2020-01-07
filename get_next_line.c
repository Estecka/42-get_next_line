/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abaur <abaur@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/04 16:19:44 by abaur             #+#    #+#             */
/*   Updated: 2020/01/07 10:37:20 by abaur            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

#include <unistd.h>
#include <stdio.h>

/*
** Allocates a string capable of holding the entirety of the chained buffers,
** plus a Null terminator.
*/

static char	*bufmalloc(t_gnlbuffer *first)
{
	t_gnlbuffer	*last;
	size_t		len;
	size_t		i;

	i = 0;
	last = first;
	while(last->next)
	{
		last = last->next;
		i++;
	}
	len = i * BUFFER_SIZE;
	i = 0;
	while(last->content[i] && last->content[i] != '\n')
		i++;
	len += i;
	return (malloc(len + 1));
}

int	get_next_line(int fd, char **line)
{
	return (0);
}
