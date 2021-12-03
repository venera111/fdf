/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qestefan <qestefan@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/11 16:47:01 by qestefan          #+#    #+#             */
/*   Updated: 2021/10/11 16:47:03 by qestefan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_compare(char c, const char *str)
{
	size_t	index;

	index = 0;
	while (str[index])
	{
		if (str[index] == c)
			return (1);
		else
			++index;
	}
	return (0);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*result;
	size_t	i;
	size_t	k;
	size_t	end;

	i = 0;
	k = 0;
	if (!s1 || !set)
		return ((void *)0);
	if (!ft_strlen(set))
		return (ft_strdup(s1));
	end = ft_strlen(s1) - 1;
	while (ft_compare(s1[i], set) && s1[i])
		++i;
	if (i == ft_strlen(s1) || !ft_strlen(s1))
		return (ft_calloc(1, 1));
	while (ft_compare(s1[end], set) && end)
		--end;
	result = (char *)malloc(sizeof(char) * (end - i + 2));
	if (result == (void *)0)
		return ((void *)0);
	while (i <= end)
		result[k++] = s1[i++];
	result[k] = '\0';
	return (result);
}
