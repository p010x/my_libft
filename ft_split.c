/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcottet <pcottet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/12 22:59:37 by pcottet           #+#    #+#             */
/*   Updated: 2020/10/16 01:16:55 by pcottet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int			ft_count_words(char const *s, char c)
{
	int		i;
	int		count_words;

	i = 0;
	count_words = 0;
	while (s[i])
	{
		while (s[i] == c && s[i])
			i++;
		if (s[i] != c && s[i])
		{
			count_words++;
			while (s[i] != c && s[i])
				i++;
		}
	}
	return (count_words);
}

char		**ft_split(char const *s, char c)
{
	char	**ret_strs;
	int		i;
	int		index;
	int		start;

	if (!(ret_strs = malloc(sizeof(*ret_strs) * (ft_count_words(s, c) + 1))))
		return (NULL);
	i = 0;
	index = 0;
	while (s[i])
	{
		while (s[i] == c && s[i])
			i++;
		if (s[i] != c && s[i])
		{
			start = i;
			while (s[i] != c && s[i])
				i++;
			if (!(ret_strs[index++] = ft_substr(s, start, i - start)))
				return (NULL);
		}
	}
	ret_strs[ft_count_words(s, c)] = NULL;
	return (ret_strs);
}
