/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcottet <pcottet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/14 15:12:38 by pcottet           #+#    #+#             */
/*   Updated: 2020/10/16 01:14:37 by pcottet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void		*memmove(void *dst, const void *src, size_t len)
{
	void	*buffer;

	buffer = NULL;
	if (len)
		buffer = malloc(len);
	if (buffer)
	{
		ft_memcpy(buffer, src, len);
		ft_memcpy(dst, buffer, len);
	}
	return (dst);
}
