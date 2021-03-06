/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjoosten <mjoosten@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/01 14:49:37 by mjoosten          #+#    #+#             */
/*   Updated: 2021/11/05 12:08:48 by mjoosten         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

t_list	*ft_lstnew(char *content)
{
	t_list	*new;

	if (!content)
		return (0);
	new = (t_list *)malloc(sizeof(t_list));
	if (!new)
	{
		free(content);
		return (0);
	}
	new->content = content;
	new->next = 0;
	return (new);
}

t_list	*ft_lstadd_back(t_list **lst, t_list *new)
{
	t_list	*ptr;

	if (!new)
		return (0);
	ptr = *lst;
	if (ptr)
	{
		while (ptr->next)
			ptr = ptr->next;
		ptr->next = new;
	}
	else
		*lst = new;
	return (new);
}

char	*ft_lstclear(t_list **lst)
{
	t_list	*next;

	while (*lst)
	{
		free((*lst)->content);
		next = (*lst)->next;
		free(*lst);
		*lst = next;
	}
	*lst = 0;
	return (0);
}

char	*ft_strdup(const char *s1)
{
	char	*s2;
	int		len;

	len = ft_strlen(s1);
	s2 = malloc(len + 1);
	if (!s2)
		return (0);
	*(s2 + len) = 0;
	while (len--)
		*(s2 + len) = *(s1 + len);
	return (s2);
}

size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}
