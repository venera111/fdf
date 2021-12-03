/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qestefan <qestefan@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/08 15:42:43 by qestefan          #+#    #+#             */
/*   Updated: 2021/10/13 20:29:32 by qestefan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static long int	ft_ngtv(long int n)
{
	if (n < 0)
		n = -n;
	return (n);
}

static int	ft_count(long int n)
{
	int	len;

	len = 0;
	if (n <= 0)
		len = 1;
	while (n != 0)
	{
		n = n / 10;
		len++;
	}
	return (len);
}

char	*ft_itoa(int n)
{
	int		len;
	int		character;
	char	*string;

	if (n < 0)
		character = -1;
	else
		character = 1;
	len = ft_count(n);
	string = (char *)malloc(sizeof(char) * len + 1);
	if (!string)
		return ((void *)0);
	string[len] = '\0';
	while (--len >= 0)
	{
		string[len] = ft_ngtv(n % 10) + '0';
		n = ft_ngtv(n / 10);
	}
	if (character == -1)
		string[0] = '-';
	return (string);
}
