/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_list.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilarhrib <ilarhrib@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/15 16:28:10 by ilarhrib          #+#    #+#             */
/*   Updated: 2025/01/15 16:29:33 by ilarhrib         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SORT_LIST_H
# define SORT_LIST_H

typedef struct s_list t_list;

struct s_list
{
	int     data;
	t_list  *next;
};

#endif