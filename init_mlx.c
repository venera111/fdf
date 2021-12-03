/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_mlx.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qestefan <qestefan@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/01 14:57:06 by qestefan          #+#    #+#             */
/*   Updated: 2021/12/03 16:25:30 by qestefan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/fdf.h"

int	deal_key(int key, t_fdf *data)
{
	ft_printf("%d\n", key);
	if (key == UP)
		data->y_shift -= 100;
	if (key == DOWN)
		data->y_shift += 100;
	if (key == RIGHT)
		data->x_shift -= 100;
	if (key == LEFT)
		data->x_shift += 100;
	mlx_clear_window(data->mlx_ptr, data->win_ptr);
	draw(data);
	return (0);
}

void	init_mlx_func(t_fdf *data)
{
	data->mlx_ptr = mlx_init();
	data->win_ptr = mlx_new_window(data->mlx_ptr, WIDTH, HEIGHT, PROGRAMM_NAME);
	data->zoom = 30;
	draw(data);
	mlx_key_hook(data->win_ptr, deal_key, data);
	mlx_loop(data->mlx_ptr);
}
