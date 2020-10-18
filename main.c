/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcottet <pcottet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/16 09:11:17 by pcottet           #+#    #+#             */
/*   Updated: 2020/10/18 14:22:31 by pcottet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <ctype.h>
#include <limits.h>
#include "libft.h"
#define INT_MIN_STR "-2147483648"
#define INT_MAX_STR "2147483647"
#define STR_IS "STR_IS"
#define STR_TO "STR_TO"
#define STR "STR"

// ----------UTILS----------
char	**er_msg = (char *[]){"Unknown fonction name", "KO shouldn't segfault", "KO should segfault"};
int		er_no;
int		check_diff_error(char *ft_name, int option);

// ----------STR_IS----------
int		ft_str_is_test(void)
{
	int		ok = 1;
	int		ft_ok = 1;
	char	str[] = {'A', 'Z', 'a', 'z', '0', '9', ' ', '~', '\0', '\t', '\n', '\r', '\v', '\b', 0, 255, -128, 127, '%', -42};
	int		i = 0;

	// ALPHA
	printf("\tTesting ft_isalpha\n");
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
	printf("%s\n", ft_ok ? "\tOK" : "\n!!!!!!!!!!ft_isalpha: KO");
	// DIGIT
	ft_ok = 1;
	i = 0;
	printf("\tTesting ft_digit\n");
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
	printf("%s\n", ft_ok ? "\tOK" : "\n!!!!!!!!!!ft_digit: KO");
	// ALPHANUM
	ft_ok = 1;
	i = 0;
	printf("\tTesting ft_isalnum\n");
	while (str[i])
	{
		if (isalnum(str[i]) != ft_isalnum(str[i]))
		{
			printf("KO : \"%c\"\t", str[i]);
			ok = 0;
			ft_ok = 0;
		}
		i++;
	}
	printf("%s\n", ft_ok ? "\tOK" : "\n!!!!!!!!!!ft_isalnum: KO");
	// ASCII
	ft_ok = 1;
	i = 0;
	printf("\tTesting ft_isascii\n");
	while (str[i])
	{
		if (isascii(str[i]) != ft_isascii(str[i]))
		{
			printf("KO : \"%c\"\t", str[i]);
			ok = 0;
			ft_ok = 0;
		}
		i++;
	}
	printf("%s\n", ft_ok ? "\tOK" : "\n!!!!!!!!!!isascii: KO");
	// PRINT
	ft_ok = 1;
	i = 0;
	printf("\tTesting ft_isprint\n");
	while (str[i])
	{
		if (isprint(str[i]) != ft_isprint(str[i]))
		{
			printf("KO : \"%c\"\t", str[i]);
			ok = 0;
			ft_ok = 0;
		}
		i++;
	}
	printf("%s\n", ft_ok ? "\tOK" : "\n!!!!!!!!!!isprint: KO");
	return (ok);
}
// ----------STR_TO----------
int		ft_str_to_test(void)
{
	int		ok = 1;
	int		ft_ok = 1;
	char	str[] = {'A', 'Z', 'a', 'z', '0', '9', ' ', '~', '\0', '\t', '\n', '\r', '\v', '\b',
					0, 255, -128, 127, '%', -42};
	char	**strs = (char *[]){"0", "124", "-124", INT_MIN_STR, INT_MAX_STR, "addazd", "", "a1",
					"1a", "-a1", "\011", "\t+1", "\n-1", "\r1", "\va", "\b", "000000000000000110",
					"  \t\n  \r\r\v\f-899",	"     32 ", "++876", "\200123", "123\200", "-+1", "+-1",
					"\n          42 24", "42jk ", "      --s8", " -sfecf", "  +442", "  -4232", NULL};
	int		tab[] = {0, 124, -124, INT32_MIN, INT32_MAX};
	char	**tab_str = (char *[]){"0", "124", "-124", INT_MIN_STR, INT_MAX_STR , NULL};
	int		i = 0;

	// LOWER
	printf("\tTesting ft_tolower\n");
	while (str[i])
	{
		if (tolower(str[i]) != ft_tolower(str[i]))
		{
			printf("KO : \"%c\"\t", str[i]);
			ok = 0;
			ft_ok = 0;
		}
		i++;
	}
	printf("%s\n", ft_ok ? "\tOK" : "\n!!!!!!!!!!ft_tolower: KO");
	// UPPER
	ft_ok = 1;
	i = 0;
	printf("\tTesting ft_toupper\n");
	while (str[i])
	{
		if (toupper(str[i]) != ft_toupper(str[i]))
		{
			printf("KO : \"%c\"\t", str[i]);
			ok = 0;
			ft_ok = 0;
		}
		i++;
	}
	printf("%s\n", ft_ok ? "\tOK" : "\n!!!!!!!!!!ft_toupper: KO");
	// ATOI
	ft_ok = 1;
	i = 0;
	printf("\tTesting ft_atoi\n");
	while (strs[i])
	{
		if (atoi(strs[i]) != ft_atoi(strs[i]))
		{
			printf("KO : \"%s\"\t", strs[i]);
			ok = 0;
			ft_ok = 0;
		}
		i++;
	}
	printf("\t\tTesting error handling");
	er_no = check_diff_error("ft_atoi", 0);
	if (er_no >= 0)
	{
		ft_ok = 0;
		ok = 0;
		printf(" -> %s", er_msg[er_no]);
	}
	printf("%s\n", ft_ok ? "\n\tOK" : "\n!!!!!!!!!!ft_atoi: KO");
	// ITOA
	ft_ok = 1;
	i = 0;
	printf("\tTesting ft_itoa\n");
	while (tab_str[i])
	{
		if (strcmp(tab_str[i], ft_itoa(tab[i])))
		{
			printf("KO : \"int: %d <-> int_str: %s <-> itoa: %s\"\t", tab[i], tab_str[i], ft_itoa(tab[i]));
			ok = 0;
			ft_ok = 0;
		}
		i++;
	}
	printf("%s\n", ft_ok ? "\tOK" : "\n!!!!!!!!!!ft_itoa: KO");
	return (ok);
}

int		ft_str_test(void)
{
	int		ok = 1;
	int		ft_ok = 1;
	int		i = 0;
	char	**strs = (char *[]){"0", "124", "-124", INT_MIN_STR, INT_MAX_STR, "addazd", "", "a1",
				"1a", "-a1", "\011", "\t+1", "\n-1", "\r1", "\va", "\b", "000000000000000110",
				"  \t\n  \r\r\v\f-899",	"     32 ", "++876", "\200123", "123\200", "-+1", "+-1",
				"\n          42 24", "42jk ", "      --s8", " -sfecf", "  +442", "  -4232", NULL};
	// LEN
	printf("\tTesting ft_strlen\n");
	while (strs[i])
	{
		if (strlen(strs[i]) != ft_strlen(strs[i]))
		{
			printf("KO : \"%s\"\t", strs[i]);
			ok = 0;
			ft_ok = 0;
		}
		i++;
	}
	printf("\t\tTesting error handling");
	er_no = check_diff_error("ft_strlen", 0);
	if (er_no >= 0)
	{
		ft_ok = 0;
		ok = 0;
		printf(" -> %s", er_msg[er_no]);
	}
	printf("%s\n", ft_ok ? "\n\tOK" : "\n!!!!!!!!!!ft_strlen: KO");
	// STRNCMP
	char	**strs_cmp1 = (char *[]){"\200",	"abc",		"abc",			"ab\0cde",	"q", "", NULL};
	char	**strs_cmp2 = (char *[]){"\0",		"abcde",	"abc\0defg", 	"abcc\0e",	"a", "", NULL};
	int		tab_cmp[]	=			{1,			3,			100,			20,			0,  2,	 0};
	printf("\tTesting ft_strncmp\n");
	i = 0;
	int res_cmp;
	int res_ft_cmp;
	while (strs_cmp1[i])
	{
		res_cmp = strncmp(strs_cmp1[i], strs_cmp2[i], tab_cmp[i]);
		res_ft_cmp = ft_strncmp(strs_cmp1[i], strs_cmp2[i], tab_cmp[i]);
		if ( (!res_cmp ? 0 : res_cmp > 0 ? 1 : -1) != (!res_ft_cmp ? 0 : res_ft_cmp > 0 ? 1 : -1))
		{
			printf("KO : \"s1: \'%s\' <-> s2: \'%s\' <-> n: %d <-> res: %d <-> ft_res: %d\"\n",
				strs_cmp1[i], strs_cmp2[i], tab_cmp[i], strncmp(strs_cmp1[i], strs_cmp2[i], tab_cmp[i]),
				ft_strncmp(strs_cmp1[i], strs_cmp2[i], tab_cmp[i]));
			ok = 0;
			ft_ok = 0;
		}
		i++;
	}
	printf("\t\tTesting error handling");
	er_no = check_diff_error("ft_strncmp", 2);
	if (er_no >= 0)
	{
		ft_ok = 0;
		ok = 0;
		printf(" -> %s", er_msg[er_no]);
	}
	printf("%s\n", ft_ok ? "\n\tOK" : "\n!!!!!!!!!!ft_strncmp: KO");
	return (ok);
}
int		main(int ac, char **av)
{
	// STR_IS
	if (ac == 1 || !strcmp(av[1], STR_IS))
	{
		printf("TESTING %s--------\n", STR_IS);
		printf("%s: %s\n", STR_IS, (ft_str_is_test() ? "OK---------" : "KO---------"));
	}
	// STR_TO
	if (ac == 1 || !strcmp(av[1], STR_TO))
	{
		printf("TESTING %s--------\n", STR_TO);
		printf("%s: %s\n", STR_TO, (ft_str_to_test() ? "OK---------" : "KO---------"));
	}
	// STR
	if (ac == 1 || !strcmp(av[1], STR))
	{
		printf("TESTING %s--------\n", STR);
		printf("%s: %s\n", STR, (ft_str_test() ? "OK---------" : "KO---------"));
	}
	return (0);
}