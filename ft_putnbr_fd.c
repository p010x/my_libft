/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcottet <pcottet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/13 03:46:27 by pcottet           #+#    #+#             */
/*   Updated: 2020/10/13 04:10:38 by pcottet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void        ft_putnbr_fd(int n, int fd)
{
    long nb;

    nb = n; 
    if (n < 0)
    {
        ft_putchar_fd('-', fd);
        nb = -nb;
    }
    if (nb >= 10)
        ft_putnbr_fd(nb / 10, fd);
    ft_putchar_fd((nb % 10) + '0', fd);
}