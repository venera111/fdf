/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   colors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qestefan <qestefan@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/04 14:40:32 by qestefan          #+#    #+#             */
/*   Updated: 2021/12/05 16:59:25 by qestefan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/fdf.h"

static int	color_gradient(double private)
{
	if (private <= 0.2)
		return (LVL_1);
	else if (private <= 0.4)
		return (LVL_2);
	else if (private <= 0.6)
		return (LVL_3);
	else if (private <= 0.8)
		return (LVL_4);
	else
		return (LVL_5);
}

void	colors(t_fdf *data)
{
	int		z_min;
	int		z_max;
	int		i;
	double	private;

	i = 0;
	z_min = find_z(data, 0);
	z_max = find_z(data, 1);
	while (i < data->height * data->width)
	{
		private = private_distances(data->p[i].z, z_min, z_max);
		data->p[i].color = color_gradient(private);
		i++;
	}
}

static int	light(int start, int end, double perc)
{
	return ((int)((1 - perc) * start + perc * end));
}

int	coloring(t_point cur, t_point p1, t_point p2, t_point d)
{
	int		red;
	int		green;
	int		blue;
	double	perc;

	if (cur.color == p2.color)
		return (cur.color);
	if (d.x > d.y)
		perc = private_distances(cur.x, p1.x, p2.x);
	else
		perc = private_distances(cur.y, p1.y, p2.y);
	red = light((p1.color >> 16) & 0xFF, (p2.color >> 16) & 0xFF, perc);
	green = light((p1.color >> 8) & 0xFF, (p2.color >> 8) & 0xFF, perc);
	blue = light(p1.color & 0xFF, p2.color & 0xFF, perc);
	return ((red << 16) | (green << 8) | blue);
}
