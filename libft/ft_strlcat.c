/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qestefan <qestefan@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/11 16:46:13 by qestefan          #+#    #+#             */
/*   Updated: 2021/10/11 16:46:14 by qestefan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t	dst2;
	size_t	src2;
	size_t	i;

	dst2 = ft_strlen(dst);
	src2 = ft_strlen(src);
	i = 0;
	if (dstsize < dst2 + 1)
		return (dstsize + src2);
	if (dstsize > dst2 + 1)
	{
		while (src[i] && dst2 + i + 1 < dstsize)
		{
			dst[dst2 + i] = src[i];
			i++;
		}
	}
	dst[dst2 + i] = '\0';
	return (dst2 + src2);
}
