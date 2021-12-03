/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parsing.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qestefan <qestefan@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/22 16:10:07 by qestefan          #+#    #+#             */
/*   Updated: 2021/10/22 21:47:01 by qestefan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_parsing(t_flags *flags, const char *symbol)
{
	int	index;

	index = ft_flag_search(flags, symbol);
	index += ft_flag_dot(flags, symbol + index);
	if (ft_specifier(symbol[index]))
		ft_print_type(flags, symbol[index]);
	else
	{
		ft_putchar('%');
		flags->char_num++;
		return (1);
	}
	return (index + 1);
}

int	ft_flag_search(t_flags *flags, const char *symbol)
{
	char	c;
	int		index;

	index = 0;
	c = symbol[index];
	while (c && (c == '0' || c == '-' || c == '#' || c == '+' || c == ' '))
	{
		if (c == '0')
			flags->zero = 1;
		if (c == '-')
			flags->minus = 1;
		if (c == '+')
			flags->plus = 1;
		if (c == '#')
			flags->octo = 1;
		if (c == ' ')
			flags->space = 1;
		c = symbol[++index];
	}
	if (c && ft_isdigit(c))
		flags->width = ft_atoi(&symbol[index]);
	while (c && ft_isdigit(c))
		c = symbol[++index];
	return (index);
}

int	ft_flag_dot(t_flags *flags, const char *symbol)
{
	char	c;
	int		index;

	index = 0;
	c = symbol[index];
	if (c && (c == '.'))
	{
		c = symbol[++index];
		flags->dot = 1;
		flags->precision = ft_atoi(&symbol[index]);
		while (c && ft_isdigit(c))
			c = symbol[++index];
	}
	return (index);
}

int	ft_specifier(char c)
{
	return (c == '%' || c == 'c' || c == 's' || c == 'p'
		|| c == 'd' || c == 'i' || c == 'u' || c == 'x' || c == 'X');
}

void	ft_print_type(t_flags *flags, char c)
{
	if (c == 'd' || c == 'i')
		ft_print_int(flags);
	else if (c == 'c')
		ft_print_char(flags);
	else if (c == 'u')
		ft_print_uint(flags);
	else if (c == 's')
		ft_print_string(flags);
	else if (c == 'p')
		ft_print_address(flags);
	else if (c == 'x')
		ft_print_hex(flags, 0);
	else if (c == 'X')
		ft_print_hex(flags, 1);
	else if (c == '%')
		ft_print_percent(flags);
}
