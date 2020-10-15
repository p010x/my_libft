/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcottet <pcottet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/14 16:26:10 by pcottet           #+#    #+#             */
/*   Updated: 2020/10/16 01:09:29 by pcottet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void		ft_lstadd_back(t_list **alst, t_list *new)
{
	t_list	*lst_tmp;

	if (!alst || !new)
		exit;
	if (lst_tmp = ft_lstlast(*alst))
		lst_tmp->next = new;
	else
		*alst = new;
}
