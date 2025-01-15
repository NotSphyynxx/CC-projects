/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_remove.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilarhrib <ilarhrib@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/12 16:42:58 by ilarhrib          #+#    #+#             */
/*   Updated: 2025/01/13 10:41:07 by ilarhrib         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list_foreach.h"

void ft_list_remove_if(t_list **begin_list, void *data_ref, int (*cmp)()){
    t_list *ptr = *begin_list;
    while (ptr){
        if (cmp(ptr->data, data_ref) == 0){
            *begin_list = ptr->next;
            free(ptr);
            ptr = *begin_list;
        }
        else
            ptr = ptr->next;
    }
}

void ft_list_remove_if(t_list **begin_list, void *data_ref, int (*cmp)()){
    if (begin_list == NULL || *begin_list == NULL)
        return ;
    t_list *ptr = *begin_list;
    if (cmp(ptr->data, data_ref)){
        begin_list = ptr->next;
        free(ptr);
        ft_list_remove_if(&begin_list, data_ref, cmp);
    }
    else{
        *begin_list = ptr->next;
        ft_list_remove_if(&begin_list, data_ref, cmp);
    }
}