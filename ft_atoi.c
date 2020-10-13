/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcottet <pcottet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/13 00:21:36 by pcottet           #+#    #+#             */
/*   Updated: 2020/10/13 03:10:46 by pcottet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int         ft_isspace(char c)
{
    return ((c == '\t' || c == '\r' || c == '\n' || c == '\v' ||
        c == '\f' || c == ' ') ? 1 : 0);
}

int         ft_atoi(const char *str)
{
    int     i;
    long    ret_value;
    long    sign;

    i = 0;
    sign = 1;
    ret_value = 0;
    while(ft_isspace(str[i]))
        i++;
    if (str[i] == '+')
        i++;
    else if (str[i] == '-')
    {
        -sign;
        i++;
    }
    while (ft_isdigit(str[i]))
    {
        ret_value *= 10;
        ret_value += (str[i] - '0');
        i++;
    }
    return ((int)(ret_value * sign));
}