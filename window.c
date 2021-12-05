/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qestefan <qestefan@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/04 17:01:58 by qestefan          #+#    #+#             */
/*   Updated: 2021/12/05 22:07:58 by qestefan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/fdf.h"

static int	close_window(void)
{
	exit(EXIT_FAILURE);
}

int	key_hook(int key, t_fdf *data)
{
	if (key == KEY_ESC)
		exit(EXIT_SUCCESS);
	if (key == KEY_DOWN || key == KEY_LEFT || key == KEY_RIGHT || key == KEY_UP)
		move(key, data);
	if (key == KEY_PLUS || key == KEY_MINUS)
		zoom(key, data);
	if (key == KEY_Q || key == KEY_W || key == KEY_A || key == KEY_S
		|| key == KEY_Z || key == KEY_X)
		rotate(key, data);
	if (key == KEY_I)
		iso(data);
	if (key == KEY_P)
		paral(data);
	return (0);
}

void	hooks_handler(t_fdf *data)
{
	mlx_hook(data->mlx_win, 2, 0, key_hook, data);
	mlx_hook(data->mlx_win, 17, 0, close_window, data);
}

void	window(t_fdf *data)
{
	data->mlx = mlx_init();
	if (!data->mlx)
		ft_perror("failed to initialize the mlx library");
	data->mlx_win = mlx_new_window(data->mlx, WIDTH, HEIGHT, PROGRAMM_NAME);
	if (!data->mlx_win)
		ft_perror("failed to create a window");
	data->img = mlx_new_image(data->mlx, WIDTH, HEIGHT);
	if (!data->img)
		ft_perror("img");
	data->addr = mlx_get_data_addr(data->img, &data->bits_per_pixel,
			&data->line_length, &data->endian);
	if (!data->addr)
		ft_perror("addr");
	draw_map(data);
	hooks_handler(data);
	mlx_loop(data->mlx);
}
