/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcottet <pcottet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/12 18:48:08 by pcottet           #+#    #+#             */
/*   Updated: 2020/10/16 01:18:30 by pcottet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t		ft_strlcpy(char *dst, const char *src, size_t dstsize)
{
	size_t	i;

	i = 0;
	if (!dst || !src)
		return (0);
	while (src[i])
	{
		if (i < dstsize - 1 && dstsize)
			dst[i] = src[i];
		else if (i == dstsize - 1 && dstsize)
			dst[i] = '\0';
		i++;
	}
	return (i);
}
