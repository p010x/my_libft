/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcottet <pcottet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/13 03:53:06 by pcottet           #+#    #+#             */
/*   Updated: 2020/10/14 14:54:30 by pcottet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void        *ft_calloc(size_t count, size_t size)
{
    char    *str;

    if (!(str = malloc(sizeof(*str) * (count * size))))
		  return (NULL);
    ft_bzero(str, (count * size));
    return (str);
}