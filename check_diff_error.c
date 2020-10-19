/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_diff_error.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcottet <pcottet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/16 15:29:14 by pcottet           #+#    #+#             */
/*   Updated: 2020/10/19 21:47:56 by pcottet          ###   ########.fr       */
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
CATCH_SEGFAULT()
int is_seg = 0;
char *str1, *str2 = NULL;
char not_null_str[] = "test_str";
int count = 0;

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
			str1 = not_null_str;
			break;
		}
		case 1:
		{
			str2 = not_null_str;
			break;
		}
		case 0:
			break;
		default:
		{
			printf("Error no matched case in switch");
			break;
		}
	}
	if (sigsetjmp(mark,1) != 0)
	{
	  is_seg = 1;
    }
	else
	{
		strncmp(str1, str2, 0);
	}
	if (sigsetjmp(mark,1) != 0)
	{
	  if (!is_seg)
	  {
		  printf(" -> option: %d", option);
		  return (1);
	  }
    }
	else
	{
		ft_strncmp(str1, str2, 0);
		if (is_seg)
		{
			printf(" -> option: %d", option);
			return (2);
		}
	}
	return (option ? check_diff_error("ft_strncmp", --option) : -1);
}
else if (!strcmp("ft_strchr", ft_name))
{
	if (sigsetjmp(mark,1) != 0)
	{
	  is_seg = 1;
    }
	else
		strchr(NULL, 0);
	if (sigsetjmp(mark,1) != 0)
	{
	  if (!is_seg)
		  return (1);
    }
	else
	{
		ft_strchr(NULL, 0);
		if (is_seg)
			return (2);
	}
	return (-1);
}
else if (!strcmp("ft_strrchr", ft_name))
{
	if (sigsetjmp(mark,1) != 0)
	{
	  is_seg = 1;
    }
	else
		strrchr(NULL, 0);
	if (sigsetjmp(mark,1) != 0)
	{
	  if (!is_seg)
		  return (1);
    }
	else
	{
		ft_strrchr(NULL, 0);
		if (is_seg)
			return (2);
	}
	return (-1);
}
else if (!strcmp("ft_strlcpy", ft_name))
{
	switch (option)
	{
		case 2:
		{
			str1 = not_null_str;
			break;
		}
		case 1:
		{
			str2 = not_null_str;
			break;
		}
		case 0:
			break;
		default:
		{
			printf("Error no matched case in switch");
			break;
		}
	}
	if (sigsetjmp(mark,1) != 0)
	{
	  is_seg = 1;
    }
	else
	{
		strncmp(str1, str2, 0);
	}
	if (sigsetjmp(mark,1) != 0)
	{
	  if (!is_seg)
	  {
		  printf(" -> option: %d", option);
		  return (1);
	  }
    }
	else
	{
		ft_strncmp(str1, str2, 0);
		if (is_seg)
		{
			printf(" -> option: %d", option);
			return (2);
		}
	}
	return (option ? check_diff_error("ft_strlcpy", --option) : -1);
}
else if (!strcmp("ft_strlcat", ft_name))
{
	switch (option)
	{
		case 2:
		{
			str1 = not_null_str;
			break;
		}
		case 1:
		{
			str2 = not_null_str;
			break;
		}
		case 0:
			break;
		default:
		{
			printf("Error no matched case in switch");
			break;
		}
	}
	if (sigsetjmp(mark,1) != 0)
	{
	  is_seg = 1;
    }
	else
	{
		strlcat(str1, str2, 0);
	}
	if (sigsetjmp(mark,1) != 0)
	{
	  if (!is_seg)
	  {
		  printf(" -> option: %d (str1: \"%s\" str2: \"%s\")", option, str1, str2);
		  return (1);
	  }
    }
	else
	{
		ft_strlcat(str1, str2, 0);
		if (is_seg)
		{
			printf(" -> option: %d", option);
			return (2);
		}
	}
	return (option ? check_diff_error("ft_strlcat", --option) : -1);
}
else if (!strcmp("ft_strnstr", ft_name))
{
	switch (option)
	{
		case 2:
		{
			str1 = not_null_str;
			break;
		}
		case 1:
		{
			str2 = not_null_str;
			break;
		}
		case 0:
			break;
		default:
		{
			printf("Error no matched case in switch");
			break;
		}
	}
	if (sigsetjmp(mark,1) != 0)
	{
	  is_seg = 1;
    }
	else
	{
		strnstr(str1, str2, 0);
	}
	if (sigsetjmp(mark,1) != 0)
	{
	  if (!is_seg)
	  {
		  printf(" -> option: %d (str1: \"%s\" str2: \"%s\")", option, str1, str2);
		  return (1);
	  }
    }
	else
	{
		ft_strnstr(str1, str2, 0);
		if (is_seg)
		{
			printf(" -> option: %d", option);
			return (2);
		}
	}
	return (option ? check_diff_error("ft_strnstr", --option) : -1);
}
else if (!strcmp("ft_strdup", ft_name))
{
	if (sigsetjmp(mark,1) != 0)
	{
	  is_seg = 1;
    }
	else
		strdup(NULL);
	if (sigsetjmp(mark,1) != 0)
	{
	  if (!is_seg)
		  return (1);
    }
	else
	{
		ft_strdup(NULL);
		if (is_seg)
			return (2);
	}
	return (-1);
}
else if (!strcmp("ft_strjoin", ft_name))
{
	switch (option)
	{
		case 2:
		{
			str1 = not_null_str;
			break;
		}
		case 1:
		{
			str2 = not_null_str;
			break;
		}
		case 0:
			break;
		default:
		{
			printf("Error no matched case in switch");
			break;
		}
	}
	if (sigsetjmp(mark,1) != 0)
	{
		printf(" -> option: %d (str1: \"%s\" str2: \"%s\")", option, str1, str2);
		return (1);
    }
	else
	{
		ft_strjoin(str1, str2);
	}
	return (option ? check_diff_error("ft_strjoin", --option) : -1);
}
else if (!strcmp("ft_substr", ft_name))
{
	switch (option)
	{
		case 1:
		{
			str1 = not_null_str;
			break;
		}
		case 0:
			break;
		default:
		{
			printf("Error no matched case in switch");
			break;
		}
	}
	if (sigsetjmp(mark,1) != 0)
	{
		printf(" -> option: %d (str1: \"%s\" start: \"15\" len: \"15\")", option, str1);
			return (1);
    }
	else
		ft_substr(str1, 15, 3);
	return (option ? check_diff_error("ft_substr", --option) : -1);
}
else if (!strcmp("ft_split", ft_name))
{
	if (sigsetjmp(mark,1) != 0)
	{
		printf(" -> (str1: \'%s\' )", str1);
		return (1);
    }
	else
		ft_split(str1, '\0');
	return (option ? check_diff_error("ft_split", --option) : -1);
}
else if (!strcmp("ft_strtrim", ft_name))
{
	switch (option)
	{
		case 2:
		{
			str1 = not_null_str;
			break;
		}
		case 1:
		{
			str2 = not_null_str;
			break;
		}
		case 0:
			break;
		default:
		{
			printf("Error no matched case in switch");
			break;
		}
	}
	if (sigsetjmp(mark,1) != 0)
	{
		printf(" -> option: %d -> (str1: \"%s\" str2: \"%s\")", option, str1, str2);
		return (1);
    }
	else
	{
		ft_strtrim(str1, str2);
	}
	return (option ? check_diff_error("ft_strtrim", --option) : -1);
}
else
	return (0);
}
