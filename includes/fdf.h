/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qestefan <qestefan@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/28 10:39:18 by qestefan          #+#    #+#             */
/*   Updated: 2021/12/02 19:05:15 by qestefan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H
# include "key.h"

# ifndef COLOR_H
# define COLOR_H
# define GREEN 0x008000
# define WHITE 0xffffff
# define WIDTH 2000
# define HEIGHT 1200
# define PROGRAMM_NAME "FDF"
# endif

#include "../libft/libft.h"
#include "../minilibx_macos/mlx.h"
#include "../includes/get_next_line.h"
#include <fcntl.h>
#include "../ft_printf/ft_printf.h"
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include "../includes/error.h"

typedef struct s_coord
{
	int		z;
	int		z1;
}			t_coord;

typedef struct s_fdf
{
	int		width;
	int		height;
	int		**z_matrix;
	int		zoom;
	int		color;
	int		x_shift;
	int		y_shift;

	void	*mlx_ptr;
	void	*win_ptr;
}				t_fdf;

void	read_file(char *file_name, t_fdf *data);
void	bresenham(float x, float y, float x1, float y1, t_fdf *data);
void	draw(t_fdf *data);

/* Initialization */
void	init_mlx_func(t_fdf *data);

/* Error */
void	ft_perror(char *str);
void	error_map(char *str, int count);

#endif
