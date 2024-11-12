/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilarhrib <ilarhrib@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/23 14:44:43 by ilarhrib          #+#    #+#             */
/*   Updated: 2024/11/10 17:36:14 by ilarhrib         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *d, const void *s, size_t numberOfBytes)
{
	size_t				i;
	unsigned char		*dest;
	const unsigned char	*src;

	if (!d && !s)
		return (NULL);
	if (s == d)
		return (d);
	i = 0;
	dest = (unsigned char *)d;
	src = (const unsigned char *)s;
	while (i < numberOfBytes)
	{
		dest[i] = src[i];
		i++;
	}
	return (d);
}
