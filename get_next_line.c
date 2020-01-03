/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abaur <abaur@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/04 16:19:44 by abaur             #+#    #+#             */
/*   Updated: 2020/01/03 16:28:13 by abaur            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>

static short	remalloc(char **result, size_t *size){
	char	*src;
	size_t	srclen;
	size_t	i;

	src = *result;
	srclen = *size;
	*result = malloc (*size);
	if (!*result)
		return (0);
	*size += BUFFER_SIZE;
	i=0;
	while(i < *size + BUFFER_SIZE)
	{
		if (i < srclen)
			(*result)[i] = src[i];
		else
			(*result)[i] = '\0';
		i++;
	}
	free(src);
	return 1;
}

int				get_next_line(int fd, char **line)
{
	size_t	linesize;
	size_t	i;
	short	err;

	if (NULL == (*line = malloc(BUFFER_SIZE)))
		return (-1);
	linesize = BUFFER_SIZE;
	i = 0;
	while (i < BUFFER_SIZE)
	{
		(*line)[i++] = 0;
	}
	i = 0;
	while(0 > (err = read(fd, (*line) + i, BUFFER_SIZE)))
	{
		i++;
		if (i == linesize && !remalloc(line, &linesize))
			return (-1);
		if ((*line)[i - 1] == '\n')
			break;
	}
	return err;
}
