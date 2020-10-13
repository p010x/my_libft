/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcottet <pcottet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/13 04:20:49 by pcottet           #+#    #+#             */
/*   Updated: 2020/10/13 04:41:18 by pcottet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void        *ft_memset(void *b, int c, size_t len)
{
    size_t i;

    i = 0;
    while (len--)
        b[i++] = (unsigned char)c;
    return (b);
}
