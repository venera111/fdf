/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_file.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qestefan <qestefan@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/28 10:44:48 by qestefan          #+#    #+#             */
/*   Updated: 2021/12/09 15:26:16 by qestefan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fdf.h>

static void	get_coordinates(char *line, t_fdf *data, int j)
{
	int	i;
	int	flag;

	i = 0;
	flag = 1;
	while (*line)
	{
		if (*line != ' ' && flag)
		{
			data->p[j * data->width + i].x = i;
			data->p[j * data->width + i].y = j;
			data->p[j * data->width + i].z = ft_atoi(line);
			i++;
			flag = 0;
		}
		else if (*line == ' ')
			flag = 1;
		line++;
	}
}

static int	get_width(char *line)
{
	int	width;

	width = 0;
	width = ft_wdcounter(line, ' ');
	return (width);
}

static void	get_height(char *file_name, t_fdf *data)
{
	int		fd;
	char	*line;
	int		tmp;

	fd = open(file_name, O_RDONLY);
	if (fd < 0)
		ft_perror(file_name);
	tmp = 0;
	while (get_next_line(fd, &line) > 0)
	{
		data->width = get_width(line);
		free(line);
		if (!tmp)
			tmp = data->width;
		if (data->width != tmp)
			error_map(ERR_AXES, 3);
		(data->height)++;
	}
	free(line);
	if (data->width == 0)
		error_map(ERR_EMPTY, 2);
	close(fd);
}

void	read_file(char *file_name, t_fdf *data)
{
	int		j;
	int		fd;
	char	*line;

	get_height(file_name, data);
	data->p = (t_point *)malloc(sizeof(t_point) * data->width * data->height);
	if (!data->p)
		ft_perror("malloc points");
	fd = open(file_name, O_RDONLY);
	j = 0;
	while (get_next_line(fd, &line) > 0)
	{
		get_coordinates(line, data, j);
		free(line);
		j++;
	}
	close(fd);
}
