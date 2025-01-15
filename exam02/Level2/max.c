/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   max.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilarhrib <ilarhrib@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/05 05:46:58 by ilarhrib          #+#    #+#             */
/*   Updated: 2025/01/05 05:53:04 by ilarhrib         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		max(int* tab, unsigned int len){
    if (len == 0)
        return 0;
    int i = 0;
    int res = tab[i];
    while (i < len){
        if (res < tab[i])
            res = tab[i];
        i++;
    }
    return res;
}