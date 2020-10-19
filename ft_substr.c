/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcottet <pcottet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/12 21:01:00 by pcottet           #+#    #+#             */
/*   Updated: 2020/10/19 17:57:10 by pcottet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_substr(char const *s, unsigned int start, size_t len)
{
	char		*ret_str;
	size_t		i;
	size_t		j;

	if (!s || start > (unsigned int)ft_strlen(s))
		return ("\0");
	i = 0;
	while (s[i + start] && i < len)
		i++;
	if (!(ret_str = malloc(sizeof(*s) * (i + 1))))
		return (NULL);
	j = 0;
	while (i)
	{
		ret_str[j++] = s[start++];
		i--;
	}
	ret_str[j] = '\0';
	return (ret_str);
}
