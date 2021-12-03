/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qestefan <qestefan@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/11 16:45:40 by qestefan          #+#    #+#             */
/*   Updated: 2021/10/13 20:30:38 by qestefan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_wordlen(const char *s, char c)
{
	int	i;

	i = 0;
	while (s[i] != c && s[i])
		++i;
	return (i);
}

static int	count_words(const char *s, char c)
{
	int		num_words;

	num_words = 0;
	while (*s == c && *s)
		++s;
	while (*s)
	{
		++num_words;
		while (*s != c && *s)
			++s;
		while (*s == c && *s)
			++s;
	}
	return (num_words);
}

static char	*word_dupe(const char *s, char c)
{
	int		i;
	int		len;
	char	*word;

	i = 0;
	len = ft_wordlen(s, c);
	word = (char *)malloc(sizeof(char) * (len + 1));
	if (!word)
		return ((void *)0);
	word[len] = '\0';
	while (i < len)
	{
		word[i] = s[i];
		++i;
	}
	return (word);
}

static void	fill_words(char **array, const char *s, char c)
{
	int		word_index;

	word_index = 0;
	while (*s == c && *s)
		++s;
	while (*s != '\0')
	{
		array[word_index] = word_dupe(s, c);
		if (!array[word_index] && array[0])
		{
			while (word_index != -1)
			{
				free(array[word_index]);
				array[word_index] = (void *)0;
				--word_index;
			}
			return ;
		}
		++word_index;
		while (*s != c && *s)
			++s;
		while (*s == c && *s)
			++s;
	}
}

char	**ft_split(char const *s, char c)
{
	int		num_words;
	char	**array;

	if (s == (void *)0)
		return ((void *)0);
	num_words = count_words(s, c);
	array = (char **)malloc(sizeof(char *) * (num_words + 1));
	if (!array)
		return ((void *)0);
	array[num_words] = (void *)0;
	fill_words(array, s, c);
	return (array);
}
