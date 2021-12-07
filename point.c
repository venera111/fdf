/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   point.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qestefan <qestefan@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/04 19:29:19 by qestefan          #+#    #+#             */
/*   Updated: 2021/12/07 21:51:31 by qestefan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/fdf.h"

static void	zoom_point(t_point *p, t_fdf *data)
{
	p->x *= data->zoom;
	p->y *= data->zoom;
	p->z *= data->z_zoom;
}

static void	shift_point(t_point *p, t_fdf *data)
{
	p->x = p->x + data->offset_x + data->shift_x + MENU;
	p->y = p->y + data->offset_y + data->shift_y;
}

t_point	give_point(t_point p, t_fdf *data)
{
	zoom_point(&p, data);
	p.x -= (data->width * data->zoom) / 2;
	p.y -= (data->height * data->zoom) / 2;
	x_rotate(&p.y, &p.z, data->alpha);
	y_rotate(&p.x, &p.z, data->beta);
	z_rotate(&p.x, &p.y, data->gamma);
	if (data->iso)
		iso_3d(&p.x, &p.y, p.z);
	shift_point(&p, data);
	return (p);
}
