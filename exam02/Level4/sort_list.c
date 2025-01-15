/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_list.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilarhrib <ilarhrib@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/15 16:27:56 by ilarhrib          #+#    #+#             */
/*   Updated: 2025/01/15 16:36:43 by ilarhrib         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sort_list.h"

t_list	*sort_list(t_list* lst, int (*cmp)(int, int)){
    t_list *tmp = NULL;
    t_list *ptr = lst;
    t_list *start = lst;
    while (ptr){
        if (cmp(ptr->data, ptr->next->data) == 0){
            tmp = ptr->data;
            ptr->data = ptr->next->data;
            ptr->next->data = tmp;
            ptr = start;
        }
        else
            ptr = ptr->next;
    }
    return (ptr);
}