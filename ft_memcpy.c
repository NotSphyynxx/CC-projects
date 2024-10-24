/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilarhrib <ilarhrib@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/23 14:44:43 by ilarhrib          #+#    #+#             */
/*   Updated: 2024/10/23 16:22:05 by ilarhrib         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void    *ft_memcpy(void *restrict d, const void *restrict s, size_t numberOfBytes)
{
    unsigned char   *dest;
    const unsigned char *src;
    size_t  i;
    
    if (!d || !s)
    {
        return (0);
    }
    i = 0;
    dest = (unsigned char*)d;
    src = (const unsigned char *)s;
    while (i < numberOfBytes)
    {
        dest[i] = src[i];
        i++;
    }
    return (d);
}