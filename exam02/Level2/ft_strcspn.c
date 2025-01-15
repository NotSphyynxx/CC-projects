/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcspn.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilarhrib <ilarhrib@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/04 16:22:32 by ilarhrib          #+#    #+#             */
/*   Updated: 2025/01/04 16:50:15 by ilarhrib         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include <stdio.h>
#include <stdlib.h>

size_t	ft_strcspn(const char *s, const char *reject){
    int j = 0;
    int i = 0;
    while (s[i]){
        j = 0;
        while (reject[j]){
            if (reject[j] == s[i])
                return i;
            j++;
        }
        i++;
    }
    return ((size_t)i);
}