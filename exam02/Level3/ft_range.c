/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_range.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilarhrib <ilarhrib@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/07 04:54:54 by ilarhrib          #+#    #+#             */
/*   Updated: 2025/01/07 05:56:29 by ilarhrib         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int     *ft_range(int start, int end){
    int size = abs((end - start)) + 1;
    int *array = malloc(size * sizeof(int));
    if (array == NULL)
        return 0;
    int i = 0;
    while (i < size){
        if (start < end){
            while (start <= end){
                array[i] = start;
                start++;
                i++;
            }
        }
            else {
                while (start >= end){
                    array[i] = start;
                    start--;
                    i++;
                }
            }
    }
    return (array);
}
