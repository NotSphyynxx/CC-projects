/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilarhrib <ilarhrib@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/24 21:30:26 by ilarhrib          #+#    #+#             */
/*   Updated: 2024/11/10 17:50:22 by ilarhrib         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *hs, const char *n, size_t len)
{
	size_t	i;
	size_t	j;
	size_t	nlen;

	nlen = ft_strlen(n);
	if (!hs && len == 0)
		return (NULL);
	if (nlen == 0)
		return ((char *)hs);
	if (len == 0)
		return (NULL);
	i = 0;
	while (hs[i] != '\0' && i + nlen <= len)
	{
		j = 0;
		while (j < nlen && hs[i + j] == n[j] && (i + j) < len)
			j++;
		if (j == nlen)
			return ((char *)(hs + i));
		i++;
	}
	return (NULL);
}
