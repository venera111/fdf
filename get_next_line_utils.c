/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qestefan <qestefan@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/23 19:25:49 by qestefan          #+#    #+#             */
/*   Updated: 2021/12/02 12:01:58 by qestefan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/get_next_line.h"

size_t	ft_strlen_gnl(const char *s)
{
	const char	*begin;

	begin = s;
	while (*s)
		s++;
	return ((size_t)(s - begin));
}

char	*ft_strdup_gnl(char const *str)
{
	char	*result;
	size_t	i;

	result = (char *)malloc(sizeof(char) * (ft_strlen_gnl(str) + 1));
	if (result)
	{
		i = 0;
		while (str[i])
		{
			result[i] = str[i];
			i++;
		}
		result[i] = '\0';
	}
	return (result);
}

char	*ft_substr_gnl(char const *s, unsigned int start, size_t len)
{
	char	*result;
	size_t	i;

	if (!s || len <= 0 || start >= ft_strlen_gnl(s))
		return (NULL);
	if (ft_strlen_gnl(s + start) < len)
		len = ft_strlen_gnl(s + start);
	result = (char *)malloc(sizeof(char) * (len + 1));
	if (!result)
		return (NULL);
	i = 0;
	while (s[i] && i < len)
		result[i++] = s[start++];
	result[i] = '\0';
	return (result);
}

char	*ft_strjoin_gnl(char const *s1, char const *s2)
{
	char	*result;
	size_t	i;
	size_t	j;

	if (!s1 || !s2)
		return (NULL);
	result = (char *)malloc(sizeof(char) * (ft_strlen_gnl(s1)
				+ ft_strlen_gnl(s2) + 1));
	if (!result)
		return (NULL);
	i = 0;
	j = 0;
	while (s1[j])
		result[i++] = s1[j++];
	j = 0;
	while (s2[j])
		result[i++] = s2[j++];
	result[i] = '\0';
	return (result);
}
