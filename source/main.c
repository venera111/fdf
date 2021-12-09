/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qestefan <qestefan@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/28 10:47:54 by qestefan          #+#    #+#             */
/*   Updated: 2021/12/09 15:26:03 by qestefan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fdf.h>

int	main(int argc, char **argv)
{
	t_fdf	*data;

	if (argc == 2)
	{
		data = (t_fdf *)malloc(sizeof(t_fdf));
		struct_fill(data);
		read_file(argv[1], data);
		colors(data);
		zoom_re(data);
		window(data);
	}
	else
		error_map(ERR_INPUT, EXIT_FAILURE);
	return (0);
}

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
	data->z_zoom = 0.01;
}

void	zoom_re(t_fdf *data)
{
	if ((WIDTH - MENU) / data->width / 4 > HEIGHT / data->height / 4)
		data->zoom = HEIGHT / data->height / 4;
	else
		data->zoom = (WIDTH - MENU) / data->width / 4;
	if (data->zoom < 1)
		data->zoom = 2;
}

void	zoom_z(t_fdf *data, int key)
{
	if (key == KEY_PLUS_Z)
		data ->z_zoom += 1;
	if (key == KEY_MINUS_Z)
		data->z_zoom -= 1;
	if (data->img)
		mlx_destroy_image(data->mlx, data->img);
	data->img = mlx_new_image(data->mlx, WIDTH, HEIGHT);
	data->addr = mlx_get_data_addr(data->img, &data->bits_per_pixel,
			&data->line_length, &data->endian);
	draw_map(data);
}
