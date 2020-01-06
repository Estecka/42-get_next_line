/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abaur <abaur@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/04 16:19:44 by abaur             #+#    #+#             */
/*   Updated: 2020/01/06 15:20:12 by abaur            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

#include <unistd.h>
#include <stdio.h>

/*
** Computes the total lenght of the chained buffers,
** and allocates a string capable holding it all.
*/

static size_t	bufmalloc(t_gnlbuffer *first, char **result)
{
	int 		len;
	t_gnlbuffer	*last;
	size_t			i;

	len = 0;
	*last = first;
	while((*last = last*->next))
		len++;
	len *= BUFFER_SIZE;
	i = 0;
	while(last->content[i] && last->content[i] != '\n')
		i++;
	len += i;
	**result = malloc(len);
	return (len);
}

int	get_next_line(int fd, char **line)
{
	return (0);
}
