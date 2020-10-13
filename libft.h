/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcottet <pcottet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/12 10:22:40 by pcottet           #+#    #+#             */
/*   Updated: 2020/10/13 04:41:22 by pcottet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

#include <unistd.h>
#include <stdlib.h>
#include <strings.h>

typedef struct      s_list
{
    void            *content;
    struct s_list   *next;
}                   t_list;

/* STR */
int         ft_strlen(const char *s);
int         ft_strncmp(const char *s1, const char *s2, size_t n);
char        *ft_strchr(const char *s, int c);
char        *ft_strchr(const char *s, int c);
size_t      ft_strlcpy(char *dst, const char *src, size_t dstsize);
size_t      ft_strlcat(char *dst, const char *src, size_t dstsize);
char        *ft_strnstr(const char *haystack, const char *needle, size_t len);
char        *ft_strdup(const char *s1);
char        *ft_substr(char const *s, unsigned int start, size_t len);
char        *ft_strjoin(char const *s1, char const *s2);
char        *ft_strtrim(char const *s1, char const *set);
char        **ft_split(char const *s, char c);
char        *ft_strmapi(char const *s, char (*f)(unsigned int, char));
/* STR_IS */
int         ft_isalpha(int c);
int         ft_isdigit(int c);
int         ft_isalnum(int c);
int         ft_isascii(int c);
int         ft_atoi(const char *str);
char        *ft_itoa(int n);
/* STR_TO */
int         ft_toupper(int c);
int         ft_tolower(int c);
/* PUT */
void        ft_putchar_fd(char c, int fd);
void        ft_putstr_fd(char *s, int fd);
void        ft_putendl_fd(char *s, int fd);
void        ft_putnbr_fd(int n, int fd);
/* MEM */
void        *ft_memset(void *b, int c, size_t len);
void        ft_bzero(void *s, size_t n);
void        *ft_calloc(size_t count, size_t size);
#endif