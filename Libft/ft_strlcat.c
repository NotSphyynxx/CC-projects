/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilarhrib <ilarhrib@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/23 18:14:40 by ilarhrib          #+#    #+#             */
/*   Updated: 2024/10/24 16:23:04 by ilarhrib         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t ft_strlcat(char *dst, const char *src, size_t dstsize)
{
    size_t dlength;
    size_t slength;
    size_t i;

    i = 0;
    slength = 0;
    dlength = 0;
    while (dst[dlength] && dlength < dstsize)
    {
        dlength++;
    }
    while (src[slength])
    {
        slength++;
    }
    if (dlength >= dstsize)
    {
        return (dstsize + slength);
    }
    while (src[i] && ((dlength + i) < dstsize - 1))
    {
        dst[dlength + i] = src[i];
        i++;
    }
    if (dlength + i < dstsize)
    {
        dst[dlength + i] = '\0';
    }
    return (dlength + slength);
}

int main () 
{
    char src[9] = " Larhrib";
    char dst[50] = "Ismail";
    printf("%zu\n %s", ft_strlcat(dst, src, 50), dst);
    return (0);
}