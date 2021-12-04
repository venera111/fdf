/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qestefan <qestefan@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/04 20:35:42 by qestefan          #+#    #+#             */
/*   Updated: 2021/12/04 20:54:42 by qestefan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/fdf.h"

double	percent(int cur, int min, int max)
{
	double	range;
	double	delta;

	range = max - min;
	delta = cur - min;
	if (range == 0)
		return (1.0);
	else
		return (delta / range);
}

int	sign(int x, int y)
{
	if (x < y)
		return (1);
	else
		return (-1);
}
