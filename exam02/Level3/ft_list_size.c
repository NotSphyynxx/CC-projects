/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_size.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilarhrib <ilarhrib@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/07 03:20:45 by ilarhrib          #+#    #+#             */
/*   Updated: 2025/01/07 04:54:08 by ilarhrib         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"

int	ft_list_size(t_list *begin_list){
    int c = 0;
    t_list *ptr;

    ptr = begin_list;
    while (ptr){
        ptr = ptr->next;
        c++;
    }
    return (c);
}
