/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abaur <abaur@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/04 16:19:44 by abaur             #+#    #+#             */
/*   Updated: 2020/01/07 14:30:06 by abaur            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>

/*
** Allocates a string capable of holding the entirety of the chained buffers,
** plus a Null terminator.
** @param t_gnlbuffer* first The first link of the buffer chain
** @return The allocated string, or NULL if the allocation fails.
*/

static char	*bufmalloc(t_gnlbuffer *first)
{
	t_gnlbuffer	*last;
	size_t		len;
	size_t		i;

	i = 0;
	last = first;
	while (last->next)
	{
		last = last->next;
		i++;
	}
	len = i * BUFFER_SIZE;
	i = 0;
	while (last->content[i] && last->content[i] != '\n')
		i++;
	len += i;
	return (malloc(len + 1));
}

/*
** Merge all chained buffers into a single string, and frees the buffer.
** Buffers are freed even if the allocation fails.
** @param t_gnlbuffer* first The first link of the buffer chain.
** @return The concatenated string, or NULL if the allocation fails.
*/

static char	*concatbuff(t_gnlbuffer *first)
{
	t_gnlbuffer *current;
	t_gnlbuffer *prev;
	char		*result;
	char		*cursor;
	size_t		i;

	result = bufmalloc(current);
	i = 0;
	cursor = result;
	current = first;
	while (current && current->content[i])
	{
		if (result)
			*(cursor++) = current->content[i++];
		if (!result || i == BUFFER_SIZE)
		{
			i = 0;
			prev = current;
			current = current->next;
			free(prev);
		}
	}
	if (result)
		*cursor = '\0';
	return (result);
}

/*
** Buffers the given file, and fetches the next character on each call.
** @param int fd The file descriptor to read.
** @param char* dst The adress where to write the character.
** @return
**  1 if a character is read
**  0 upon reading EOF, EOF is output to dst.
** -1 in case of error
*/

int			get_next_char(int fd, char *dst)
{
	static char		buffer[BUFFER_SIZE] = { 0 };
	static size_t	offset = BUFFER_SIZE;
	static int		readsize = BUFFER_SIZE;

	if (offset >= readsize)
	{
		offset = 0;
		readsize = read(fd, buffer, BUFFER_SIZE);
		if (readsize == 0)
			*dst = EOF;
		if (readsize < 1)
			return (readsize);
	}
	*dst = buffer[offset++];
	return (1);
}

int	get_next_line(int fd, char **line)
{
	return (0);
}
