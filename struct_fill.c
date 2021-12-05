/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct_fill.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qestefan <qestefan@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/04 16:42:04 by qestefan          #+#    #+#             */
/*   Updated: 2021/12/05 22:08:31 by qestefan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/fdf.h"

void	struct_fill(t_fdf *data)
{
	data->width = 0;
	data->height = 0;
	data->p = NULL;
	data->mlx = NULL;
	data->mlx_win = NULL;
	data->img = NULL;
	data->addr = NULL;
	data->bits_per_pixel = 0;
	data->line_length = 0;
	data->endian = 0;
	data->offset_x = (WIDTH - MENU) / 2;
	data->offset_y = HEIGHT / 2;
	data->shift_x = 0;
	data->shift_y = 0;
	data->zoom = 1;
	data->alpha = 0;
	data->beta = 0;
	data->gamma = 0;
	data->iso = 1;
}
