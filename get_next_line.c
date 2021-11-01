/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjoosten <mjoosten@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/01 14:53:38 by mjoosten          #+#    #+#             */
/*   Updated: 2021/11/01 16:38:53 by mjoosten         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <limits.h>
#include <unistd.h>

#include <stdio.h>

//#define BUFFER_SIZE 42

//static void	rmline(char *buf);

char	*get_next_line(int fd)
{
	static char	buf[BUFFER_SIZE + 1];
	char		*str;
	char		*tmp;

	if (fd < 0 || fd > OPEN_MAX)
		return (0);
	str = ft_strdup(buf);
	while (read(fd, buf, BUFFER_SIZE))
	{
		printf("BUF: %s\n", buf);
		tmp = ft_strjoin(str, buf);
		free(str);
		str = tmp;
		//rmline(buf);
	}
	if (!*str)
	{
		free(str);
		return (0);
	}
	return (str);
}
/*
static void	rmline(char *buf)
{
	int	i;
	int	len;

	i = 0;
	len = ft_strlen(buf);
	while (len + i < BUFFER_SIZE)
	{
		buf[i] = buf[len + i];
		i++;
	}
	while (i < BUFFER_SIZE)
	{
		buf[i] = 0;
		i++;
	}
}
*/