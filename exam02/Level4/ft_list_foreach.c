/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_foreach.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilarhrib <ilarhrib@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/12 16:37:05 by ilarhrib          #+#    #+#             */
/*   Updated: 2025/01/12 16:42:33 by ilarhrib         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list_foreach.h"

void    ft_list_foreach(t_list *begin_list, void (*f)(void *)){
    t_list *ptr = begin_list;
    while (ptr){
        (*f)(ptr->data);
        ptr = ptr->next;
    }
}