/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_wdcounter.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qestefan <qestefan@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/01 21:31:06 by qestefan          #+#    #+#             */
/*   Updated: 2021/12/01 21:31:13 by qestefan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_wdcounter(char *line, char ch)
{
	int	count_words;

	count_words = 0;
	while (*line == ch && *line)
		++line;
	while (*line)
	{
		++count_words;
		while (*line != ch && *line)
			++line;
		while (*line == ch && *line)
			++line;
	}
	return (count_words);
}
