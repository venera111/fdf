/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qestefan <qestefan@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/28 10:39:18 by qestefan          #+#    #+#             */
/*   Updated: 2021/12/04 20:59:20 by qestefan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# define MENU 200
# define WIDTH 2000
# define HEIGHT 1200
# define ANGLE 0.05
# define PROGRAMM_NAME "FDF"

# include <math.h>
# include <stdio.h>
# include <stdlib.h>
# include "../libft/libft.h"
# include "../ft_printf/ft_printf.h"
# include "../minilibx_macos/mlx.h"
# include "../includes/get_next_line.h"
# include "../includes/error.h"
# include "../includes/color.h"
# include "../includes/menu.h"
# include "../includes/key.h"

typedef struct s_point
{
	int	x;
	int	y;
	int	z;
	int	color;
}				t_point;

typedef struct s_fdf
{
	int		width;
	int		height;
	void	*mlx;
	void	*mlx_win;
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		size_line;
	int		endian;
	int		iso;
	int		zoom;
	int		offset_x;
	int		offset_y;
	int		shift_y;
	int		shift_x;
	float	alpha;
	float	beta;
	float	gamma;
	void	*mlx_ptr;
	void	*win_ptr;
	t_point	*p;
}				t_fdf;

/* Filling in the structure */
void	struct_fill(t_fdf *data);

/* Filling out the card */
void	read_file(char *file_name, t_fdf *data);
void	draw(t_fdf *data);

/* Colors */
void	colors(t_fdf *data);
int		coloring(t_point cur, t_point p1, t_point p2, t_point d);

/* Zoom */
void	zoom_re(t_fdf *data);

/* Initializing the window */
void	window(t_fdf *data);

/* Draw */
void	draw_map(t_fdf *data);

/* Pointers */
t_point	give_point(t_point p, t_fdf *data);

/* Error */
void	ft_perror(char *str);
void	error_map(char *str, int count);

/* Utils */
int		sign(int x, int y);
double	percent(int cur, int min, int max);

/* Map rotation */
void	x_rotate(int *y, int *z, float alpha);
void	y_rotate(int *x, int *z, float beta);
void	z_rotate(int *x, int *y, float gamma);
void	iso_proj(int *x, int *y, int z);
void	move(int key, t_fdf *data);
void	zoom(int key, t_fdf *data);
void	rotate(int key, t_fdf *data);
void	iso(t_fdf *data);
void	paral(t_fdf *data);

#endif
