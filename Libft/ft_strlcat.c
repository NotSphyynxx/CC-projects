/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilarhrib <ilarhrib@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/23 18:14:40 by ilarhrib          #+#    #+#             */
/*   Updated: 2024/11/10 17:50:31 by ilarhrib         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t	dl;
	size_t	sl;
	size_t	i;

	i = 0;
	sl = 0;
	dl = 0;
	if (!dst && !dstsize)
		return (ft_strlen(src));
	while (dst[dl] && dl < dstsize)
		dl++;
	while (src[sl])
		sl++;
	if (dl >= dstsize)
		return (dstsize + sl);
	while (src[i] && ((dl + i) < dstsize - 1))
	{
		dst[dl + i] = src[i];
		i++;
	}
	dst[dl + i] = '\0';
	return (dl + sl);
}
