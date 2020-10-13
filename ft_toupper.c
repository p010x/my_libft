/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_toupper.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcottet <pcottet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/12 17:41:19 by pcottet           #+#    #+#             */
/*   Updated: 2020/10/13 03:20:00 by pcottet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int         ft_toupper(int c)
{
    return ((c >= 'a' && c <= 'z') ? (c - ('a' - 'A')) : c);
}