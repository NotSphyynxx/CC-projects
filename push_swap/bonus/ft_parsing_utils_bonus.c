/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parsing_utils_bonus.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilarhrib <ilarhrib@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/06 17:03:31 by ilarhrib          #+#    #+#             */
/*   Updated: 2025/03/06 17:03:49 by ilarhrib         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

void	ft_error(void)
{
	ft_putstr_fd("Error\n", 2);
}

int	ft_is_digit(char c)
{
	return (c >= '0' && c <= '9');
}

int	ft_is_signed(char c)
{
	return (c == '-' || c == '+');
}

size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize)
{
	size_t	srcl;
	size_t	i;

	srcl = ft_strlen(src);
	i = 0;
	if (dstsize > 0 && src)
	{
		while (i < dstsize - 1 && src[i])
		{
			dst[i] = src[i];
			i++;
		}
		dst[i] = '\0';
	}
	return (srcl);
}
