/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qestefan <qestefan@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/04 20:21:36 by qestefan          #+#    #+#             */
/*   Updated: 2021/12/07 21:28:13 by qestefan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/fdf.h"

void	move(int key, t_fdf *data)
{
	if (key == KEY_DOWN)
		data->shift_y += 10;
	else if (key == KEY_UP)
		data->shift_y -= 10;
	else if (key == KEY_LEFT)
		data->shift_x -= 10;
	else if (key == KEY_RIGHT)
		data->shift_x += 10;
	draw_map(data);
}

void	zoom(int key, t_fdf *data)
{
	if (key == KEY_PLUS && data->zoom < __INT_MAX__)
		(data->zoom)++;
	else if (key == KEY_MINUS && data->zoom > 2)
		(data->zoom)--;
	draw_map(data);
}

void	rotate(int key, t_fdf *data)
{
	if (key == KEY_Q)
		data->alpha -= ANGLE;
	else if (key == KEY_W)
		data->alpha += ANGLE;
	else if (key == KEY_A)
		data->beta -= ANGLE;
	else if (key == KEY_S)
		data->beta += ANGLE;
	else if (key == KEY_Z)
		data->gamma -= ANGLE;
	else if (key == KEY_X)
		data->gamma += ANGLE;
	draw_map(data);
}

void	iso(t_fdf *data)
{
	data->iso = 1;
	data->alpha = 0;
	data->beta = 0;
	data->gamma = 0;
	draw_map(data);
}

void	paral(t_fdf *data)
{
	data->iso = 0;
	data->alpha = 0;
	data->beta = 0;
	data->gamma = 0;
	draw_map(data);
}
