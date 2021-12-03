/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_file.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qestefan <qestefan@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/28 10:44:48 by qestefan          #+#    #+#             */
/*   Updated: 2021/12/03 16:24:45 by qestefan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/fdf.h"

int	get_width(char *line)
{
	int	width;

	width = 0;
	width = ft_wdcounter(line, ' ');
	return (width);
}

int	get_height(char	*file_name, t_fdf *data)
{
	int		fd;
	int		height;
	char	*line;
	int		tmp;

	fd = open(file_name, O_RDONLY);
	if (fd < 0)
		ft_perror(file_name);
	height = 0;
	tmp = 0;
	while (get_next_line(fd, &line) > 0)
	{
		data->width = get_width(line);
		free(line);
		if (!tmp)
			tmp = data->width;
		if (data->width != tmp)
			error_map(ERR_AXES, 3);
		height++;
	}
	free(line);
	close(fd);
	return (height);
}

void	fill_matrix(int *z_line, char *line)
{
	char	**nums;
	int		i;

	nums = ft_split(line, ' ');
	i = 0;
	while (nums[i])
	{
		z_line[i] = ft_atoi(nums[i]);
		free(nums[i]);
		i++;
	}
	free(nums);
	nums = NULL;
}

void	read_file(char *file_name, t_fdf *data)
{
	int		i;
	int		fd;
	char	*line;

	data->height = get_height(file_name, data);
	data->z_matrix = (int **)malloc(sizeof(int *) * (data->height + 1));
	i = 0;
	while (i < data->height)
	{
		data->z_matrix[i] = (int *)malloc(sizeof(int) * (data->width + 1));
		i++;
	}
	i = 0;
	fd = open(file_name, O_RDONLY);
	while (get_next_line(fd, &line) > 0)
	{
		fill_matrix(data->z_matrix[i], line);
		free(line);
		i++;
	}
	free(line);
	close(fd);
}
