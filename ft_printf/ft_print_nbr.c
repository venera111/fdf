/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_nbr.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qestefan <qestefan@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/22 16:11:06 by qestefan          #+#    #+#             */
/*   Updated: 2021/10/22 23:24:03 by qestefan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_print_int(t_flags *f)
{
	char	*s;
	int		size;
	int		number;

	number = va_arg(f->ap, int);
	f->printed = f->char_num;
	if (!(number || f->precision))
		s = 0;
	else
		s = ft_itoa(number);
	size = ft_strlen(s);
	if (!(f->minus) && f->width > ft_max(f->precision, size))
		ft_width(f, ft_max(size, f->precision), (f->zero && !f->dot));
	f->char_num += write(1, "+", (number >= 0 && f->plus));
	if (*s == '-')
		f->char_num += write(1, "-", ((*s) == '-'));
	f->char_num += write(1, " ", (number >= 0 && f->space && !(f->plus)));
	size -= (number < 0);
	ft_precision(f, size, 1);
	f->char_num += write(1, s + (*s == '-'), ft_strlen(s + (*s == '-')));
	f->printed = f->char_num - f->printed;
	if (f->minus)
		ft_width(f, f->printed, 0);
	free(s);
	ft_reset_flags(f);
}

void	ft_print_uint(t_flags *flags)
{
	char			*str;
	int				size;
	unsigned int	number;

	number = va_arg(flags->ap, unsigned int);
	if (number == 0 && flags->precision == 0)
		str = 0;
	else
		str = ft_u_itoa(number);
	size = ft_strlen(str);
	if (!(flags->minus) && flags->width > ft_max(flags->precision, size))
		ft_width(flags, size, (flags->zero && !flags->dot));
	ft_precision(flags, size, 1);
	flags->char_num += write(1, str, size);
	if (flags->minus)
		ft_width(flags, size, 0);
	free(str);
	ft_reset_flags(flags);
}

void	ft_print_hex(t_flags *flags, int input)
{
	char			*str;
	int				size;
	unsigned int	number;
	int				temp;

	number = va_arg(flags->ap, unsigned int);
	if (number == 0 && flags->precision == 0)
		str = 0;
	else
		str = ft_itoa_hex(number);
	size = ft_strlen(str);
	if (input)
		ft_str_toupper(str);
	temp = ft_max(size, flags->precision) + (2 * (flags->octo));
	if (!(flags->minus) && flags->width > temp)
		ft_width(flags, temp, 0);
	ft_hash(flags, input);
	ft_precision(flags, size, 1);
	flags->char_num += write(1, str, size);
	if (flags->minus)
		ft_width(flags, temp, 0);
	free(str);
	ft_reset_flags(flags);
}

void	ft_print_address(t_flags *flags)
{
	char			*str;
	int				size;
	unsigned long	number;

	number = va_arg(flags->ap, unsigned long);
	str = ft_l_itoa_hex(number);
	size = ft_strlen(str);
	if (!(flags->minus))
		ft_width(flags, size + 2, 0);
	flags->char_num += write(1, "0x", 2);
	ft_precision(flags, size, 1);
	flags->char_num += write(1, str, size);
	if (flags->minus)
		ft_width(flags, size + 2, 0);
	free(str);
	ft_reset_flags(flags);
}

void	ft_print_percent(t_flags *flags)
{
	flags->char_num += write(1, "%", 1);
	ft_reset_flags(flags);
}
