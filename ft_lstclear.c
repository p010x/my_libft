/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcottet <pcottet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/14 16:49:06 by pcottet           #+#    #+#             */
/*   Updated: 2020/10/14 22:13:33 by pcottet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void        ft_lstclear(t_list **lst, void (*del)(void *))
{
    t_list  *lst_tmp;

    lst_tmp = *lst;
    while (*lst->next)
    {
        ft_lstdelone(*lst, del);
        lst_tmp = tmp->next;
        *lst = lst_tmp;
    }
    free(lst);
}