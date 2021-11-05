/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjoosten <mjoosten@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/01 14:50:38 by mjoosten          #+#    #+#             */
/*   Updated: 2021/11/05 16:23:55 by mjoosten         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H

# include <stdlib.h>
# include <unistd.h>

typedef struct s_list
{
	char			*content;
	struct s_list	*next;
}					t_list;

char	*get_next_line(int fd);

t_list	*ft_lstnew(char *content);
t_list	*ft_lstadd_back(t_list **lst, t_list *new);
char	*ft_lstclear(t_list **lst);
char	*ft_strdup(const char *s1);
size_t	ft_strlen(const char *s);

#endif