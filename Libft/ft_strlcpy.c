/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilarhrib <ilarhrib@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/23 17:00:59 by ilarhrib          #+#    #+#             */
/*   Updated: 2024/10/24 11:26:20 by ilarhrib         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t ft_strlcpy(char *restrict dst, const char *restrict src, size_t dstsize)
{
    size_t src_len;
    size_t i;

    src_len = 0;
    while (src[src_len])
    {
        src_len++;
    }
    if (dstsize == 0)
    {
        return (src_len);
    }
    i = 0;
    while ((i < (dstsize - 1)) && src[i])
    {
        dst[i] = src[i];
        i++;
    }
    dst[i] = '\0';
    return (src_len);
}