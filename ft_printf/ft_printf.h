/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qestefan <qestefan@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/22 16:12:48 by qestefan          #+#    #+#             */
/*   Updated: 2021/11/30 13:20:37 by qestefan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdlib.h>
# include <unistd.h>
# include <stdarg.h>
# include "../libft/libft.h"

typedef struct s_flags
{
	va_list	ap;

	int		char_num;

	int		zero;
	int		minus;
	int		plus;
	int		octo;
	int		space;

	int		width;
	int		precision;
	int		dot;
	int		printed;
}	t_flags;

int		ft_atoi(const char *str);
void	ft_str_toupper(char *str);
size_t	ft_strlen(const char *str);
void	ft_putchar(char c);
int		ft_putnstr(char *str, int n);
void	ft_putstr(char *str);
void	ft_init_flags(t_flags *flags);
void	ft_reset_flags(t_flags *flags);
void	ft_precision(t_flags *flags, int size, int zero);
void	ft_width(t_flags *flags, int size, int zero);
void	ft_hash(t_flags *flags, int input);
int		ft_max(int a, int b);
int		ft_min(int a, int b);
void	ft_print_int(t_flags *flags);
void	ft_print_uint(t_flags *flags);
void	ft_print_hex(t_flags *flags, int casse);
void	ft_print_address(t_flags *flags);
void	ft_print_char(t_flags *flags);
void	ft_print_string(t_flags *flags);
void	ft_print_percent(t_flags *flags);
int		ft_specifier(char c);
void	ft_print_type(t_flags *flags, char c);
int		ft_flag_search(t_flags *flags, const char *input);
int		ft_flag_dot(t_flags *flags, const char *input);
int		ft_parsing(t_flags *flags, const char *input);
int		ft_printf(const char *format, ...);
char	*ft_u_itoa(unsigned int n);
char	*ft_itoa_hex(unsigned int n);
char	*ft_l_itoa_hex(unsigned long n);
void	*ft_calloc(size_t count, size_t size);
void	*ft_memset(void *b, int c, size_t len);
char	*ft_strdup(const char *s1);

#endif
