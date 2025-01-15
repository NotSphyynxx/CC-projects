/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rrange.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilarhrib <ilarhrib@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/07 05:59:29 by ilarhrib          #+#    #+#             */
/*   Updated: 2025/01/07 06:07:04 by ilarhrib         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int     *ft_rrange(int start, int end){
    int size = abs((end - start)) + 1;
    int *array = malloc(size * sizeof(int));
    if (array == NULL)
        return 0;
    int i = 0;
    while (i < size){
        if (end > start){
            while (start <= end){
                array[i] = end;
                end--;
                i++;
            }
        }
        else {
            while (end <= start){
                array[i] = end;
                end++;
                i++;
            }
        }
    }
    return (array);
}
#include <libc.h>
int main(){
    int *array = ft_rrange(1, 5);
    int i = 0;
    while (i < 5){
        printf("%d ", array[i]);
        i++;
    }
    return 0;
}