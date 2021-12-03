/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_hex.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qestefan <qestefan@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/22 16:10:26 by qestefan          #+#    #+#             */
/*   Updated: 2021/10/22 16:10:26 by qestefan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static char	*ft_zero_string(void)
{
	char	*string;

	string = (char *)malloc(sizeof(char) * 2);
	string[0] = '0';
	string[1] = 0;
	return (string);
}

static char	ft_hex(int n)
{
	if (n < 10)
		return ('0' + n);
	else
		return ('a' + n - 10);
}

char	*ft_itoa_hex(unsigned int n)
{
	unsigned int	i;
	char			*string;
	unsigned int	len;

	if (n == 0)
		return (ft_zero_string());
	i = 0;
	len = n;
	while (len > 15)
	{
		len /= 16;
		i++;
	}
	string = (char *)ft_calloc(i + 2, sizeof(char));
	len = n;
	while (len > 0)
	{
		string[i] = ft_hex(len % 16);
		len /= 16;
		i--;
	}
	return (string);
}

char	*ft_l_itoa_hex(unsigned long n)
{
	unsigned long	i;
	char			*string;
	unsigned long	len;

	if (n == 0)
		return (ft_zero_string());
	i = 0;
	len = n;
	while (len > 15)
	{
		len /= 16;
		i++;
	}
	string = (char *)ft_calloc(i + 2, sizeof(char));
	len = n;
	while (len > 0)
	{
		string[i] = ft_hex(len % 16);
		len /= 16;
		i--;
	}
	return (string);
}
