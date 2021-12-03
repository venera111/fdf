/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qestefan <qestefan@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/28 10:47:54 by qestefan          #+#    #+#             */
/*   Updated: 2021/12/02 20:59:24 by qestefan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/fdf.h"

int	main(int argc, char **argv)
{
	t_fdf *data;

	if (argc == 2)
	{
		data = (t_fdf *)malloc(sizeof(t_fdf));
		read_file(argv[1], data);
		//add_map_colors(data);
		init_mlx_func(data);
		return (0);
	}
}
// gcc *.c libft/libft.a minilibx_macos/libmlx.a -lmlx -framework OpenGL -framework AppKit
