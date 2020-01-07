/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abaur <abaur@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/04 16:20:24 by abaur             #+#    #+#             */
/*   Updated: 2020/01/07 10:51:33 by abaur            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# define BUFFER_SIZE 32

typedef s_gnlbuffer t_gnlbuffer;
struct s_gnlbuffer {
	t_gnlbuffer *next;
	char **content;
};

int		get_next_char(int fd, char *dst);
int		get_next_line(int fd, char **line);

#endif
