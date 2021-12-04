/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   colors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qestefan <qestefan@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/04 14:40:32 by qestefan          #+#    #+#             */
/*   Updated: 2021/12/04 20:54:23 by qestefan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/fdf.h"

static int	find_z(t_fdf *data, int x)
{
	int	i;
	int	z;

	i = 0;
	z = data->p[0].z;
	while (i < data->height * data->width)
	{
		if (!x && z > data->p[i].z)
			z = data->p[i].z;
		else if (x && z < data->p[i].z)
			z = data->p[i].z;
		i++;
	}
	return (z);
}

static int	color_grad(double proc)
{
	if (proc <= 0.2)
		return (C_ZERO);
	else if (proc <= 0.4)
		return (C_MZ);
	else if (proc <= 0.6)
		return (C_MID);
	else if (proc <= 0.8)
		return (C_TM);
	else
		return (C_TOP);
}

void	colors(t_fdf *data)
{
	int		z_min;
	int		z_max;
	int		i;
	double	perc;

	i = 0;
	z_min = find_z(data, 0);
	z_max = find_z(data, 1);
	while (i < data->height * data->width)
	{
		perc = percent(data->p[i].z, z_min, z_max);
		data->p[i].color = color_grad(perc);
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
		perc = percent(cur.x, p1.x, p2.x);
	else
		perc = percent(cur.y, p1.y, p2.y);
	red = light((p1.color >> 16) & 0xFF, (p2.color >> 16) & 0xFF, perc);
	green = light((p1.color >> 8) & 0xFF, (p2.color >> 8) & 0xFF, perc);
	blue = light(p1.color & 0xFF, p2.color & 0xFF, perc);
	return ((red << 16) | (green << 8) | blue);
}
