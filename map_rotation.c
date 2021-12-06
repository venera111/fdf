/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_rotation.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qestefan <qestefan@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/04 20:39:01 by qestefan          #+#    #+#             */
/*   Updated: 2021/12/06 10:33:03 by qestefan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/fdf.h"

void	x_rotate(int *y, int *z, float alpha)
{
	int	tmp_y;

	tmp_y = *y;
	*y = tmp_y * cos(alpha) + *z * sin(alpha);
	*z = -tmp_y * sin(alpha) + *z * cos(alpha);
}

void	y_rotate(int *x, int *z, float beta)
{
	int	tmp_x;

	tmp_x = *x;
	*x = tmp_x * cos(beta) + *z * sin(beta);
	*z = -tmp_x * sin(beta) + *z * cos(beta);
}

void	z_rotate(int *x, int *y, float gamma)
{
	int	tmp_x;
	int	tmp_y;

	tmp_x = *x;
	tmp_y = *y;
	*x = tmp_x * cos(gamma) - tmp_y * sin(gamma);
	*y = tmp_x * sin(gamma) + tmp_y * cos(gamma);
}

void	iso_proj(int *x, int *y, int z)
{
	int	tmp_x;
	int	tmp_y;

	tmp_x = *x;
	tmp_y = *y;
	*x = (tmp_x - tmp_y) * cos(0.523599);
	*y = (tmp_x + tmp_y) * sin (0.523599) - z;
}
