/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjoosten <mjoosten@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/01 14:53:38 by mjoosten          #+#    #+#             */
/*   Updated: 2021/11/05 12:08:18 by mjoosten         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static int	ft_linelen(char *buf);
static void	ft_rmline(char *buf);
static char	*ft_strsjoin(t_list **lst);
static int	ft_strslen(t_list **lst);

char	*get_next_line(int fd)
{
	static char	buf[BUFFER_SIZE + 1];
	char		*str;
	int			bytes_read;
	t_list		*lst;

	if (read(fd, buf, 0) < 0 || *buf == 127)
		return (0);
	lst = 0;
	if (!ft_lstadd_back(&lst, ft_lstnew(ft_strdup(buf))))
		return (ft_lstclear(&lst));
	while (ft_linelen(buf) == -1)
	{
		bytes_read = read(fd, buf, BUFFER_SIZE);
		if (bytes_read < 0)
			return (0);
		if (bytes_read < BUFFER_SIZE)
			buf[bytes_read] = 127;
		if (!ft_lstadd_back(&lst, ft_lstnew(ft_strdup(buf))))
			return (ft_lstclear(&lst));
	}
	ft_rmline(buf);
	str = ft_strsjoin(&lst);
	ft_lstclear(&lst);
	return (str);
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
	buf[i] = 0;
}

static char	*ft_strsjoin(t_list **lst)
{
	char	*str;
	t_list	*ptr;
	int		i;

	if (!ft_strslen(lst))
		return (0);
	str = malloc(ft_strslen(lst) + 1);
	if (!str)
		return (0);
	ptr = *lst;
	while (ptr)
	{
		i = 0;
		while (ptr->content[i] && ptr->content[i] != 127)
		{
			*str++ = *((char *)ptr->content + i);
			if (ptr->content[i] == '\n')
				break ;
			i++;
		}
		ptr = ptr->next;
	}
	*str = 0;
	return (str - ft_strslen(lst));
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
		while (ptr->content[i] && ptr->content[i] != 127)
		{
			if (ptr->content[i] == '\n')
				return (len + 1);
			i++;
			len++;
		}
		ptr = ptr->next;
	}
	return (len);
}
