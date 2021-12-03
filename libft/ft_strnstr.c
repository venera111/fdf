/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qestefan <qestefan@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/11 16:46:43 by qestefan          #+#    #+#             */
/*   Updated: 2021/10/11 16:46:44 by qestefan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	i;
	size_t	k;

	i = 0;
	if (!*needle)
		return ((char *)haystack);
	while (haystack[i] && i < len)
	{
		k = 0;
		while (haystack[i + k] == needle[k]
			&& haystack[i + k] && needle[k] && i + k < len)
			k++;
		if (!needle[k])
			return ((char *)(haystack + i));
		i++;
	}
	return ((void *)0);
}
