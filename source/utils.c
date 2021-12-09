/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qestefan <qestefan@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/04 20:35:42 by qestefan          #+#    #+#             */
/*   Updated: 2021/12/09 15:26:31 by qestefan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fdf.h>

double	private_distances(int z, int min, int max)
{
	double	scope;
	double	delta;

	scope = max - min;
	delta = z - min;
	if (scope == 0)
		return (1.0);
	else
		return (delta / scope);
}

int	sign(int x, int y)
{
	if (x < y)
		return (1);
	else
		return (-1);
}
