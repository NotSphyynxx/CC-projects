/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilarhrib <ilarhrib@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/22 13:05:22 by ilarhrib          #+#    #+#             */
/*   Updated: 2024/10/23 16:58:01 by ilarhrib         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void    *ft_memmove(void *dest, const void *src, size_t lenght)
{
    unsigned char   *d;
    const unsigned char *s;
    size_t i;
    
    i = 0;
    s = (unsigned char *)src;
    d = (unsigned char *)dest;
    if (d > s)
    {
        while (lenght--)
        {
            d[lenght] = s[lenght];
        }
    }
    else
    {
        while (i < lenght)
        {
            d[i] = s[i];
            i++;
        }
    }
    return (dest);
}