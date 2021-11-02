/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjoosten <mjoosten@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/01 14:53:38 by mjoosten          #+#    #+#             */
/*   Updated: 2021/11/02 17:42:04 by mjoosten         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <limits.h>
#include <unistd.h>

#include <stdio.h>

static int	ft_linelen(char *buf);
static void	ft_rmline(char *buf);
static char	*ft_strsjoin(t_list **lst);
static int	ft_strslen(t_list **lst);

void	printlist(t_list **lst)
{
	t_list	*ptr;
	int		i;

	i = 0;
	ptr = *lst;
	while (ptr)
	{
		printf("LST[%d]: %s\n", i, ptr->content);
		i++;
		ptr = ptr->next;
	}
}

char	*get_next_line(int fd)
{
	static char	buf[BUFFER_SIZE + 1];
	char		*str;
	int			bytes_read;
	t_list		*lst;

	if (fd < 0 || fd > OPEN_MAX || *buf == 127)
		return (0);
	if (*buf)
		ft_lstadd_back(&lst, ft_lstnew(ft_strdup(buf)));
	while (ft_linelen(buf) == -1)
	{
		bytes_read = read(fd, buf, BUFFER_SIZE);
		if (bytes_read < 0)
			return (0);
		if (bytes_read < BUFFER_SIZE)
			buf[bytes_read] = 127;
		ft_lstadd_back(&lst, ft_lstnew(ft_strdup(buf)));
		//printlist(&lst);
	}
	ft_rmline(buf);
	str = ft_strsjoin(&lst);
	ft_lstclear(&lst);
	if (!str || !*str)
	{
		free(str);
		return (0);
	}
	return (str);
}

static void	ft_rmline(char *buf)
{
	int	i;
	int	len;

	i = 0;
	len = ft_linelen(buf);
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

static int	ft_linelen(char *buf)
{
	int		i;

	i = 0;
	while (buf[i])
	{
		if (buf[i] == '\n')
			return (i + 1);
		if (buf[i] == 127)
			return (i);
		i++;
	}
	return (-1);
}

static char	*ft_strsjoin(t_list **lst)
{
	char	*str;
	char	*start;
	t_list	*ptr;
	int		i;

	str = malloc(ft_strslen(lst) + 1);
	if (!str)
		return (0);
	start = str;
	ptr = *lst;
	while (ptr)
	{
		i = 0;
		while (ptr->content[i])
		{
			if (ptr->content[i] == 127)
				break ;
			*str++ = *((char *)ptr->content + i);
			if (ptr->content[i] == '\n')
				break ;
			i++;
		}
		ptr = ptr->next;
	}
	*str = 0;
	return (start);
}

static int	ft_strslen(t_list **lst)
{
	t_list	*ptr;
	int		len;
	int		i;

	len = 0;
	ptr = *lst;
	while (ptr)
	{
		i = 0;
		while (ptr->content[i])
		{
			if (ptr->content[i] == '\n')
				return (len + 1);
			if (ptr->content[i] == 127)
				return (len);
			i++;
			len++;
		}
		ptr = ptr->next;
	}
	return (len);
}
