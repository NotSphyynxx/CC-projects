/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilarhrib <ilarhrib@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/22 12:12:55 by ilarhrib          #+#    #+#             */
/*   Updated: 2024/10/23 12:37:43 by ilarhrib         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void *ft_memset(void *s, int c, size_t n)
{
    size_t i;
    unsigned char *ptr = (unsigned char *)s;
    unsigned char v = (unsigned char) c;
    
    i = 0;
    while (i < n)
    {
        ptr[i] = v;
        i++;
    }
    return (s);
}