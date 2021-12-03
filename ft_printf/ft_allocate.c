/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qestefan <qestefan@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/22 16:11:28 by qestefan          #+#    #+#             */
/*   Updated: 2021/10/22 16:11:28 by qestefan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*ft_strdup(const char *s1)
{
	char	*result;
	int		i;

	i = 0;
	while (s1[i])
		i++;
	result = (char *)malloc(sizeof(char) * i + 1);
	if (!result)
		return ((void *)0);
	i = 0;
	while (*s1)
		result[i++] = *s1++;
	result[i] = '\0';
	return (result);
}

void	*ft_calloc(size_t count, size_t size)
{
	void	*result;

	result = malloc(count * size);
	if (!result)
		return ((void *)0);
	ft_memset(result, 0, count * size);
	return (result);
}
