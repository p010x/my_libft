/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcottet <pcottet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/13 00:00:56 by pcottet           #+#    #+#             */
/*   Updated: 2020/10/16 01:19:00 by pcottet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char			*ret_str;
	unsigned int	i;

	if (!(ret_str = ft_strdup(s)) || !f || !s)
		return (NULL);
	i = 0;
	while (s[i])
	{
		ret_str[i] = (*f)(i, s[i]);
		i++;
	}
	return (ret_str);
}
