/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjoosten <mjoosten@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/01 14:49:37 by mjoosten          #+#    #+#             */
/*   Updated: 2021/11/01 16:37:33 by mjoosten         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

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

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*str;
	char	*start;

	if (!s1 || !s2)
		return (0);
	str = (char *)malloc(ft_strlen(s1) + ft_strlen(s2) + 1);
	if (!str)
		return (0);
	start = str;
	while (*s1)
		*str++ = *s1++;
	while (*s2)
		*str++ = *s2++;
	*str = 0;
	return (start);
}

size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize)
{
	int	len;

	len = ft_strlen(src);
	if (!dstsize)
		return (len);
	while (*src && --dstsize)
		*dst++ = *src++;
	*dst = 0;
	return (len);
}

size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}
