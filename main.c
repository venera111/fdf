/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qestefan <qestefan@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/28 10:47:54 by qestefan          #+#    #+#             */
/*   Updated: 2021/12/05 18:22:03 by qestefan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/fdf.h"

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
		return (0);
	}
	error_map(ERR_INPUT, EXIT_FAILURE);
	return (0);
}
