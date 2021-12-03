/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qestefan <qestefan@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/22 16:10:47 by qestefan          #+#    #+#             */
/*   Updated: 2021/10/22 16:10:47 by qestefan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static char	*ft_zero_string(void)
{
	char	*dest;

	dest = (char *)malloc(sizeof(char) * 2);
	dest[0] = '0';
	dest[1] = '\0';
	return (dest);
}

// static long int	ft_ngtv(long int n)
// {
// 	if (n < 0)
// 		n = -n;
// 	return (n);
// }

// static int	ft_count(long int n)
// {
// 	int	len;

// 	len = 0;
// 	if (n <= 0)
// 		len = 1;
// 	while (n != 0)
// 	{
// 		n = n / 10;
// 		len++;
// 	}
// 	return (len);
// }

// char	*ft_itoa(int n)
// {
// 	int		len;
// 	int		character;
// 	char	*string;

// 	if (n == 0)
// 		return (ft_zero_string());
// 	if (n < 0)
// 		character = -1;
// 	else
// 		character = 1;
// 	len = ft_count(n);
// 	string = (char *)malloc(sizeof(char) * len + 1);
// 	if (!string)
// 		return (NULL);
// 	string[len] = '\0';
// 	while (--len >= 0)
// 	{
// 		string[len] = ft_ngtv(n % 10) + '0';
// 		n = ft_ngtv(n / 10);
// 	}
// 	if (character == -1)
// 		string[0] = '-';
// 	return (string);
// }

char	*ft_u_itoa(unsigned int n)
{
	unsigned int	i;
	char			*string;
	unsigned int	len;

	if (n == 0)
		return (ft_zero_string());
	i = 0;
	len = n;
	while (len > 9)
	{
		len /= 10;
		i++;
	}
	string = (char *)ft_calloc(i + 2, sizeof(char));
	len = n;
	while (len > 0)
	{
		string[i] = (len % 10) + '0';
		len /= 10;
		i--;
	}
	return (string);
}
