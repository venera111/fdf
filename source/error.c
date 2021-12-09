/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qestefan <qestefan@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/02 18:32:43 by qestefan          #+#    #+#             */
/*   Updated: 2021/12/09 15:25:30 by qestefan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fdf.h>

void	ft_perror(char *str)
{
	perror(str);
	exit(EXIT_FAILURE);
}

void	error_map(char *str, int count)
{
	write(2, ERR_MAP, ft_strlen_gnl(ERR_MAP));
	write(2, str, ft_strlen_gnl(str));
	exit(count);
}
