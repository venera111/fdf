/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zoom.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qestefan <qestefan@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/04 19:37:47 by qestefan          #+#    #+#             */
/*   Updated: 2021/12/05 17:25:18 by qestefan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/fdf.h"

void zoom_re(t_fdf *data)
{
	if ((WIDTH - MENU) / data->width / 4 > HEIGHT / data->height / 4)
		data->zoom = HEIGHT / data->height / 4;
	else
		data->zoom = (WIDTH - MENU) / data->width / 4;
	if (data->zoom < 1)
		data->zoom = 2;
}
