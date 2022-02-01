/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qestefan <qestefan@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/25 12:16:39 by qestefan          #+#    #+#             */
/*   Updated: 2021/12/09 15:25:48 by qestefan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <get_next_line.h>

static bool	ft_search_new_line(char *str)
{
	while (*str)
		if (*str++ == '\n')
			return (true);
	return (false);
}

static char	*ft_save_buffer(char *str, char *buffer)
{
	char	*temp;

	if (str)
	{
		temp = str;
		str = ft_strjoin_gnl(str, buffer);
		free(temp);
	}
	else
		str = ft_strdup_gnl(buffer);
	return (str);
}

static char	*ft_get_line_remainder(char **str)
{
	char	*temp;
	size_t	i;
	char	*line;

	if (!(*str))
		return (NULL);
	i = 0;
	while ((*str)[i] != '\n' && (*str)[i])
		i++;
	if (i < ft_strlen_gnl(*str))
	{
		temp = *str;
		line = ft_substr_gnl(*str, 0, ++i);
		*str = ft_substr_gnl(*str, i, ft_strlen_gnl(*str));
		free(temp);
	}
	else
	{
		line = *str;
		*str = NULL;
	}
	return (line);
}

int	get_next_line(int fd, char **line)
{
	char		*buffer;
	int			readed;
	static char	*str;

	if (BUFFER_SIZE <= 0 || fd < 0)
		return (-1);
	buffer = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!buffer)
		return (-1);
	readed = read(fd, buffer, BUFFER_SIZE);
	while (readed > 0)
	{
		buffer[readed] = '\0';
		str = ft_save_buffer(str, buffer);
		if (ft_search_new_line(str))
			break ;
		readed = read(fd, buffer, BUFFER_SIZE);
	}
	free(buffer);
	*line = ft_get_line_remainder(&str);
	return (readed);
}
