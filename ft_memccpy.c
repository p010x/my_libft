/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcottet <pcottet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/14 15:04:47 by pcottet           #+#    #+#             */
/*   Updated: 2020/10/14 15:29:16 by pcottet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void        *ft_memccpy(void *dst, const void *src, int c, size_t n)
{
    size_t i;

    i = 0;
    while (n--)
    {
        dst[i] = src[i];
        if ((unsigned char)src[i] == (unsigned char c))
        {
            i++;
            return (&dst[i]);
        }
    }
    return (NULL);
}