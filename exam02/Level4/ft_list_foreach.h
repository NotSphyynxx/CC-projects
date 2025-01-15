/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_foreach.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilarhrib <ilarhrib@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/12 16:35:58 by ilarhrib          #+#    #+#             */
/*   Updated: 2025/01/12 16:36:50 by ilarhrib         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_LIST_FOREACH_H
#define FT_LIST_FOREACH_H

#include <libc.h>
typedef struct    s_list
{
    struct s_list *next;
    void          *data;
}                 t_list;

#endif