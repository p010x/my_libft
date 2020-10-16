/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcottet <pcottet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/14 15:33:37 by pcottet           #+#    #+#             */
/*   Updated: 2020/10/16 03:26:01 by pcottet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int			ft_memcmp(const void *s1, const void *s2, size_t n)
{
	unsigned char	*s1_tmp;
	unsigned char	*s2_tmp;
	size_t	i;

	i = 0;
	s1_tmp = (unsigned char *)s1;
	s2_tmp = (unsigned char *)s2;
	while (n--)
	{
		if (s1_tmp[i] != s2_tmp[i])
			return (s1_tmp[i] - s2_tmp[i]);
	}
	return (0);
}
