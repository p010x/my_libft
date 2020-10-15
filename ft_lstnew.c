/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcottet <pcottet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/14 15:43:20 by pcottet           #+#    #+#             */
/*   Updated: 2020/10/14 16:01:41 by pcottet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list      *ft_lstnew(void *content)
{
    t_list  *lst;

    if (!(lst = malloc(sizeof(t_list))) || !content)
        return (NULL);
    lst->content = content;
    lst->next = NULL;
    return (lst);
}