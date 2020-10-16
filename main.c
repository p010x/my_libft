/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcottet <pcottet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/16 09:11:17 by pcottet           #+#    #+#             */
/*   Updated: 2020/10/16 10:11:21 by pcottet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <ctype.h>
#include "libft.h"

int		ft_str_is_test(void)
{
	int		ok = 1;
	int		ft_ok = 1;
	char	str[] = {'A', 'Z', 'a', 'z', '0', '9', ' ', '~', '\0', '\t', '\n', '\r', '\v', 0, 255, -128, 127};
	int		i = 0;

	printf("Testing ft_isalpha\n");
	while (str[i])
	{
		if (isalpha(str[i]) != ft_isalpha(str[i]))
		{
			printf("KO : \"%c\"\t", str[i]);
			ok = 0;
			ft_ok = 0;
		}
		i++;
	}

	printf("%s\n", ft_ok ? "OK" : "\n!!!!!!!!!!ft_isalpha: KO");
	ft_ok = 1;
	i = 0;
	printf("Testing ft_digit\n");
	while (str[i])
	{
		if (isdigit(str[i]) != ft_isdigit(str[i]))
		{
			printf("KO : \"%c\"\t", str[i]);
			ok = 0;
			ft_ok = 0;
		}
		i++;
	}
	printf("%s\n", ft_ok ? "OK" : "\n!!!!!!!!!!ft_digit: KO");
	return (ok);
}

int		main(int ac, char **av)
{
	char	STR_IS[] = "STR_IS";
	if (ac == 1 || av[1] == STR_IS)
	{
		printf("STR_IS: %s", (ft_str_is_test() ? "OK" : "KO"));
	}
	return (0);
}
