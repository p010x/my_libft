/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcottet <pcottet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/14 15:27:04 by pcottet           #+#    #+#             */
/*   Updated: 2020/10/14 15:33:21 by pcottet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void        *ft_memchr(const void *s, int c, size_t n)
{
    size_t  i;

    i = 0;
    while (n--)
    {
        if ((unsigned char)s[i] == (unsigned char)c)
            return (s[i]);
        i++;
    }
    return (NULL);
}