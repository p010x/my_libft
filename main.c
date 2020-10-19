/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcottet <pcottet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/16 09:11:17 by pcottet           #+#    #+#             */
/*   Updated: 2020/10/19 21:46:05 by pcottet          ###   ########.fr       */
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
// int		check_diff_error(char *ft_name, int option)
// {
// 	printf("%s%d", ft_name, option);
// 	return (-1);
// }

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
	// Return value
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
// ----------STR----------
int		ft_str_test(void)
{
	int		ok = 1;
	int		ft_ok = 1;
	int		i, j, k, l= 0;
	// LEN
	printf("\tTesting ft_strlen\n");
	char	**strs = (char *[]){"0", "124", "-124", INT_MIN_STR, INT_MAX_STR, "addazd", "", "a1",
				"1a", "-a1", "\011", "\t+1", "\n-1", "\r1", "\va", "\b", "000000000000000110",
				"  \t\n  \r\r\v\f-899",	"     32 ", "++876", "\200123", "123\200", "-+1", "+-1",
				"\n          42 24", "42jk ", "      --s8", " -sfecf", "  +442", "  -4232", NULL};
	while (strs[i])
	{
		if (strlen(strs[i]) != ft_strlen(strs[i]))
		{
			printf("KO : \"%s\"\t\n", strs[i]);
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
	printf("\tTesting ft_strncmp\n");
	char	**strs_cmp1 = (char *[]){"\200",	"abc",		"abc",			"ab\0cde",	"q", "", NULL};
	char	**strs_cmp2 = (char *[]){"\0",		"abcde",	"abc\0defg", 	"abcc\0e",	"a", "", NULL};
	int		tab_cmp[]	=			{1,			3,			100,			20,			0,  2,	 0};
	int res_cmp;
	int res_ft_cmp;

	ft_ok = 1;
	i = 0;
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
	// STRCHR
	printf("\tTesting ft_strchr\n");
	char	haystack[] = "hello 2 the world \200d	";
	char	needle[] = "z\n 2~ \200 \thl";

	ft_ok = 1;
	i = 0;
	while (needle[i])
	{

		if (strchr(haystack, needle[i]) != ft_strchr(haystack, needle[i]))
		{
			printf("KO : \"haystack: \'%s\' <-> needle: \'%c\' <-> res: %s <-> ft_res: %s\"\n",
				haystack, needle[i], strchr(haystack, needle[i]), ft_strchr(haystack, needle[i]));
			ok = 0;
			ft_ok = 0;
		}
		i++;
	}
	printf("\t\tTesting error handling");
	er_no = check_diff_error("ft_strchr", 0);
	if (er_no >= 0)
	{
		ft_ok = 0;
		ok = 0;
		printf(" -> %s", er_msg[er_no]);
	}
	printf("%s\n", ft_ok ? "\n\tOK" : "\n!!!!!!!!!!ft_strchr: KO");
	// STRRCHR (re-using strchr's variable)
	printf("\tTesting ft_strrchr\n");
	ft_ok = 1;
	i = 0;
	while (needle[i])
	{
		if (strrchr(haystack, needle[i]) != ft_strrchr(haystack, needle[i]))
		{
			printf("KO : \"haystack: \'%s\' <-> needle: \'%c\' <-> res: %s <-> ft_res: %s\"\n",
				haystack, needle[i], strrchr(haystack, needle[i]), ft_strrchr(haystack, needle[i]));
			ok = 0;
			ft_ok = 0;
		}
		i++;
	}
	printf("\t\tTesting error handling");
	er_no = check_diff_error("ft_strrchr", 0);
	if (er_no >= 0)
	{
		ft_ok = 0;
		ok = 0;
		printf(" -> %s", er_msg[er_no]);
	}
	printf("%s\n", ft_ok ? "\n\tOK" : "\n!!!!!!!!!!ft_strrchr: KO");
	// STRLCPY
	printf("\tTesting ft_strlcpy\n");
	int		dst_cpy_sizes[]	= {0, 1, 2, 6, 9, 10, -1};
	char	dst_cpy[10] = "abc\0\0\0";
	char	dst_cpy_tmp[10], dst_cpy_ft_tmp[10];
	char	**srcs_cpy	= (char *[]){"a", "abc", "a\0abc", "je suis un tout petit nan", "", "\0", NULL};
	int		res_cpy, ft_res_cpy = 0;

	ft_ok = 1;
	i = 0;
	strcpy(dst_cpy_tmp, dst_cpy);
	strcpy(dst_cpy_ft_tmp, dst_cpy);
	while (srcs_cpy[i])
	{
		j = 0;
		while (dst_cpy_sizes[j] >= 0)
		{
			res_cpy = strlcpy(dst_cpy_tmp, srcs_cpy[i], dst_cpy_sizes[j]);
			ft_res_cpy = ft_strlcpy(dst_cpy_ft_tmp, srcs_cpy[i], dst_cpy_sizes[j]);
			if ((res_cpy != ft_res_cpy) || strcmp(dst_cpy_tmp, dst_cpy_ft_tmp))
			{
				printf("KO : \"dst: \'%s\' <-> src: \'%s\' <-> size_dst: %d -> res: %d <-> ft_res: %d -> dst_cpy: \'%s\' <-> ft_dst_cpy: \'%s\' \"\n",
				dst_cpy, srcs_cpy[i], dst_cpy_sizes[j], res_cpy, ft_res_cpy, dst_cpy_tmp, dst_cpy_ft_tmp);
				ok = 0;
				ft_ok = 0;
			}
			j++;
			strcpy(dst_cpy_tmp, dst_cpy);
			strcpy(dst_cpy_ft_tmp, dst_cpy);
		}
		i++;
	}
	printf("\t\tTesting error handling");
	er_no = check_diff_error("ft_strlcpy", 2);
	if (er_no >= 0)
	{
		ft_ok = 0;
		ok = 0;
		printf(" -> %s", er_msg[er_no]);
	}
	printf("%s\n", ft_ok ? "\n\tOK" : "\n!!!!!!!!!!ft_strlcpy: KO");
	// STRLCAT
	printf("\tTesting ft_strlcat\n");
	int		dst_cat_sizes[]	= {0, 1, 2, 6, 9, 10, -1};
	char	dst_cat[10] = "abc\0\0\0";
	char	dst_cat_tmp[10], dst_cat_ft_tmp[10];
	char	**srcs_cat	= (char *[]){"a", "abc", "a\0abc", "je suis un tout petit nan", "", "\0", NULL};
	int		res_cat, ft_res_cat = 0;

	ft_ok = 1;
	strcpy(dst_cat_tmp, dst_cat);
	strcpy(dst_cat_ft_tmp, dst_cat);
	i = 0;
	while (srcs_cat[i])
	{
		j = 0;
		while (dst_cat_sizes[j] >= 0)
		{
			res_cat = strlcat(dst_cat_tmp, srcs_cat[i], dst_cat_sizes[j]);
			ft_res_cat = ft_strlcat(dst_cat_ft_tmp, srcs_cat[i], dst_cat_sizes[j]);
			if ((res_cat != ft_res_cat) || strcmp(dst_cat_tmp, dst_cat_ft_tmp) != 0)
			{
				printf("KO : \"dst: \'%s\' <-> src: \'%s\' <-> size_dst: %d <-> res: %d <-> ft_res: %d <-> dst_cat: \'%s\' <-> ft_dst_cat: \'%s\'\"\n",
				dst_cat, srcs_cat[i], dst_cat_sizes[j], res_cat, ft_res_cat, dst_cat_tmp, dst_cat_ft_tmp);
				ok = 0;
				ft_ok = 0;
			}
			j++;
			strcpy(dst_cat_tmp, dst_cat);
			strcpy(dst_cat_ft_tmp, dst_cat);
		}
		i++;
	}
	printf("\t\tTesting error handling");
	er_no = check_diff_error("ft_strlcat", 2);
	if (er_no >= 0)
	{
		ft_ok = 0;
		ok = 0;
		printf(" -> %s", er_msg[er_no]);
	}
	printf("%s\n", ft_ok ? "\n\tOK" : "\n!!!!!!!!!!ft_strlcat: KO");
	// STRNSTR
	printf("\tTesting ft_strnstr\n");
	int		strnstr_len[]	= {0, 1, 2, 6, 9, 100, -1};
	char	**haystacks	= (char *[]){"Ceci n'est pas une pipe.", "ozarabozaraboze", "a\0abc", "J'ai fait pipapipapou en LV2", "", "\0", NULL};
	char	**needles	= (char *[]){"a", "aaaaa", "pe", ".", "", "C", "BWAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAA", "pipapou", "une", "\0", NULL};
	char	**needles2	= (char *[]){"a", "aaaaa", "pe", ".", "", "C", "BWAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAA", "pipapou", "une", "\0", NULL};
	char	*strnstr_tmp, *strnstr_ft_tmp;


	ft_ok = 1;
	i = 0;
	while (haystacks[i])
	{
		j = 0;
		while (needles[j])
		{
			k = 0;
			while (strnstr_len[k] >= 0)
			{
				strnstr_tmp = strnstr(haystacks[i], needles[j], strnstr_len[k]);
				strnstr_ft_tmp = ft_strnstr(haystacks[i], needles2[j], strnstr_len[k]);
				if (((strnstr_tmp && !strnstr_ft_tmp) || (!strnstr_tmp && strnstr_ft_tmp)) ||
					((strnstr_tmp && strnstr_ft_tmp) && strcmp(strnstr_tmp, strnstr_ft_tmp)))
				{
					printf("KO : \"haystack: \'%s\' <-> needle: \'%s\' <-> needle2: \'%s\' -> lenght: %d -> res: \'%s\' <-> ft_res: \'%s\'\"\n",
					haystacks[i], needles[j], needles2[j], strnstr_len[k], strnstr_tmp, strnstr_ft_tmp);
					ok = 0;
					ft_ok = 0;
				}
				k++;
			}
			j++;
		}
		i++;
	}
	printf("\t\tTesting error handling");
	er_no = check_diff_error("ft_strnstr", 0);
	if (er_no >= 0)
	{
		ft_ok = 0;
		ok = 0;
		printf(" -> %s", er_msg[er_no]);
	}
	printf("%s\n", ft_ok ? "\n\tOK" : "\n!!!!!!!!!!ft_strnstr: KO");
	// DUP
	printf("\tTesting ft_strdup\n");
	char	**strs_dup = (char *[]){"0", "124", "-124", INT_MIN_STR, INT_MAX_STR, "addazd", "", "a1",
				"1a", "-a1", "\011", "\t+1", "\n-1", "\r1", "\va", "\b", "000000000000000110",
				"  \t\n  \r\r\v\f-899",	"     32\0 ", "++876", "\200123", "123\200", "-+1", "+-1",
				"\n          42 24", "42jk ", "      --s8", " -sfecf", "  +442", "  -4232", NULL};

	ft_ok = 1;
	i = 0;
	while (strs_dup[i])
	{
		if (strcmp(strdup(strs_dup[i]), ft_strdup(strs_dup[i])))
		{
			printf("KO : str: \'%s\' -> str_dup: \'%s\' <-> ft_str_dup: \'%s\' \n", strs_dup[i], strdup(strs_dup[i]), ft_strdup(strs_dup[i]));
			ok = 0;
			ft_ok = 0;
		}
		i++;
	}
	printf("\t\tTesting error handling");
	er_no = check_diff_error("ft_strdup", 0);
	if (er_no >= 0)
	{
		ft_ok = 0;
		ok = 0;
		printf(" -> %s", er_msg[er_no]);
	}
	printf("%s\n", ft_ok ? "\n\tOK" : "\n!!!!!!!!!!ft_strlen: KO");
	// JOIN
	printf("\tTesting ft_strjoin\n");
	char	**strs_join1 = (char *[]){"", "", "1", "abcd", "ABC\0D", NULL};
	char	**strs_join2 = (char *[]){"", "1", "", "efgh", "EF\0G"};
	char	**strs_join_res = (char *[]){"", "1", "1", "abcdefgh", "ABCEF"};
	char	*str_join_tmp;

	ft_ok = 1;
	i = 0;
	while (strs_join1[i])
	{
		str_join_tmp = ft_strjoin(strs_join1[i], strs_join2[i]);
		if (strcmp(str_join_tmp, strs_join_res[i]))
		{
			printf("KO : s1: \'%s\' <-> s2: \'%s\' -> sjoin: \'%s\' <-> ft_sjoin: \'%s\'\n", strs_join1[i], strs_join2[i], strs_join_res[i], str_join_tmp);
			ok = 0;
			ft_ok = 0;
		}
		i++;
	}
	printf("\t\tTesting error handling");
	er_no = check_diff_error("ft_strjoin", 0);
	if (er_no >= 0)
	{
		ft_ok = 0;
		ok = 0;
		printf(" -> %s", er_msg[er_no]);
	}
	printf("%s\n", ft_ok ? "\n\tOK" : "\n!!!!!!!!!!ft_strlen: KO");
	// SUB
	printf("\tTesting ft_substr\n");
	int		substr_start[]	= {0, 1, 2, 3, 6, -1};
	int		substr_len[]	= {0, 1, 2, 3, 6, -1};
	char	**strs_sub = (char *[]){"", "\0", "1", "abcd", "ABC\0DEFGIJKL", NULL};
	char	**strs_sub_res0 = (char *[]){"", "", "", "", "", // case 0 0
										 "", "", "1", "a", "A", // case 0 1
										 "", "", "1", "ab", "AB", // case 0 2
										 "", "", "1", "abc", "ABC", // case 0 3
										 "", "", "1", "abcd", "ABC"}; // case 0 6
	char	**strs_sub_res1 = (char *[]){"", "", "", "", "", // case 1 0
										 "", "", "", "b", "B", // case 1 1
										 "", "", "", "bc", "BC", // case 1 2
										 "", "", "", "bcd", "BC", // case 1 3
										 "", "", "", "bcd", "BC"}; // case 1 6
	char	**strs_sub_res2 = (char *[]){"", "", "", "", "", // case 2 0
										 "", "", "", "c", "C", // case 2 1
										 "", "", "", "cd", "C", // case 2 2
										 "", "", "", "cd", "C", // case 2 3
										 "", "", "", "cd", "C"}; // case 2 6
	char	**strs_sub_res3 = (char *[]){"", "", "", "", "", // case 3 0
										 "", "", "", "d", "", // case 3 1
										 "", "", "", "d", "", // case 3 2
										 "", "", "", "d", "", // case 3 3
										 "", "", "", "d", ""}; // case 3 6
	char	**strs_sub_res6 = (char *[]){"", "", "", "", "", // case 6 0
										 "", "", "", "", "", // case 6 1
										 "", "", "", "", "", // case 6 2
										 "", "", "", "", "", // case 6 3
										 "", "", "", "", ""}; // case 6 6
	char	**strs_all_res[5]	= {strs_sub_res0, strs_sub_res1, strs_sub_res2, strs_sub_res3, strs_sub_res6};
	char	*str_sub_tmp;

	ft_ok = 1;
	i = 0;
	while (substr_start[i] >= 0)
	{
		j = 0;
		l = 0;
		while (substr_len[j] >= 0)
		{
			k = 0;
			while (strs_sub[k])
			{
				str_sub_tmp = ft_substr(strs_sub[k], substr_start[i], substr_len[j]);
				if (strcmp(strs_all_res[i][l], str_sub_tmp))
				{
					printf("KO : s: \'%s\' <-> start: \'%d\' <-> len: \'%d\' -> res: \'%s\' <-> ft_res: \'%s\'\n",
					strs_sub[k], substr_start[i], substr_len[j], strs_all_res[i][l], str_sub_tmp);
					ok = 0;
					ft_ok = 0;
				}
				k++;
				l++;
			}
			j++;
		}
		i++;
	}
	printf("\t\tTesting error handling");
	er_no = check_diff_error("ft_substr", 1);
	if (er_no >= 0)
	{
		ft_ok = 0;
		ok = 0;
		printf(" -> %s", er_msg[er_no]);
	}
	printf("%s\n", ft_ok ? "\n\tOK" : "\n!!!!!!!!!!ft_substr: KO");
	// SPLIT
	printf("\tTesting ft_split\n");
	char	str_split[]		= "*Ceci n'est pas une \200ozarabozara.\0abc";
	char	split_charset[]	= {'*', 'a', 'z', '.', 'c', ' ', -127, '\200', '\0'};
	int		max_charset		= 9;
	char	**strs_empty	= (char *[]){"a", "aaaaaaaaaaaa", "", NULL};
	char	c_split_empty	= 'a';
	char	**res_empty		= (char *[]){"", NULL};
	char	**split_res0	= (char *[]){"Ceci n'est pas une \200ozarabozara.", NULL}; // charset '*'
	char	**split_res1	= (char *[]){"*Ceci n'est p", "s une \200oz", "r", "boz", "r", ".", NULL}; // charset 'a'
	char	**split_res2	= (char *[]){"*Ceci n'est pas une \200o", "arabo", "ara.", NULL}; // charset 'z'
	char	**split_res3	= (char *[]){"*Ceci n'est pas une \200ozarabozara", NULL}; // charset '.'
	char	**split_res4	= (char *[]){"*Ce", "i n'est pas une \200ozarabozara.", NULL}; // charset 'c'
	char	**split_res5	= (char *[]){"*Ceci" ,"n'est", "pas", "une", "\200ozarabozara.", NULL}; // charset ' '
	char	**split_res6	= (char *[]){"*Ceci n'est pas une \200ozarabozara.", NULL}; // charset -127
	char	**split_res7	= (char *[]){"*Ceci n'est pas une ", "ozarabozara.", NULL}; // charset 200
	char	**split_res8	= (char *[]){"*Ceci n'est pas une \200ozarabozara.", NULL}; // charset '\0'
	char	**split_allres[9]	= {split_res0, split_res1, split_res2, split_res3,  split_res4,
							split_res5, split_res6, split_res7, split_res8};
	char	**split_ft_res;

	ft_ok = 1;
	i = 0;
	while (i < max_charset)
	{
		split_ft_res = ft_split(str_split, split_charset[i]);
		j = 0;
		while (split_allres[i][j])
		{
			if ((!split_allres[i][j + 1] && split_ft_res[j + 1]) || (split_allres[i][j + 1] && !split_ft_res[j + 1]) ||
				strcmp(split_allres[i][j],  split_ft_res[j]))
			{
				printf("KO : \"s: \'%s\' <-> charset: \'%c\' -> res: \'%s\' <-> ft_res: \'%s\' -> next_res: \'%s\' next_ft_res: \'%s\' \"\n",
					str_split, split_charset[i], split_allres[i][j], split_ft_res[j], split_allres[i][j + 1], split_ft_res[j + 1]);
				ok = 0;
				ft_ok = 0;
				break;
			}
			j++;
		}
		i++;
	}
	i = 0;
	while (strs_empty[i])
	{
	char **split_ft_res = ft_split(strs_empty[i], c_split_empty);
		if (split_ft_res[1] || *split_ft_res[0])
		{
			printf("KO : \"s: \'%s\' <-> charset: \'%c\' -> ft_res: \'%s\' should be "" <-> next_ft_res: \'%s\' should be '(null)' \"\n",
					strs_empty[i], c_split_empty, split_ft_res[0], split_ft_res[1]);
			ok = 0;
			ft_ok = 0;
		}
		i++;
	}
	printf("\t\tTesting error handling");
	er_no = check_diff_error("ft_split", 0);
	if (er_no >= 0)
	{
		ft_ok = 0;
		ok = 0;
		printf(" -> %s", er_msg[er_no]);
	}
	printf("%s\n", ft_ok ? "\n\tOK" : "\n!!!!!!!!!!ft_split: KO");
	// TRIM
	printf("\tTesting ft_strtrim\n");
	char	**strs_trim		= (char *[]){"\t\n  \tAAA \t BBB\t\n  \t", "\t\t\n\t\t   ", "", "abc", NULL};
	char	**strs_trim_res	= (char *[]){"AAA \t BBB", "", "", "abc", NULL};
	char	*strs_trim_set	= "\t\n\r\v\f ";
	char	*str_trim_tmp;

	ft_ok = 1;
	i = 0;
	while (strs_trim[i])
	{
		str_trim_tmp = ft_strtrim(strs_trim[i] , strs_trim_set);
		if (strcmp(str_trim_tmp, strs_trim_res[i]))
		{
			printf("KO : \"s: \'%s\' <-> set: \'%s\' -> res: \'%s\' <-> ft_res: \'%s\' \"\n",
				strs_trim[i], strs_trim_set, strs_trim_res[i], str_trim_tmp);
			ok = 0;
			ft_ok = 0;
		}
		i++;
	}
	i = 0;
	while (strs_trim[i])
	{
		str_trim_tmp = ft_strtrim(strs_trim[i] , "");
		if (strcmp(str_trim_tmp, strs_trim[i]))
		{
			printf("KO : \"s: \'%s\' <-> set: \'\"\"\' -> res: \'%s\' <-> ft_res: \'%s\' \"\n",
				strs_trim[i], strs_trim[i], str_trim_tmp);
			ok = 0;
			ft_ok = 0;
		}
		i++;
	}
	printf("\t\tTesting error handling");
	er_no = check_diff_error("ft_strtrim", 2);
	if (er_no >= 0)
	{
		ft_ok = 0;
		ok = 0;
		printf(" -> %s", er_msg[er_no]);
	}
	printf("%s\n", ft_ok ? "\n\tOK" : "\n!!!!!!!!!!ft_strtrim: KO");
	// RETURN VALUE
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
