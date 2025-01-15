/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilarhrib <ilarhrib@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/05 04:16:08 by ilarhrib          #+#    #+#             */
/*   Updated: 2025/01/05 04:22:21 by ilarhrib         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

char    *ft_strdup(char *src){
    int i = 0;
    while (src[i]){
        i++;
    }
    char *new_copy = malloc(i * sizeof(char) + 1);
    if (new_copy == NULL){
        return NULL;
    }
    i = 0;
    while (src[i]){
        new_copy[i] = src[i];
        i++;
    }
    new_copy[i] = '\0';
    return (new_copy);
}