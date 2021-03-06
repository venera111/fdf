/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qestefan <qestefan@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/28 18:13:09 by qestefan          #+#    #+#             */
/*   Updated: 2021/12/09 15:25:23 by qestefan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fdf.h>

void	my_mlx_pixel_put(t_fdf *data, int x, int y, int color)
{
	char	*dst;

	if (x >= MENU && y >= 0 && x < WIDTH && y < HEIGHT)
	{
		dst = data->addr + (y * data->line_length + x
				* (data->bits_per_pixel / 8));
		*(unsigned int *)dst = color;
	}
}

static void	draw_controls(t_fdf *data)
{
	int	y;

	y = 0;
	mlx_string_put(data->mlx, data->mlx_win, 10, y += 30, C_TEXT, M_MENU);
	mlx_string_put(data->mlx, data->mlx_win, 40, y += 30, C_TEXT, M_ZOOM_P);
	mlx_string_put(data->mlx, data->mlx_win, 40, y += 30, C_TEXT, M_ZOOM_M);
	mlx_string_put(data->mlx, data->mlx_win, 10, y += 40, C_TEXT, M_ROTATE);
	mlx_string_put(data->mlx, data->mlx_win, 40, y += 30, C_TEXT, M_X);
	mlx_string_put(data->mlx, data->mlx_win, 40, y += 30, C_TEXT, M_Y);
	mlx_string_put(data->mlx, data->mlx_win, 40, y += 30, C_TEXT, M_Z);
	mlx_string_put(data->mlx, data->mlx_win, 10, y += 40, C_TEXT, M_PROJ);
	mlx_string_put(data->mlx, data->mlx_win, 40, y += 30, C_TEXT, M_PARAL);
	mlx_string_put(data->mlx, data->mlx_win, 40, y += 30, C_TEXT, M_ISO);
}

static void	draw_background(t_fdf *data)
{
	int	*img;
	int	i;

	img = (int *)data->addr;
	i = 0;
	while (i < WIDTH * HEIGHT)
	{
		img[i] = COLOR_BACK;
		i++;
	}
}

static void	draw_line(t_point p1, t_point p2, t_fdf *data)
{
	t_point	d;
	t_point	s;
	t_point	tmp;

	d.x = abs(p2.x - p1.x);
	d.y = abs(p2.y - p1.y);
	s.x = sign(p1.x, p2.x);
	s.y = sign(p1.y, p2.y);
	d.z = d.x - d.y;
	tmp = p1;
	while (tmp.x != p2.x || tmp.y != p2.y)
	{
		my_mlx_pixel_put(data, tmp.x, tmp.y, coloring(tmp, p1, p2, d));
		s.z = d.z * 2;
		if (s.z > -d.y)
		{
			d.z -= d.y;
			tmp.x += s.x;
		}
		if (s.z < d.x)
		{
			d.z += d.x;
			tmp.y += s.y;
		}
	}
}

void	draw_map(t_fdf *data)
{
	int	x;
	int	y;

	draw_background(data);
	y = 0;
	while (y < data->height)
	{
		x = 0;
		while (x < data->width)
		{
			if (x < data->width - 1)
				draw_line(give_point(data->p[x + y * data->width], data),
					give_point(data->p[x + 1 + y * data->width], data), data);
			if (y < data->height - 1)
				draw_line(give_point(data->p[x + y * data->width], data),
					give_point(data->p[x + (y + 1) * data->width], data), data);
			x++;
		}
		y++;
	}
	mlx_put_image_to_window(data->mlx, data->mlx_win, data->img, 0, 0);
	draw_controls(data);
}
