/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_diff_error.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcottet <pcottet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/16 15:29:14 by pcottet           #+#    #+#             */
/*   Updated: 2020/10/18 11:21:41 by pcottet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <ctype.h>
#include <limits.h>
#include <signal.h>
#include <setjmp.h>
#include "libft.h"
#define CATCH_SEGFAULT()	struct sigaction sa;\
    						memset(&sa, 0, sizeof(struct sigaction));\
    						sigemptyset(&sa.sa_mask);\
    						sa.sa_sigaction = segfault_sigaction;\
    						sa.sa_flags   = SA_SIGINFO;\
    						sigaction(SIGSEGV, &sa, NULL);

// ----------UTILS----------
sigjmp_buf mark;
void segfault_sigaction(int signal, siginfo_t *si, void *arg)
{
    // printf("\t\tSegfault(code: %d) for: ", si->si_code);
	siglongjmp(mark, -1);
}

int		check_diff_error(char *ft_name, int option)
{
// int					ft_strlen(const char *s);
// int					ft_strncmp(const char *s1, const char *s2, size_t n);
// char				*ft_strchr(const char *s, int c);
// char				*ft_strrchr(const char *s, int c);
// size_t				ft_strlcpy(char *dst, const char *src, size_t dstsize);
// size_t				ft_strlcat(char *dst, const char *src, size_t dstsize);
// char				*ft_strnstr(const char *haystack, const char *needle,
// 					size_t len);
// char				*ft_strdup(const char *s1);
// char				*ft_substr(char const *s, unsigned int start, size_t len);
// char				*ft_strjoin(char const *s1, char const *s2);
// char				*ft_strtrim(char const *s1, char const *set);
// char				**ft_split(char const *s, char c);
// char				*ft_strmapi(char const *s, char (*f)(unsigned int, char));

CATCH_SEGFAULT()
int is_seg = 0;
if (!strcmp("ft_strlen", ft_name))
{
	if (sigsetjmp(mark,1) != 0)
	{
	  is_seg = 1;
    }
	else
		strlen(NULL);
	if (sigsetjmp(mark,1) != 0)
	{
	  if (!is_seg)
		  return (1);
    }
	else
	{
		ft_strlen(NULL);
		if (is_seg)
			return (2);
	}
	return (-1);
}
else if (!strcmp("ft_atoi", ft_name))
{
	if (sigsetjmp(mark,1) != 0)
	{
	  is_seg = 1;
    }
	else
		atoi(NULL);
	if (sigsetjmp(mark,1) != 0)
	{
	  if (!is_seg)
		  return (1);
    }
	else
	{
		ft_atoi(NULL);
		if (is_seg)
			return (2);
	}
	return (-1);
}
else if (!strcmp("ft_strncmp", ft_name))
{
	switch (option)
	{
		case 2:
		{
			char cmp1[] = "NULL";
			char *cmp2 = NULL;
			break;
		}
		case 1:
		{
			char *cmp1 = NULL;
			char cmp2[] = "NULL";
			break;
		}
		default:
		{
			char *cmp1 = NULL;
			char *cmp2 = NULL;
			break;
		}
	}
	if (sigsetjmp(mark,1) != 0)
	{
	  is_seg = 1;
    }
	else
		strncmp(cmp1, cmp2, 0);
	if (sigsetjmp(mark,1) != 0)
	{
	  if (!is_seg)
		  return (1);
    }
	else
	{
		ft_strncmp(cmp1, cmp2, 0);
		if (is_seg)
			return (2);
	}
	return (option ? check_diff_error("ft_strncmp", --option) : -1);
}
else
	return (0);
}
