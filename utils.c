/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qestefan <qestefan@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/04 20:35:42 by qestefan          #+#    #+#             */
/*   Updated: 2021/12/05 17:00:18 by qestefan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/fdf.h"

int	find_z(t_fdf *data, int flag)
{
	int	i;
	int	z;

	i = 0;
	z = data->p[0].z;
	while (i < data->height * data->width)
	{
		if (!flag && z > data->p[i].z)
			z = data->p[i].z;
		else if (flag && z < data->p[i].z)
			z = data->p[i].z;
		i++;
	}
	return (z);
}

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
