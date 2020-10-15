/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcottet <pcottet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/13 00:58:04 by pcottet           #+#    #+#             */
/*   Updated: 2020/10/16 01:08:54 by pcottet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_to_a(int n, int len, char *str)
{
	long	nb;

	nb = n;
	if (n < 0)
	{
		nb = -nb;
		str[0] = '-';
	}
	str[len--] = '\0';
	while (nb)
	{
		str[len--] = (nb % 10) + '0';
		nb /= 10;
	}
	return (str);
}

char		*ft_itoa(int n)
{
	long	nb;
	int		ret_str_len;
	char	*ret_str;

	if (!n)
		return ("0");
	ret_str_len = 0;
	nb = n;
	if (n < 0)
	{
		ret_str_len++;
		nb = -nb;
	}
	while (nb)
	{
		ret_str_len++;
		nb /= 10;
	}
	return ((ret_str = malloc(sizeof(*ret_str) * (ret_str_len + 1))) ?
		ft_to_a(n, ret_str_len, ret_str) : NULL);
}
